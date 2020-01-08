#include <iostream>


template <typename T>
 
 class smart_ptr
 {
 private:
     T *ptr_;

 public:
     smart_ptr();
     ~smart_ptr() { delete ptr_; }

     explicit smart_ptr(T *ptr = nullptr):ptr_(ptr){}

     T *get() const { return ptr_; }
 };
 
  
 



int main()
{
    std::cout << "test" << std::endl;
    return 0;
}