#include<iostream>
#include<type_traits>

template<typename T>
T Divide(T a, T b){
    if(std::is_floating_point<T>::value == false){     // check run time
        std::cout << "use floating point value\n";
    }
    return a/b;
}

template<typename T>
void Check(T&&){
    std::cout << std::boolalpha;
    std::cout << "Is reference : " << std::is_reference<T>::value << std::endl;
    std::cout << "After removing reference : "<< std::is_reference<typename std::remove_reference<T>::type>::value << std::endl;
}

int main(){
    std::cout << std::boolalpha << "Is Integer : " << std::is_integral<int>::value << std::endl;
    std::cout << Divide(5,2) << std::endl;

    Check(5);
    int value{};
    Check(value);
    return 0;
}