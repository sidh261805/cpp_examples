#include<iostream>
#include<list>
//linked list
int main(){
    std::list<int> ls;
    for(int i = 0;i < 10;++i){
        ls.push_back(i * 10);
    }
    auto itr = ls.begin();
    while(itr != ls.end()){
        std::cout << *itr++ << " ";
    }
    ls.insert(itr,800);
    // ls.erase(itr);
    return 0;
}