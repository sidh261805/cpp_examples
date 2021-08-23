#include<iostream>
#include<list>
#include<thread>

std::list<int> g_Data;
const int SIZE = 5000000;

void Download(){
    std::cout<<"[Downloader] Started download" << std::endl;
    for(int i; i<SIZE; ++i){
        g_Data.push_back(i);
    }
    std::cout<<"[Downloader] Finished download" << std::endl;
}

int main(){
    std::cout<<"[main] User started an operation" << std::endl;
    std::thread th(Download);
    th.detach();

    std::cout << "[main] User started another operation" << std::endl;
    if(th.joinable()){
        th.join();
    }

    std::system("read -p 'Press Enter to continue...' var");
    return 0;
}