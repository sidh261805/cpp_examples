#include<iostream>

template<typename T>
T Max(T x,T y){
    return x>y?x:y;
}

int main(){
    std::cout << Max<int>(3,4) << std::endl;
    std::cout << Max(3.4f,7.6f) << std::endl;
    return 0;
}

