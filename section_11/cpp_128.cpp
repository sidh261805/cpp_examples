#include <iostream>
#include"inc/integer.hpp"

class Employee{
    std::string m_Name;
    Integer m_Id;
public:
    Employee(const std::string &name, const Integer &id) :
    m_Name{name},
    m_Id{id} {
        std::cout << "Employee(const std::string &name, const Integer &id)" << std::endl;
    }

    Employee(const std::string &&name, Integer &&id) :
    m_Name{name},
    m_Id{id} {
        std::cout << "Employee(const std::string &&name, const Integer &&id)" << std::endl;
    }
};


int main(){
    std::string name{"Sidd"};
    Employee emp(name, 58);  // both L value invoke copy no diff 
    Employee emp1("test", 57); // invole R-value and move r value for id
    Employee emp2("test2", Integer{57}); // not invole R-value because in this id will be pass in m_ID
    return 0;
}