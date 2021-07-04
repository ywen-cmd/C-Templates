#include<iostream>
using namespace std;

class DemoClass
{
public:
    DemoClass() : m_a(100) { }
 
    // ....
 
public:
    int m_a;
};
 
 
int DemoClass::*ipm = 0; // ipm是一个指针，指向类DemoClass的一个int成员，该处初始化为0
 
 
int main()
{
    DemoClass aC;
 
    cout << &(aC.m_a) << endl;  // 0x22fecc
 
    //ipm = &(aC.m_a); // 编译错误: cannot convert 'int*' to 'int DemoClass::*' in assignment
 
    ipm = &DemoClass::m_a; // ok
    cout << ipm << endl; // 1 opps! 注意哦！这里输出1，即offset == 1
 
    cout << aC.m_a << endl;  // 100
    aC.*ipm = 99; //  这是神马用法？ 很惊奇！！ O(∩_∩)O哈哈~
    cout << aC.m_a << endl;  // 99
 
    DemoClass *pC = &aC;
    cout << pC->m_a << endl;  // 99
    pC->*ipm = 1001; //  这又是神马用法？ 其实等价于 aC.*ipm = 99; O(∩_∩)O哈哈~
    cout << aC.m_a << " | " << pC->m_a << " | " << pC->*ipm << endl;  // 1001 | 1001 | 1001

    return 0;
}