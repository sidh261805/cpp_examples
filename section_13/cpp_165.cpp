#include<iostream>
#include<vector>
#include<set>
#include<algorithm>
class Employee{
    std::string m_Name;
    int m_Id;
    std::string m_progLang;
public: 
    Employee(const std::string &n, int id, const std::string &p1):
        m_Name(n),
        m_Id(id),
        m_progLang(p1){}

    const std::string & GetName() const{
        return m_Name;
    }
    int GetId() const{
        return m_Id;
    }
    const std::string & GetProgramming() const {
        return m_progLang;
    }
    // bool operator<(const Employee &e){
    //     return m_Id < e.m_Id;
    // }
};

void Vec(){
    std::vector<Employee> v{
        Employee{"sidd", 101, "C++"},
        Employee{"lala",201,"python"},
        Employee{"Alka",301,"JAva"}
    };
    // std::sort(v.begin(),v.end());
    std::sort(v.begin(),v.end(), [](const auto &e1,const auto &e2){
            return e1.GetName() < e2.GetName();
    });

    for (const auto &e : v){
        std::cout 
                << "Id:" << e.GetId()
                << " | Name:" << e.GetName()
                << " | Programming:" << e.GetProgramming() 
                << std::endl;
    }
}

struct EmpCompare{
    bool operator()(const Employee &e1,const Employee &e2) const{
        return e1.GetId() < e2.GetId();
    }
};

void Set(){
    std::set<Employee,EmpCompare> v{
        Employee{"sidd", 101, "C++"},
        Employee{"lala",201,"python"},
        Employee{"Alka",301,"JAva"}
    };

    for (const auto &e : v){
        std::cout 
                << "Id:" << e.GetId()
                << " | Name:" << e.GetName()
                << " | Programming:" << e.GetProgramming() 
                << std::endl;
    }
}

int main (){
    Vec();
    Set();
    return 0;
}