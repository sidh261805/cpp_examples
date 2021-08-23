#include<iostream>
#include<vector>

template<typename T, int size>
class PrettyPrinter{
    T *m_Data;
public:
    PrettyPrinter(T *data): m_Data(data){
    }
    void Print(){
        std::cout << "columns [ "<< *m_Data << " ]"<< std::endl;
        std::cout << "[ "<< *m_Data << " ]"<< std::endl;
    }
    T * GetData(){
        return m_Data;
    }

};

//Partial Specialization
template<typename T>
class PrettyPrinter<T, 80>{
    T *m_Data;
public:
    PrettyPrinter(T *data): m_Data(data){
    }
    void Print(){
        std::cout << "columns is MAX ]"<< std::endl;
        std::cout << "[ "<< *m_Data << " ]"<< std::endl;
    }
    T * GetData(){
        return m_Data;
    }

};

template<typename T>
class SmartPointer{
    T *m_ptr;
public:
    SmartPointer(T *ptr):m_ptr(ptr){

    }
    T *operator ->(){
        return &m_ptr;
    }
    T & operator *(){
        return *m_ptr;
    }
    ~SmartPointer(){
        delete m_ptr;
    }
};

template<typename T>
class SmartPointer<T[]>{
    T *m_ptr;
public:
    SmartPointer(T *ptr):m_ptr(ptr){

    }
    T & operator[](int index){
        return m_ptr[index];
    }
    ~SmartPointer(){
        delete [] m_ptr;
    }
};


int main(){
    int data = 300;
    PrettyPrinter<int,40> p(&data);
    p.Print();
    PrettyPrinter<int,80> p1(&data);
    p1.Print();

    SmartPointer<int> smrt1{new int(3)};
    std::cout<< *smrt1 << std::endl;

    SmartPointer<int[]> smrt2{new int[10]};
    smrt2[0] = 45;
    std::cout<< smrt2[0] << std::endl;

    return 0;
}