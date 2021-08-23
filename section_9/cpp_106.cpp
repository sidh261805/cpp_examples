#include<iostream>
#include<memory>
#include<limits>
#include<vector>

class Test{
    public:
    Test(){
        std::cout << "Ctor Test called" << std::endl;
    }
    ~Test(){
        std::cout << "Dtor Test called" << std::endl;
    }
};

int ProcessRecords(int count){
    // Test *p = new Test;      // if error thrown dtor never called in dynamic memory allocation, only stack will unwind
    std::unique_ptr<Test> p(new Test);   // make local object dtor call in stack unwinding
    if (count < 10){
        throw std::out_of_range("Value should be greater than 10");
    }

    // delete(p);
    return 0;
}

int ProcessRecords_a(int count){
    std::cout << "count" << count;
    std::vector<int> p;
    p.reserve(count);
    std::vector<int> pArray;
    pArray.reserve(count);                    //if fail to allocate then throw bad_alloc
    for (int i=0 ; i < count; ++i){
        pArray.push_back(i);
    }

    // int *p = new int[count];                              //use vector instead of dynamic arrays
    // int *pArray = (int*)malloc(count * sizeof(int));
    // if (pArray == nullptr){                                     //fail to allocate then p will never delete cause memory leak
    //     throw std::runtime_error("Failed to allocate memory");
    // }
    // for (int i =0; i < count; ++i){
    //     pArray[i] = i;
    // }
    // free(pArray);
    return 0;
}

int main(){
    try{
        // ProcessRecords(5);
        ProcessRecords_a(std::numeric_limits<long>::max());
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

}