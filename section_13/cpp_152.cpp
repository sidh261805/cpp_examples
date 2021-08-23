#include<iostream>
#include<array>
#include <algorithm> // for std::sort
int main(){
    std::array<int, 5> arr{ 7, 3, 1, 9, 5 };
    for(int i = 0; i < arr.size(); i++){
        std::cout << " " << arr[i];
    }
    std::cout << std::endl;
    for (auto x : arr){
        std::cout << " " << x ;
    }

    auto it = arr.begin();

    arr.data(); // return  pointer to internal array use in c
    
    std::cout << std::endl;
    std::sort(it, arr.end()); // sort the array forwards
    for(int i = 0; i < arr.size(); i++){
        std::cout << " " << arr[i];
    }
    
}