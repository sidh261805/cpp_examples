#include<iostream>

template<typename ...Args>
auto Sum(Args... args){
    return(args + ... + 0);   //binary right fold
}

template<typename ...Args>
auto Sum2(Args... args){
    return( 0 + ... + args);   //binary left fold
}

/*
+ - * / % & ^ | = < > << >> += 
= *= &= ^= |= <<= >>= <= >= && || , .* ->*

&&      - true
||      - false
,       - void()
Other   - ill-formed
*/

template<typename Predicate, typename ...Args>
bool Anyof(Predicate p, Args ...args){
    return(... || p(args));
}

template<typename ...Args,typename Predicate>
bool Allof(Predicate p, Args ...args){
    return(... && p(args));
}

int main(){
    auto value = Sum(1,2,3,4,5);
    std::cout<< "[Sum : " << value << "]"<<std::endl;

    auto value2 = Sum2(1,2,3,4,5);
    std::cout<< "[Sum2 : " << value2 << "]"<<std::endl;

    auto value3 = Sum();  //also possible  (1+(2+(3+(4+(5+0)))))
    auto value4 = Sum2();

    std::cout << std::boolalpha << "Any of : " << Anyof([](int args){ return args % 2 == 0;},1,5,8,7) << std::endl;
    std::cout << std::boolalpha << "Any of : " << Allof([](int args){ return args % 2 == 0;},2,6,8,0) << std::endl;

    return 0;
}