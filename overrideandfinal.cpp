
#include <algorithm>  
#include <iterator>   
#include <vector>    
#include "output_container.h"
#include <iostream>

#include <fstream>

using namespace std;

class A
{
public:
   // A() { cout << "class A " << endl; }
   // ~A(){};
    virtual void foo() = 0;
    virtual void bar() = 0;
    virtual void foobar() = 0;
};

class B:public A
{
public:
   // B() { cout << "Class B " << endl; }
    //~B(){}
    void foo() { cout << "public B >>>  foo " << endl; } // OK
    void bar() { cout << "public B >>>  bar " << endl; } // OK
    void foobar() { cout << "public B >>>  foobar " << endl; } // OK  如果没有，B仍是纯虚基类
                                                               //void foobar() override;
                                                               //  非虚函数不能  override
};
/*
class C final : public B
{
public:
    void foo() override { cout << "public C >>>  foo " << endl; }// OK
                                                 //void bar() override;
                                                 // final  函数不可  override
};*/
/*
class D : public C
{
    //  错误：final  类不可派生
};
*/


int main()
{
    B testb;
    testb.foo();

   /* C testc;
    testc.foo();
*/
    cout << "override test" << endl;
    return 0;
}