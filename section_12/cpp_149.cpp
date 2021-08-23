#include<iostream>
#include<fstream>

int main(){
    int x{5};
    auto f = [y=x](int args){
        return y + args;
    };
    std::cout << f(5) << std::endl;

    std::ofstream out{"file.txt"};
    auto write = [out = std::move(out)](int x)mutable{
        out << "save the value : "<<x;
    };
    write(4004);   // out cannot be use outside b'coz resources moved

    return 0;
}