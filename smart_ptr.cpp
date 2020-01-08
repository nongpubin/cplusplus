#include <iostream>
#include <string.h>

template <typename T>
class smart_ptr
{
 private:
     T *ptr_;

 public:
     smart_ptr();
     ~smart_ptr() {
         std::cout << "delete ptr_" << std::endl;
         delete ptr_; }
     void log() { std::cout << "name === " << std::endl; }
     explicit smart_ptr(T *ptr = nullptr):ptr_(ptr){}
     T *get() const { return ptr_; }

     T &operator*() const { return *ptr_; }
     T *operator->() const { return ptr_; }
     operator bool() const { return ptr_; }
 };
 
  class test
  {
  private:
  public:
      test(){}
      ~test(){}
  };
  
 
  

int main()
{
    std::cout << "test" << std::endl;

    smart_ptr<char> p(new char[128]);
    strncpy(p.get(), "hello",10);
    std::cout << p.get() << std::endl;
 
    return 0;
}