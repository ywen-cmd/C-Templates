#include "accum0.hpp"
#include <iostream>
using namespace std;
int main(){
    int num[]={1,2,3,4,5};
    auto sum = ::accum(&num[0],&num[5]);
    cout<<sum<<endl;
    return 0;
}