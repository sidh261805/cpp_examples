#include<iostream>

template<typename T>
void Print(const T &value){
    if constexpr(std::is_pointer_v<T>){
        std::cout << *value << std::endl;
    } else if constexpr (std::is_array_v<T>){
        for(auto x : value){
            std::cout << x << std::endl;
        }
    } else {
        std::cout << value << std::endl;
    }
}

template<typename T>
std::string ToString(T value){  //when pass int value it will not compile else part
    if constexpr (std::is_arithmetic_v<T>){
        return std::to_string(value);
    } else {
        return std::string{value};
    }
}

void CheckMode(){
    if(sizeof(void *) == 4){
        std::cout << "32 - bit "<<std::endl;
    } else if(sizeof(void *) == 8){
        std::cout << "64 - bit "<<std::endl;
    } else {
        std::cout << "unknown mode "<<std::endl;
    }
}

int main(){
    CheckMode();
    int value{10};
    auto s = ToString(value);
    Print(s);

    Print(&value);

    int arr[] = {1,2,3,4,5};
    Print(arr);

}