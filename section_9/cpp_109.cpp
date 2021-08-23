#include<iostream>
#include<random>
#include<memory>
#include<vector>

void Test(int x) noexcept(false){
    std::cout << x << std::endl;
    throw x;
}

int sum(int x, int y) noexcept(noexcept(Test(x))){
    Test(x);
    return x+y;
}

class A{
public:
    ~A(){  //by default its true and give compiler warnning if try to throw
        // throw 5;
    }
};

int main(){
    A a;
    std::cout<< std::boolalpha << noexcept(a.~A()) << noexcept(Test(5)) << std::endl;
    try{
        sum(4,6);
    }
    catch (int x) {
        std::cout << x << std::endl; 
    }
}

//All the move operator in class marked with noexcept because if we store object of such class in containers ex.vector 
//then vector move the resource, if not marked noexcept(true)then copy.