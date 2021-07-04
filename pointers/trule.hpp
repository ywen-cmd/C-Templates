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
#ifndef TRULE_HPP
#define TRULE_HPP
#include <iostream>
// template <typename T>
// class Holder;

//alreafy know Holder is a template class
template <typename T>
class Trule {
  private:
    T* ptr;    // objects to which the trule refers (if any)

  public:
    // constructor to ensure that a trule is used only as a return type
    // to transfer holders from callee to caller!
    Trule (Holder<T>& h) {
      //
        std::cout<<"func 1\n";
        ptr = h.get();
        //has a release,not need friend class
        h.release();
    }

    // copy constructor
    Trule (Trule<T> const& t) {
        std::cout<<"func 2\n";
        ptr = t.ptr;
        const_cast<Trule<T>&>(t).ptr = 0;
    }

    // destructor
    ~Trule() { 
        delete ptr; 
    }

  private:
    Trule(Trule<T>&);                // discourage use of lvalue trules
    Trule<T>& operator= (Trule<T>&); // discourage copy assignment
    //declare holder as a friend 
    //friend can steal a dominant
    friend class Holder<T>;
};

#endif // TRULE_HPP
