#include<iostream>

template<typename T>
struct Unamed
{
    T operator()(T x, T y){
        return x+y;
    }
};


// lambda fun is a shortcut for func object
int main(){
    auto sum = [](int x, int y) noexcept (false){
        return x + y;
    };
    auto sum_cpp14 = [](auto x, auto y) noexcept (false){
        return x + y;
    };
    std::cout << typeid(sum).name() << std::endl;
    Unamed<int> n;
    std::cout << n(9,7) << std::endl;
    std::cout << sum(9,7) << std::endl;
    std::cout << sum_cpp14(9.4f,7.4f) << std::endl;
    return 0;
}