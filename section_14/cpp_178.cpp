#include<iostream>
#include<thread>
#include<future>

using namespace std::chrono_literals;

int Process(int x){
    int sum {};
    for (int i = 0; i < x; ++i){
        sum += i;
        std::cout << '.'<<std::endl;
        std::this_thread::sleep_for(300ms); //s is literals used from cpp14
    }
    std::cout << "Thread id : " << std::this_thread::get_id() << std::endl;
    return sum;
}

int main(){
    std::future<int> result = std::async(std::launch::async,Process,10); 
    std::this_thread::sleep_for(1s);
    std::cout << "main() thrad running ..." << std::endl;
    if(result.valid()){
        auto timepoint = std::chrono::system_clock::now();
        timepoint += 1s;
        // auto status = result.wait_for(1s);
        auto status = result.wait_until(timepoint);
        switch (status)
        {
        case std::future_status::deferred:
            std::cout << " Task is synchronous\n"<<std::endl;
            break;
        case std::future_status::ready:
            std::cout << " Task is ready\n"<<std::endl;
            break;
        case std::future_status::timeout:
            std::cout << " Task is processing\n"<<std::endl;
            break;
        }
        auto sum = result.get();
        std::cout << sum << std::endl;
    }
    return 0;
}