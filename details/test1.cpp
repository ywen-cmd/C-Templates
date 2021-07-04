#include<iostream>
using namespace std;

template<typename T>
class B{
    public:
    enum E{e1=6,e2=28,e3=496};
    virtual void zero(E e=e1);  
    virtual void one(E&);
};

template<typename T>
class D:public B<T>{
    public:
    //copy enum
    // enum E{e1=6,e2=28,e3=496};
    // virtual void zero(E e=e1);  
    // virtual void one(E&);
    void f(){
        // typename D<T>::E e;
        // this->zero();
        D<T>::zero();
        // this->one(e);
        // B<T>::zero();
        // B<T>::one(e);
    }
};

template<typename T>
class F:public D<T>{
    public:
    //copy enum
    enum E{e1=6,e2=28,e3=496};
    virtual void zero(E e=e1);  
    virtual void one(E&);
    void f(){
        typename F<T>::E e;
        this->zero();
        this->one(e);
    }
};

int main(){
    // B<int>* pb = new D<int>();
    D<int>* pd = new D<int>();
    // pb->zero();
    pd->f();
    return 0;
}

template<typename T>
void B<T>::zero(E e){
    cout<<"base::zero"<<endl;
}

template<typename T>
void B<T>::one(E& e){
    cout<<"base::one"<<endl;
}

// template<typename T>
// void D<T>::zero(E e){
//     cout<<"D::zero"<<endl;
// }

// template<typename T>
// void D<T>::one(E& e){
//     cout<<"D::one"<<endl;
// }

// template<typename T>
// void F<T>::zero(E e){
//     cout<<"F::zero"<<endl;
// }

// template<typename T>
// void F<T>::one(E& e){
//     cout<<"F::one"<<endl;
// }