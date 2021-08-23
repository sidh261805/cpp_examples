#include<iostream>

[[deperecated("Use latest version")]]
int * CreateArray(int size){
    return new int[size];
}

class [[deperecated("do not use this class")]] Test {

};

namespace [[deperecated("Do not use this namespace")]] A{

}

template<typename T>
[[nodiscard]]
T * CreateArray_New(T size){
    return new T[size];
}

class [[nodiscard]] Number{

};

Number GetNumber(int x){
    return Number{};
}

int main(){
    CreateArray(5);
    Test t;
    CreateArray_New<int> (10);
    auto a = CreateArray_New<int> (5);
    GetNumber(4);
    auto num = GetNumber(4);
}