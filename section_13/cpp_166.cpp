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
};

struct EmpIds{
    std::vector<int> m_Ids;
    void operator()(const Employee &emp){
        if(emp.GetProgramming() == "C++"){
            m_Ids.push_back(emp.GetId());
        }
    }
};

void Vec(){
    std::vector<Employee> v{
        Employee{"sidd", 101, "C++"},
        Employee{"lala",201,"python"},
        Employee{"Bob",201,"C++"},
        Employee{"Alka",301,"JAva"}
    };
    
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

    int cppCount{};
    cppCount = std::count_if(v.begin(),v.end(),[](const Employee &e){
            return e.GetProgramming() == "C++";
    });
    std::cout << "Count : "<< cppCount << std::endl;

    auto itr = std::find_if(v.begin(),v.end(),[](const auto &e){
        return e.GetProgramming() == "JAva";
    });
    if(itr != v.end()){
        std::cout << "Found : " << itr->GetName() << " is JAVA programmer" << std::endl;
    }

    std::for_each(v.begin(),v.end(),[](const auto &e){
        std::cout << e.GetName() << std::endl;
    });

    auto foundIds = std::for_each(v.begin(),v.end(),EmpIds());  //only possible with function object not with function pointer
    for(auto id : foundIds.m_Ids){
        std::cout << "Id : "<<id << std::endl;
    }

}

struct EmpCompare{
    bool operator()(const Employee &e1,const Employee &e2) const{
        return e1.GetId() < e2.GetId();
    }
};


int main (){
    Vec();
    return 0;
}