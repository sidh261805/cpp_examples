#include<iostream>
#include<mutex>
#include<vector>

template<typename T>
class Data {
public:
    Data(const T &t){

    }
};
Data(const char*) -> Data<std::string>;
Data(int) -> Data<long>;

int main(){
    Data d1{5};
    Data d2 = d1;
    auto d3 = new Data{"Hello"};

    Data d4{"Hello"};

    Data d5{9};

    std::pair<int,int> p1{3,5};
    auto p2 = std::make_pair(4,5);

    std::pair p3{4,6};
    std::vector v1{3,4,5,6,7};

    std::mutex m;
    std::lock_guard lck{m};



}
