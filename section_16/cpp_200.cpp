#include<iostream>
#include<type_traits>

// _t added in c++14 for type perform transformation
// _v added in c++17 for type return boolean
template<typename T>
T Divide(T a,T b){
    if(std::is_floating_point_v<T> == false){
        std::cout << "Use floating value type only "<< std::endl;
        return 0;
    }
    return a/b;
}

template<typename T>
void Check(T &&){
    std::cout << std::boolalpha;
    std::cout << "Is reference ? " << std::is_reference_v<T> << std::endl;

    std::cout << "After removing : "<< std::is_reference_v<typename std::remove_reference_t<T>> << std::endl;
}

class Number{
    int num;
public:
    Number()=default;
    Number(int x):num{x}{}
};


int main(){
    // static_assert(std::is_default_constructible<Number>::value, "only object with default ctor is deserialized");
    static_assert(std::is_default_constructible_v<Number>, "only object with default ctor is deserialized");
    Divide<int>(5,6);

    Check(5);
    int value{};
    Check(value);
    return 0;
}