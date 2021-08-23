#include<iostream>
#include<list>
#include<thread>
#include<mutex>

std::mutex mt;

std::list<int> g_Data;
const int SIZE = 100000;

void Download1(){
    for(int i; i<SIZE; ++i){
        mt.lock();
        g_Data.push_back(i);
        // if(i == 130000){  //dead lock
        //     return;
        // }
        mt.unlock();
    }
}

void Download2(){
    for(int i; i<SIZE; ++i){
        mt.lock();
        g_Data.push_back(i);
        mt.unlock();
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