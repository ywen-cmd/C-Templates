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
#include <cassert> 
#include <iostream>
#include "stdobjpolicy.hpp"
#include "stdarraypolicy.hpp"
#include "simplerefcount.hpp"
#include "countingptr.hpp"
#include <vector>

void test1();
// void test2();

int main()
{
    test1();
    // test2();
}

void test1()
{
    std::cout << "\ntest1():\n";
    CountingPtr<int> p0;
    { 
       CountingPtr<int> p1(new int(42));
       std::cout << "*p1: " << *p1 << std::endl;

       *p1 = 17;
       std::cout << "*p1: " << *p1 << std::endl;

       CountingPtr<int> p2 = p1;
       std::cout << "*p2: " << *p2 << std::endl;

       *p1 = 33;
       std::cout << "*p2: " << *p2 << std::endl;

       p0 = p2;
       std::cout << "*p0: " << *p0 << std::endl;

       ++*p0;
       ++*p1;
       ++*p2;
       std::cout << "*p0: " << *p0 << std::endl;
       std::cout << "*p1: " << *p1 << std::endl;
       std::cout << "*p2: " << *p2 << std::endl;
       std::cout << "==" << (p0 == p1.operator->()) << std::endl;


    //    std::cout << p0.CP::count() << std::endl;
    //    std::cout << p1.CP::count() << std::endl;
    //    std::cout << p2.CP::count() << std::endl;
       //Test DELETE multiple times
    //    int* a = new int(10);
    //    p0 = a;
    //    p1 = a;
    //    std::cout << p0.CP::count() << std::endl;
    //    std::cout << p1.CP::count() << std::endl;
    //    std::cout << (p1.CP::ptr_const()== p0.CP::ptr_const()) << std::endl;

    //    std::cout << p2.CP::count() << std::endl;
    //    std::cout << "check address a:<" << a <<">\n";
    }
    // std::cout << *p0 << std::endl;
    std::cout << "after block: *p0: " << *p0 << std::endl;
    //it will cause multiple delete of same address
    //but it doesn't crack in mingw32
    //it will cause double free error in ubuntu
}

void test2()
{
    std::cout << "\ntest2():\n";
    { CountingPtr<int> p0(new int(42));
       CountingPtr<int> p2 = p0;
    }
    CountingPtr<int> p1(new int(42));
    
    std::cout << "qqq" << std::endl;

    std::vector<CountingPtr<int> > coll;
    std::cout << "qqq" << std::endl;
    coll.push_back(p1);
    std::cout << "qqq" << std::endl;
    coll.push_back(p1);
    std::cout << "qqq" << std::endl;

    std::cout << "qqq" << std::endl;

    ++*p1;
    ++*coll[0];
    std::cout << *coll[1] << std::endl;
}

// test1
// Linux下能报错,MinGW32不报错
// (base) ywen@ywen-virtual-machine:~/code/test_shared_ptr$ g++ -o test countingptrtest.cpp 
// (base) ywen@ywen-virtual-machine:~/code/test_shared_ptr$ ./test 

// test1():
// *p1: 42
// *p1: 17
// *p2: 17
// *p2: 33
// *p0: 33
// *p0: 36
// *p1: 36
// *p2: 36
// 3
// 3
// 3
// 1
// 1
// 0
// 1
// check address a:<0x55947b5142c0>
// D:counter<0x55947b5142a0>
// D:object<0x55947b514280>
// D:counter<0x55947b514300>
// D:object<0x55947b5142c0>
// 2068923136
// after block: *p0: 2068923136
// D:counter<0x55947b5142e0>
// D:object<0x55947b5142c0>
// free(): double free detected in tcache 2
// 已放弃