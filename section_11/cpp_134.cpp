#include<iostream>

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
// Explicit specialization
template<>
class PrettyPrinter<char *>{
    char *m_Data;
public:
    PrettyPrinter(char *data): m_Data(data){
    }
    void Print(){
        std::cout << "[ "<< m_Data << " ]"<< std::endl;
    }
    char * GetData(){
        return m_Data;
    }

};

int main(){
    int *m_pInt = new int(4);
    int data = 8;
    float data_f = 4.3f;
    PrettyPrinter<int> p0(m_pInt);
    p0.Print();
    PrettyPrinter<int> p1(&data);
    p1.Print();
    PrettyPrinter<float> p2(&data_f);
    p2.Print();
    char *p{"Hello world"};
    PrettyPrinter<char*> p7(p);
    p7.Print();
    char *pData = p7.GetData(); //return pointer to pointer
    // PrettyPrinter<char> p2(p); //print only H because pointer to string in fun
    // p2.Print();
    // char *pData = p2.GetData(); 
    return 0;
}