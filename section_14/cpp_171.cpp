#include<iostream>
#include<list>
#include<thread>

std::list<int> g_Data;
const int SIZE = 50000000;

class String{
public:
    String(){
        std::cout << "String()" << std::endl;
    }
    String(const String&){
        std::cout << "const String&" << std::endl;
    }
    String & operator=(const String&){
        std::cout << "operator=(const String&)" << std::endl;
    }
    ~String(){
        std::cout << "~String()" << std::endl;
    }
};

void Download(String &file){ //const String &file
    std::cout<<"[Downloader] Started download" << std::endl;
    for(int i; i<SIZE; ++i){
        g_Data.push_back(i);
    }
    std::cout<<"[Downloader] Finished download" << std::endl;
}

int main(){
    String file;
    std::cout<<"[main] User started an operation" << std::endl;
    std::thread th(Download, std::ref(file));  //cref for const ref argument
    th.detach();

    std::cout << "[main] User started another operation" << std::endl;
    if(th.joinable()){
        th.join();
    }

    std::system("read -p 'Press Enter to continue...' var");
    return 0;
}