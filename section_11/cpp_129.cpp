#include <iostream>
#include"inc/integer.hpp"

class Employee{
    std::string m_Name;
    Integer m_Id;
public:
   template<typename T, typename Z> //If Lvalue pass it deduce to Lvalue rule apply for R value function
    Employee(T &&name, Z &&id) :
    m_Name{name},
    m_Id{std::forward<Z>(id)} {
        std::cout << "Employee(const std::string &&name, const Integer &&id)" << std::endl;
    }
};

template<typename T, typename z>
Employee* CreateEmp(T && a, z &&b){
    return new Employee(a,std::forward<z>(b));
}

int main(){
    Employee emp1("test2", Integer{57}); // not invole R-value because in this id will be pass in m_ID
    Integer val{57};
    Employee emp2("test2", val);

    auto emp3 = CreateEmp("test6", Integer{60});

    return 0;
}