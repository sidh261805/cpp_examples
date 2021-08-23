#include<iostream>
#include<cstring>

template<typename T>   // Template Instantiation when it called
T Max(T x,T y){
    std::cout << "[Type : " << typeid(T).name() << "]" << " Max value :";
    return x>y?x:y;
}

//Explicit Instantiation
template char Max(char x, char y);

//Explicit specialization
template<> const char* Max<const char*>(const char* x, const char* y){
    return strcmp (x,y)> 0 ? x : y;
}

int main(){
    const char *pB {"B"};
    const char *pA {"A"};
    std::cout << Max(pA,pB) << std::endl;   //argument deduction
    return 0;
}

