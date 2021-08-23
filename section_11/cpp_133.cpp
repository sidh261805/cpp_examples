#include<iostream>

template<typename T, int size>
class Stack{
    T m_Buffer[size];
    int m_Top{-1};
public:
    Stack() = default;
    Stack(const Stack &obj){
        m_Top = obj.m_Top;
        for (int i =0; i <= m_Top; ++i){
            m_Buffer[i] = obj.m_Buffer[i];
        }
    }

    void push(const T &element){
        m_Buffer[++m_Top]=element;
    }
    void pop();
    int Top() const {
       return m_Buffer[m_Top]; 
    }
    bool IsEmpty(){
        return m_Top == -1;
    }
    static Stack Create();  //short hand notation does not specify template parameter

    
};

template<typename T, int size>
void Stack<T,size>::pop(){
        --m_Top;
};

template<typename T, int size>
Stack<T,size> Stack<T,size>::Create(){
    return Stack<T,size>();
}

int main (){
    Stack<int,4> st = Stack<int,4>::Create();
    // Stack<int,4> st;
    st.push(2);
    st.push(5);
    st.push(6);
    st.push(8);
    auto s2(st);
    while (!s2.IsEmpty())
    {
        std::cout << s2.Top()<< " ";
        s2.pop();
    }
    
}