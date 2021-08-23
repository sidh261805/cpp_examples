#include<iostream>
namespace A{
    namespace B {
        namespace c{

        }
    }
}

namespace A::B::C {
    void lala(){

    }
}

int main(){
    A::B::C::lala();
    using A::B::C::lala;
    using namespace A::B::C;
    lala();
}
