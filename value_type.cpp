
#include <stdio.h>
#include <iostream>
#include <unistd.h>

using namespace std;

class shape
{
public:
    virtual ~shape() {}
};

class circle : public shape
{
public:
    circle() { puts("circle()"); }
    ~circle() { puts("~circle()"); }
};

class triangle : public shape
{
public:
    triangle() { puts("triangle()"); }
    ~triangle() { puts("~triangle()"); }
};

class result
{
public:
    result() { puts("result()"); }
    ~result() { puts("~result()"); }
};

result process_shape(const shape &shape1,const shape &shape2)
{
    puts("process_shape()");
    return result();
}

class Obj {
public:
  Obj()
  {
    cout << "Obj()" << endl;
  }
  Obj(const Obj&)
  {
    cout << "Obj(const Obj&)"
       << endl;
  }
  Obj(Obj&&)
  {
    cout << "Obj(Obj&&)" << endl;
  }
};

Obj simple()
{
  Obj obj;
  //  简单返回对象；一般有  NRVO
  return obj;
}

Obj simple_with_move()
{
  Obj obj;
  // move  会禁止  NRVO
  return std::move(obj);
}

Obj complicated(int n)
{
  Obj obj1;
  Obj obj2;
  //  有分支，一般无  NRVO
  if (n % 2 == 0) {
    return obj1;
  } else {
    return obj2;
  }
}

/*
template <typename T>
void bar(T&& s)
{
  foo(std::forward<T>(s));
}*/


void foo(const shape&)
{
  puts("foo(const shape&)");
}

void foo(shape&&)
{
  puts("foo(shape&&)");
}

void bar(const shape& s)
{
  puts("bar(const shape&)");
  foo(s);   //使用左值引用
  //foo(std::move(s));  //右值引用
  //foo(static_cast<shape&&>(s));
}

void bar(shape&& s)
{
  puts("bar(shape&&)");
  foo(std::move(s));
}

 
int main()
{
  /*cout << "*** 1 ***" << endl;
  auto obj1 = simple();
  cout << "*** 2 ***" << endl;
  auto obj2 = simple_with_move();
  cout << "*** 3 ***" << endl;
  auto obj3 = complicated(42);*/
  //bar(circle());
  
  circle temp;
  bar(temp);
  bar(circle());
}

int main1()
{
    puts("main()");
    //process_shape(circle(), triangle()); 
   // result &&r = process_shape(circle(), triangle());
    result &&r = std::move(process_shape(circle(), triangle()));
    puts("something else");
    
    result ne = r;
}

