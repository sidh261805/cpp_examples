#include<iostream>


template<typename ...Args>
auto Sum(Args... args){
    return(args + ...);   //uranary right fold
}

template<typename ...Args>
auto Sum2(Args... args){
    return( ... + args);   //uranary left fold
}

int main(){
    auto value = Sum(1,2,3,4,5);  // (1+(2+(3+(4+(5)))))
    std::cout<< "[Sum : " << value << "]"<<std::endl;

    auto value2 = Sum2(1,2,3,4,5);
    std::cout<< "[Sum2 : " << value2 << "]"<<std::endl;

    return 0;
}