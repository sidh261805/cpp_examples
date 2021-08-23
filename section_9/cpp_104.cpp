#include<iostream>
#include<limits>

int ProcessRecords(int count){
    std::cout << "count" << count;
    int *p = new int[count];
    int *pArray = (int*)malloc(count * sizeof(int));
    if (pArray == nullptr){
        throw std::runtime_error("Failed to allocate memory");
    }
    for (int i =0; i < count; ++i){
        pArray[i] = i;
    }
    free(pArray);
    return 0;
}

int main()
{
    try{
        ProcessRecords(std::numeric_limits<long>::max());
    }
    catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    catch (std::bad_alloc &e){
        std::cout << e.what() << std::endl;
    }
    return 0;
}