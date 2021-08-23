#include <iostream>

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
};

int main(){
    atexit([](){      // if capture list empty conversion happen to function pointer and it worked
        std::cout <<"Program terminates .. "<< std::endl;
        });

    [](int x){
        x *= 2;
        [](int x){
            std::cout << "x : " << x << std::endl;
        }(x);
    }(5);

    Product p{"Watch",500};
    p.AssignPrice();
    std::cout << "Final Price : "<<p.GetPrice()<<std::endl;
    
    return 0;
}