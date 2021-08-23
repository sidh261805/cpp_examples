#include<iostream>

template<int T>
int CreateArr(){
    return T;
}

template<typename T>
T Sum(T *pArr, int size){
    T total{};
    for (int i =0 ; i<size; i++){
        total += pArr[i];
    }
    return total;
}

template<typename T, int size>
T rSum(T (&pArr)[size]){
    T total{};
    for (int i =0 ; i<size; i++){
        total += pArr[i];
    }
    return total;
}

int main(){
    const int a{5};
    std::cout << CreateArr<10>()<<std::endl;
    std::cout << CreateArr<a>()<<std::endl; //always except static array and const

    int Arr[] {2,3,6,5};
    std::cout << Sum(Arr,4) <<std::endl; 
    //int (&rArr)[4] = Arr;
    std::cout << rSum(Arr) <<std::endl; 

    return 0;
}