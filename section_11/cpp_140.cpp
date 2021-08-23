#include<iostream>
#include<type_traits>

template<typename T>
T Divide(T a, T b){
    static_assert(std::is_floating_point<T>::value, "Only floating supported");  // check at compile time
    if(std::is_floating_point<T>::value == false){
        std::cout << "use floating point value\n";
    }
    return a/b;
}

int main(){
    std::cout << Divide(5.3,2.3) << std::endl;
    std::cout << Divide(5,2) << std::endl;  // not compile 
    return 0;
}