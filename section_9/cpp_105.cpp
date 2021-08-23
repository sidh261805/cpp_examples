#include<iostream>
#include<limits>

int ProcessRecords(int count){
    std::cout << "count" << count << std::endl;
    if (count < 10){
        throw std::out_of_range("Count need to be greater than 10");
    }
    int *p = new int[count];
    delete(p);
    return 0;
}

int main()
{
    try{
        // ProcessRecords(std::numeric_limits<long>::max());
        ProcessRecords(5);
    }
    catch(std::runtime_error &e){
        std::cout << e.what() << std::endl;
    }
    catch(std::out_of_range &e){
        std::cout << e.what() << std::endl;
    }
    catch (std::bad_alloc &e){
        std::cout << e.what() << std::endl;
    }
    catch (std::exception &e){                  // use base class to catch all exceptions
        std::cout << e.what() << std::endl;
    }
    catch(...){                                   // catch exception which not documented & should be the last catch block
        std::cout << "Exception" << std::endl;
    }
    return 0;
}