#include<iostream>

auto Sum(){
    return 0;
}

template<typename T, typename... Params>
T Sum(T numb, Params... args){
    return numb + Sum(args...);
}

int main(){
    auto result = Sum(1,2,3,4,5);
    std::cout << "Sum : "<<result<<std::endl;
}