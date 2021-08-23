#include<iostream>

class EvaluteOrder{
public:
    EvaluteOrder& First(int){
        std::cout << __func__<<std::endl;
        return *this;
    }
    EvaluteOrder& Second(int){
        std::cout << __func__<<std::endl;
        return *this;
    }
};

int FirstsubExpression(int){
    std::cout << __func__<<std::endl;
    return 0;
}

int SecondsubExpression(int){
    std::cout << __func__<<std::endl;
    return 0;
}

int main(){
    EvaluteOrder eo;
    eo.First(FirstsubExpression(0)).Second(SecondsubExpression(0));
}