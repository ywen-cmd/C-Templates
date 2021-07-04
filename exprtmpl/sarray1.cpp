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
#include "sarray1.hpp"
#include "sarrayops1.hpp"
#include <iostream>

int main()
{
    // SArray<double> x(1000), y(1000);
    SArray<double> x(4), y(4);
    x[0]=1;
    x[1]=2;
    x[2]=3;
    x[3]=4;    
    y[0]=0;
    y[1]=1;
    y[2]=2;
    y[3]=3;
    //...
    x = 1.2*x + x*y;

    for(int i=0;i<4;i++){
        std::cout<<x[i]<<std::endl;
    }

}
