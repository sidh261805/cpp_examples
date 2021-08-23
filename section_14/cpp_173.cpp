#include<iostream>
#include<list>
#include<thread>
#include<mutex>

std::mutex mt;

std::list<int> g_Data;
const int SIZE = 200000;

void Download1(){
    for(int i; i<SIZE; ++i){
        std::lock_guard<std::mutex> mtg(mt);
        g_Data.push_back(i);
    }
}

void Download2(){
    for(int i; i<SIZE; ++i){
        std::lock_guard<std::mutex> mtg(mt);
        g_Data.push_back(i);
    }
}

int main(){
    std::thread t1(Download1);
    std::thread t2(Download2);
    t1.join();
    t2.join();
    std::cout << g_Data.size() << std::endl;
    return 0;
}