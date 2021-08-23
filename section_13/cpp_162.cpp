#include<iostream>
#include<string>
#include<unordered_set>

class Employee{
    int m_Id;
    std::string m_Name;
public:
    Employee (std::string name, int Id):m_Id(Id),m_Name(name){}

    const std::string &GetName() const {
        return m_Name;
    }

    int GetId()const{
        return m_Id;
    }
};

struct EmployeeHash {
    size_t operator()(const Employee & emp) const{
        auto s1 = std::hash<std::string>{}(emp.GetName());
        auto s2 = std::hash<int>{}(emp.GetId());
        return s1 ^ s2;
    }
};

struct EmpEquality {
    bool operator()(const Employee &e1, const Employee &e2)const{
        return e1.GetId() == e2.GetId();
    }
};

void CalculateHash(){
    std::hash<std::string> h;
    std::cout << "hash : "<< h("Hello") << std::endl;

    std::unordered_set<Employee,EmployeeHash,EmpEquality> e;
    e.insert(Employee("sidd",995));
    e.insert(Employee("lala",125));
    e.insert(Employee("ironman",587));

    for(const auto x : e){
        std::cout << "Bucket number "<< e.bucket(x) << " : " << x.GetId() << " " << x.GetName() << std::endl;
    }
}

int main(){
    CalculateHash();
    return 0;
}