#include<iostream>

template<typename T>   // Template Instantiation when it called
T Max(T x,T y){
    std::cout << "[Type : " << typeid(T).name() << "]" << " Max value :";
    return x>y?x:y;
}

int main(){
    std::cout << Max<float>(3,4.1) << std::endl;   //argument deduction
    std::cout << Max(static_cast<float>(3),8.4f) << std::endl;
    std::cout << Max(3.4f,7.6f) << std::endl;
    int (*pFun)(int,int) = Max;  //invoke template by function pointer
    return 0;
}

