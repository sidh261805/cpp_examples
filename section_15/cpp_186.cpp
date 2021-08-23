#include<iostream>
#include<fstream>
void Alloc(){
    int *p = (int*)malloc(sizeof(int));
    if(p != nullptr){
        *p = 100;
        std::cout << "[Value : old if :" << *p << "]" << std::endl;
        free(p);
    }
    //if(initialization; condition){}

    if(int *p = (int*)malloc(sizeof(int)); p!= nullptr){
        *p = 100;
        std::cout << "[Value : new if :" << *p << "]" << std::endl;
        free(p);
    } else {
        //here p will be nullptr
    }
}

void Write(std::string data){
    std::ofstream out{"file.txt"};
    if(out){
        if(!data.empty()){
            std::cout << data;
        } else {
            std::cout << "no data to write" << std::endl;
        }
    }
    if(std::ofstream out{"file.txt"};!data.empty()){
            std::cout << data;
    } else {
        std::cout << "no data to write" << std::endl;
    }
}

void SwitchCase(int errorcode){
    std::ofstream out{"file.txt"};
    switch(errorcode){
        case 0:
            out << "Invalid param";
            break;
        case 1:
            out << "Could not read from file";
            break;
    }
    
    switch(std::ofstream out{"file.txt"};errorcode){
        case 0:
            out << "Invalid param";
            break;
        case 1:
            out << "Could not read from file";
            break;
    }
}

int main(){
    Alloc();
}