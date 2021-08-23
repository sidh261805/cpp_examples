#include<iostream>
#include<vector>
#include<list>

//typedef is not templatise use and use type alias for this

const char * GetErrorMeaasge(int errorNo){
    return "Empty";
}

void ShowError(const char *(*PFN)(int)){
    std::cout << PFN;
}

// typedef const char *(*PFN)(int);
using PFN = const char *(*)(int);
void ShowError_1(PFN pfn){
    std::cout << pfn;
}

// template<typename T>
typedef std::vector<std::list<std::string>> Names;

template<typename T>
using Names1 = std::vector<std::list<T>>;

int main(){
   PFN pfn = GetErrorMeaasge;
   ShowError(pfn);
   ShowError_1(pfn);

   Names name;
   Names1<std::string> name1;
   Names1<Names1<std::string>> name2;
    return 0;
}