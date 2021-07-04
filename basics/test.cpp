#include<iostream>
template<char const* name>
class Myclass{
    ;
};

// const char* str = "hello";
// Myclass<str> s;
//run -error
// test.cpp:7:16: error: '"hello"' is not a valid template argument for type 'const char*' because string literals can never be used in this context
//  Myclass<"hello"> s;

constexpr char str[] = "hello";
Myclass<str> x;