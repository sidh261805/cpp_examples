#include<iostream>
#include<deque>

int main(){
    std::deque<int> deq;
    for(int i = 0; i < 5; ++i){
        deq.push_back(i*10);
    }
    for(int i = 0; i < 5; ++i){
        deq.push_front(i*30);
    }
    deq[0] = 500;
    auto itr = deq.begin();
    while(itr!= deq.end()){
        std::cout << *itr++ << " ";
    }
    deq.insert(deq.begin(),200);
    deq.erase(deq.end()-5);
    deq.pop_back();
    deq.pop_front();
    auto itr1 = deq.begin();
    std::cout << std::endl;
    while(itr1!= deq.end()){
        std::cout << *itr1++ << " ";
    }
    return 0;
}