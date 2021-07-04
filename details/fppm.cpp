/* The following code example is taken from the book
 * "C++ Templates - The Complete Guide"
 * by David Vandevoorde and Nicolai M. Josuttis, Addison-Wesley, 2002
 *
 * (C) Copyright David Vandevoorde and Nicolai M. Josuttis 2002.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
 #include<iostream>
 using namespace std;
template <int N>
class X {
  public:
    typedef int I;
    void f(int m) {
      cout<<"x+"<<m<<endl;
      cout<<N<<endl;
    }
};

template<int N> 
void fppm(void (X<N>::*p)(typename X<N>::I)){
  X<N> ins;
  (ins.*p)(100);
  (ins.*p)(23);
}

int main() 
{
    fppm(&X<33>::f);  // fine: N deduced to be 33
}
