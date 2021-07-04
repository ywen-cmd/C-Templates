#include<iostream>
template<typename X>
class Base{
    public:
    int basefield;
    typedef int T;
};

// template<>
// class Base<bool>{
//     public:
//     enum{basefield=42};
// };

template<typename T>
class DD:public Base<T>{
    public:
    void f(){
        this->basefield = 34;
    }
};

void g(DD<bool>& d){
    d.f();
}

int main(){
    DD<bool> d;
    g(d);
    std::cout<<d.basefield<<std::endl;
    return 0;
}