#include<iostream>
#include<vector>

template<typename T>
class PrettyPrinter{
    T *m_Data;
public:
    PrettyPrinter(T *data): m_Data(data){
    }
    void Print(){
        std::cout << "[ "<< *m_Data << " ]"<< std::endl;
    }
    T * GetData(){
        return m_Data;
    }

};

// explicit specialization on class
// template<>
// class PrettyPrinter<std::vector<int>>{
//     std::vector<int> *m_Data;
// public:
//     PrettyPrinter(std::vector<int> *data): m_Data(data){

//     }
//     void Print(){
//         for(const auto &x : *m_Data){
//             std::cout << "[ "<< x << " ]"<< std::endl;
//         }
//     }
//     std::vector<int> * GetData(){
//         return m_Data;
//     }
// };


//member function template
template<>
void PrettyPrinter<std::vector<int>>::Print(){
    for(const auto &x : *m_Data){
        std::cout << "[ "<< x << " ]"<< std::endl;
    }
}

int main(){
    std::vector<int> v{3,5,7,9,1};
    PrettyPrinter<std::vector<int>> pv(&v);
    pv.Print();
}