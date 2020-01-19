#include <iostream>
#include <unistd.h>



class matrix {
public:
  //  普通构造
  matrix(size_t rows, size_t cols);
  //  半正则要求的构造
  matrix();
  matrix(const matrix&);
  matrix(matrix&&);
  //  半正则要求的赋值
  matrix& operator=(const matrix&);
  matrix& operator=(matrix&&);

};


#include <iostream>

using namespace std;

// Can copy and move
class A {
public:
  A() { cout << "Create A\n"; }
  ~A() { cout << "Destroy A\n"; }
  A(const A&) { cout << "Copy A\n"; }
  A(A&&) { cout << "Move A\n"; }
  //A(const A&) = delete;
};

A getA_unnamed()
{
    return A();
}

int main()
{
  auto a = getA_unnamed();
  A al=a;
}
