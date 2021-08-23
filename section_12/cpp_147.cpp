#include <iostream>

template<typename T,int size, typename Callback>
void Foreach(T(&arr)[size],Callback operation){
   for(int i=0; i<size; ++i){
       operation(arr[i]);
   }
}

int main(){
    int ar[]{9,5,7,1,8,3};
    for (auto x: ar){
        std::cout<< x<<" ";
    }
    std::cout << std::endl;

    int sum;

    Foreach(ar,[=,&sum](auto x){ // take variable declare before it
        sum += x;
    });

    std::cout << "Sum : " << sum << std::endl;

    
    return 0;
}