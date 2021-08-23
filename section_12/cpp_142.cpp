#include <iostream>

using Comparator = bool(*)(int,int);

template<typename T,int size>
void Shorting(T(&arr)[size],Comparator com){
    for(int i=0; i<size-1; ++i){
        for(int j=0; j<size-1; ++j){
            if(com(arr[j],arr[j+1])){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }    
}

//fun pointer point global fun and it has no state and never be inline

bool comp_greater(int x, int y){
    return x>y;
}

bool comp_lesser(int x, int y){
    return x<y;
}


int main(){
    int ar[]{9,5,7,1,8,3};
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;

    Shorting(ar, comp_greater);
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;

    Shorting(ar, comp_lesser);
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;

    return 0;
}