#include<iostream>
#include<map>
#include<functional>
#include<string>
//implemented binary tree store pair object 
//modify value not key

void Map(){
    std::map<int,std::string> m{
        {1,"superman"},
        {2,"batman"},
        {3,"ironman"}
    };
    m.insert(std::pair<int,std::string>(8,"Aquaman"));
    m.insert(std::make_pair(6,"wonder woman"));

    m[0] = "Siddharth";

    m[1] = "Auto";
    m.erase(6);

    auto itr = m.begin();
    for (const auto & x : m){
        std::cout << x.first << " : " << x.second << std::endl;
    }

    itr = m.find(1);
    if(itr != m.end()){
        std::cout << " Element found "<< itr->second <<  std::endl;
    } else {
        std::cout << "Not found "<< std::endl;
    }

    std::cout << " Element m[3] "<< m[3] <<  std::endl;  // don use if not present it will create one with empty string
    
}

void MultiMap(){
    std::multimap<int,std::string> mm{
        {1,"superman"},
        {2,"batman"},
        {3,"ironman"}
    };
    mm.insert(std::pair<int,std::string>(8,"Aquaman"));
    mm.insert(std::make_pair(6,"wonder woman"));
    mm.insert(std::make_pair(6,"sidd"));
    mm.insert(std::make_pair(6,"lala"));

    // mm[0] = "Siddharth"; multimap subscript operator is not overloaded

    

    auto found = mm.equal_range(6);
    while(found.first != found.second){
        std::cout << found.first->first << " : " << found.first->second << std::endl;
        found.first++;
    }

    mm.erase(6);

    auto itr = mm.begin();
    for (const auto & x : mm){
        std::cout << x.first << " : " << x.second << std::endl;
    }

    itr = mm.find(1);
    if(itr != mm.end()){
        std::cout << " Element found "<< itr->second <<  std::endl;
    } else {
        std::cout << "Not found "<< std::endl;
    }

    
}

int main(){
    Map();
    MultiMap();
    return 0;
}