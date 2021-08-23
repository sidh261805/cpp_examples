#include<iostream>
#include<random>
#include<memory>

int ProcessRecords(int count){
    std::default_random_engine eng;
    std::bernoulli_distribution dist;
    int errors{};
    for (int i = 0 ; i < count; ++i){
        try {
            std::cout << "Processing record  : " << i << std::endl;
            if (!dist(eng)){
                ++errors;
                throw std::runtime_error("Could not process records");
            }
        }
        catch (std::runtime_error &ex) {
            std::cout << "[ERROR " << ex.what() << "]" << std::endl;
            if (errors > 4){
                std::runtime_error err("Too many operations");
                ex = err;
                throw;
            }
        }
    }
    return 0;
}

int main(){
    try{
        ProcessRecords(15);
    }
    catch (std::runtime_error &e) {
        std::cout << e.what() << std::endl; //print from L20 read by reference
    }

}