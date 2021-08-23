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

int main(){
    int value{10};
    Print(value);

    Print(&value);

    int arr[] = {1,2,3,4,5};
    Print(arr);

}