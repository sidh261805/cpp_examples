#include<iostream>
#include<thread>
#include<future>

using namespace std::chrono_literals;

int Process(std::promise<int> &x){
    std::future<int> f = x.get_future();
    try {
        std::cout << "[Task]: Waiting for value "<< std::endl;
        int count = f.get();
        std::cout << "[Task]: resource acquired "<< std::endl;
        int sum {};
        for (int i = 0; i < count; ++i){
            sum += i;
            std::cout << '.'<<std::endl;
            std::this_thread::sleep_for(300ms); //s is literals used from cpp14
        }
        std::cout << "Thread id : " << std::this_thread::get_id() << std::endl;
        return sum;
    } catch (std::runtime_error &e){
        std::cout << "[Task] : Exception: "<<e.what() << std::endl;
    }
    
}

int main(){
    std::promise<int> data;
    std::future<int> result = std::async(std::launch::async,Process,std::ref(data)); 
    std::cout << "main() thrad running ..." << std::endl;
    std::this_thread::sleep_for(1s);
    try{
        throw std::runtime_error("Data not avaliable...");
        data.set_value(10);
        if(result.valid()){
            auto sum = result.get();
            std::cout << sum << std::endl;
    } 
    }catch(std::runtime_error &e) {
        data.set_exception(std::make_exception_ptr(e));
    }
        return 0;
}
    
    