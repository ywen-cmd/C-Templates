#include<iostream>
typedef int Int;

void g(Int);

template <typename T>
void f(T i){
    if(i>0)
        g(-i);
}

void g(Int){
    f<Int>(42);
}

int main(){
    g(1);
    return 0;
}