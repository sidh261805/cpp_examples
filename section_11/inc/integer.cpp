#include "integer.hpp"

Integer::Integer(){
    std::cout << "Integer()" << std::endl;
    m_pInt = new int{0};
}

Integer::Integer(int value){
    std::cout << "Integer(int)" << std::endl;
    m_pInt = new int{value};
}

Integer::Integer(const Integer &obj){
    std::cout << "Integer(const Integer&)" << std::endl;
    m_pInt = new int{*obj.m_pInt};
}

Integer::Integer(Integer &&obj){
    std::cout << "Integer(const Integer&&)" << std::endl;
    m_pInt = obj.m_pInt;
    obj.m_pInt = nullptr;
}

int Integer::Getvalue()const{
    std::cout << "value :" << *m_pInt << std::endl;
    return *m_pInt;
}

void Integer::Setvalue(int value){
    *m_pInt = value;
}

std::ostream & operator<<(std::ostream& stream, const Integer& integer) {
    stream << *integer.m_pInt;
    return stream;
}

Integer::~Integer(){
    std::cout << "~Integer()" << std::endl;
}