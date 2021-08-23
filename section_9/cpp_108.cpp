#include<iostream>
#include<random>
#include<memory>
#include<vector>
#include<string>

class A{
public:
    A(){std::cout << "Ctor of A called" << std::endl;}
    ~A(){std::cout << "Dtor of A called" << std::endl;}
};

class B{
public:
    B(){std::cout << "Ctor of B called" << std::endl;}
    ~B(){std::cout << "Dtor of B called" << std::endl;}
};

class Test{
    std::unique_ptr<A> pA{};               //A *pA{};
    B b{};
    std::unique_ptr<int> pInt{};           //pInt{}; int *pInt{};
    std::string pStr{};                    //char *pStr{};
    std::vector<int> pArr{};               //pArr{}; int *pArr{};
public:
    Test(){
        std::cout << "Ctor of Test called" << std::endl;
        pA.reset(new A); //pA = new A;
        throw std::runtime_error("Failed to allocate memory");
        // pInt = new int;
        // pStr = new char[100];
        // pArr = new int[100];
        }
    ~Test(){
        std::cout << "Dtor of Test called" << std::endl;  // never use the program will Abort, If uses then catch inside
        // delete pA;
        // delete pInt;
        // delete[] pStr;
        // delete[] pArr;
        }
};

int main(){
    try{
        Test t;
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl; 
    }

}