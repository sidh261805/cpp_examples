#include <iostream>


template<typename T,int size, typename Comparator>
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

struct com{ // pollute global namespace
    bool operator()(int x, int y){
        return x>y;
    }
};


int main(){
    com comp2;

    int ar[]{9,5,7,1,8,3};
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;

    Shorting(ar, comp2);
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;


    return 0;
}