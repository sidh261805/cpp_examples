#include<iostream>
class Number{
public:
    Number(int value){
        std::cout << "Parameterized ctor" << std::endl;
    }
    Number(const Number &value){
        std::cout << "Copy const" <<std::endl;
    }
    Number (Number &&value){
        std::cout << "Move ctor" << std::endl;
    }
};

void Foo(Number n){

}

Number Create(){
    // Number n{0};  // named value optimization
    // return n;

    return Number{0}; // return temp object  , return value optimiztion
}

int main (){
    Number n1 = Number{3};
    Foo(Number{2});
    auto n2 = Create();
}

//copy Elision 