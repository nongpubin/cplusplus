
#include <stdio.h>
#include <iostream>
#include <unistd.h>

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

int main()
{
    puts("main()");
    //process_shape(circle(), triangle()); 
   // result &&r = process_shape(circle(), triangle());
    result &&r = std::move(process_shape(circle(), triangle()));
    puts("something else");
    
}

