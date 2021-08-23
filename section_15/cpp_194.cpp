#include<iostream>
class Number{
public:
    Number(int value){
        std::cout << "Parameterized ctor" << std::endl;
    }
    // Number(const Number &value){
    //     std::cout << "Copy const" <<std::endl;                                         @imp cpp14 need move & copy ctor because copy elision is not mandatory
    // }
    // Number(Number &&value){
    //     std::cout << "Move ctor" << std::endl;
    // }
    Number(const Number &value) = delete;                                                //@cpp:17 not require ctor 
    Number( Number &&value) = delete;
};

void Foo(Number n){

}

Number Create(){
    // Number n{0};  // named value optimization
    // return n;

    return Number{0}; // return temp object  , return value optimiztion
}

template<typename T, typename... Args>
T CreateNew(Args&&... args){
    return T{args...};
}

int main (){
    Number n1 = Number{3};
    Foo(Number{2});
    auto n2 = Create();

    auto n3 = CreateNew<Number>(4);  //return object to copy in n3s
}

//copy Elision 
// func return by value
// return have temp value
// pass by value                   usefull when object is expensive to copy
