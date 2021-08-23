#include <iostream>
#include"inc/integer.hpp"

// template<typename T>
// void Print(std::initializer_list<T> args){
//     for (const auto &x : args){
//         std::cout << x << " ";
//     }
// }

void Print(){
    std::cout << std::endl;
}

//Template parameter pack
template<typename T, typename... Params>
void Print(T &&a,Params&&... args){
    std::cout << a;
    if (sizeof...(args) != 0){
        std::cout << ",";
    }
    // Print(args...);
    Print(std::forward<Params>(args)...);
}

int main(){
   std::initializer_list<int> list{1,2,3,4};
//    Print(list);
    // Print(1,2,3,"4");
    Integer val{1};
    Print(1,val, Integer{3});

    return 0;
}