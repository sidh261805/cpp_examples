#include<iostream>
#include<map>

struct Person{
    std::string name;
    int age;
    Person()=default;
    Person(const std::string &nm, int ag):name(nm),age(ag){}
};

struct S1{
    int arr1[10];
    char ch1[256];
};

int main(){
    Person p{"sidd",27};
    // auto name = p.name;

    const auto &[name, age]=p;
    std::cout << name << age <<std::endl;

    // age = 28;
    // std::cout << name << age <<std::endl;

    std::pair<int,int> p4{3,4};

    std::map<int ,std::string> errorInfo{ {1,"not avaliable"},{2,"port is in use"}};
    for(auto err: errorInfo){
        std::cout << err.first << ":" << err.second << std::endl;
    }

    for(auto [key,value] : errorInfo){
        std::cout << key << " : " << value << std::endl;
    }

    int arr[] = {1,2,3};
    auto [a,b,c] = arr;
    auto arr2 = arr; //decay as pointer

    S1 s;
    auto [s1,s2] = s; //s1 and s2 is both array not decay to pointer

}