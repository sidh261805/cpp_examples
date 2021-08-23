#include<iostream>
#include<list>
#include<thread>
#include<mutex>

void Process(){
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "Thread id : " << std::this_thread::get_id() << std::endl;
}

int main(){
    std::thread t1(Process);
    auto id = t1.get_id();
    t1.native_handle();
    std::cout << "[Thread id :"<<id <<" and thread type : " << t1.native_handle() << " Cores: "<<std::thread::hardware_concurrency()<< std::endl;
    t1.join();
    return 0;
}