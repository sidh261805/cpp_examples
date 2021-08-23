

//removed feature from cpp17 it is from cpp98
// cpp11 -> warning: dynamic exception specifications are deprecated in C++11 [-Wdeprecated]
// void Foo() throw(int,float){

// }

void Foo() noexcept {  //cpp 11,14 noexcept was not part of function type

}

void Bar() {

}

int main(){
    void(*p)()noexcept; // cpp 11 no error but in cpp17
    void(*y)();
    // p = Bar;
    // p();
    y = Foo;
    y();

}