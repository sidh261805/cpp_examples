#include<iostream>
#include <functional>
#include<set> // implemented as binary tree

void set(){
    std::set<int, std::greater<int>> s{9,3,8,6,1};
    s.insert(0);
    
    auto itr = s.begin();
    while(itr != s.end()){
        std::cout<< *itr++ << " ";
    }
    std::cout << std::endl;
    s.erase(6); // value is it's self a key

    itr = s.find(1);
    if(itr != s.end()){
        std::cout << " Element found "<< std::endl;
    } else {
        std::cout << "Not found "<< std::endl;
    }
}

void Multiset(){
    std::multiset<int, std::greater<int>> s{9,3,8,6,1,9,3,0};  // same type multiple value allow 
    s.insert(0);
    
    auto itr = s.begin();
    while(itr != s.end()){
        std::cout<< *itr++ << " ";
    }
    std::cout << std::endl;
    s.erase(6); // value is it's self a key

    itr = s.find(1);
    if(itr != s.end()){
        std::cout << " Element found "<< std::endl;
    } else {
        std::cout << "Not found "<< std::endl;
    }

    auto found = s.equal_range(9);
    while(found.first != found.second){
        std::cout << *found.first++ << std::endl;
    }

}

int main(){
    set();
    Multiset();
}