#include<iostream>
#include<thread>
#include<future>

using namespace std::chrono_literals;

void Process(){
    for (int i = 0; i < 10; ++i){
        std::cout << '.';
        std::this_thread::sleep_for(1s); //s is literals used from cpp14
    }
    std::cout << "Thread id : " << std::this_thread::get_id() << std::endl;
}

int main(){
    std::future<void> result = std::async(std::launch::async,Process); // to always sure create seperate thread
    std::cout << "main() thrad running ..." << std::endl;
    result.get();
    return 0;
}