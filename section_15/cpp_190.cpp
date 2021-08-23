#include <iostream>
#include <sstream>

template<typename T,int size, typename Callback>
void Foreach(T(&arr)[size],Callback operation){
   for(int i=0; i<size; ++i){
       operation(arr[i]);
   }
}

class Product{
    std::string name;
    float price;
public:
    Product(const std::string &n, float p):name(n),price(p){
    }
    void AssignPrice(){
        float taxes[]{12,5,5};
        float baseprice{price};
        Foreach(taxes,[baseprice,this](float tax){ // take variable declare before it
            float taxprice = baseprice * tax/100;
            price += taxprice;
        });
    }
    float GetPrice()const{
        return price;
    }

    auto GetDescription(){
        return [*this](const std::string &header){  //object copy by value pass * then it will be avaliable after free dynamic mem
            std::ostringstream ost;
            ost << header << std::endl;
            ost << "name : " << name << std::endl;
            ost << "price : " << price << std::endl;
            return ost.str();
        };
    }
};

int main(){
    // Product p{"Watch",500};
    // p.AssignPrice();
    // std::cout << "Final Price : "<<p.GetPrice()<<std::endl;
    Product *p = new Product{"Watch",500};
    auto desc = p->GetDescription();
    delete p;
    std::cout << desc("*************");

    auto f = [](int x,int y){
        return x+y;
    };
    constexpr auto sum = f(6,2);  //compute at compile time
    sum1 = f(6,2); //sum computed at runtime
    printf("%d",sum);

    
    return 0;
}