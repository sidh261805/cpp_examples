#include<iostream>

// lambda fun is a shortcut for func object
int main(){
    [](){
        std::cout << "hello lambda" << std::endl;
    }();
    auto fn = [](){
        std::cout << "hello lambda again" << std::endl;
    };
    fn();
    return 0;
}