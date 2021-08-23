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

template<typename T,int size, typename Callback>
void Foreach(T(&arr)[size],Callback operation){
   for(int i=0; i<size; ++i){
       operation(arr[i]);
   }
}

template<typename T>
struct Unamed
{
    int offset;
    Unamed(int off):offset(off){}
    void operator()(T &x)const{   //<-- because const offset will not modify in lambda use mutable keyword to remove const
        x += offset;
       // ++offset;
    }
};

int main(){
    int ar[]{9,5,7,1,8,3};
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;

    Shorting(ar, [](auto x, auto y){
        return x>y;
    });
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;

    auto fn = [](auto x){
        std::cout<< x << " ";
    };
    Foreach(ar,fn);

    int offset = 5;
    auto fn1 = [offset](auto &x){
        x += offset;
    };
    Foreach(ar,fn1);

    std::cout << std::endl;

    Foreach(ar,[](auto x){
        std::cout<< x << " ";
    });

    // Unamed<int> n(3);
    // int x = 5;
    // n(x);

    auto fn2 = [offset](auto &x)mutable{
        x += offset;
        offset++;
    };
    Foreach(ar,fn2);

    std::cout << std::endl;

    Foreach(ar,[](auto x){
        std::cout<< x << " ";
    });

    return 0;
}