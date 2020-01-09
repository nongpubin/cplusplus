#include <iostream>
#include <string.h>
#include <unistd.h>

#if 0

template <typename T>
class smart_ptr
{
 private:
     T *ptr_;

 public:
     smart_ptr();
     ~smart_ptr() {
         std::cout << "delete ptr_" << &ptr_ << std::endl;
         delete ptr_; }
     void log() { std::cout << "name === " << std::endl; }
     explicit smart_ptr(T *ptr = nullptr):ptr_(ptr){}
     T *get() const { return ptr_; }

     T &operator*() const { return *ptr_; }
     T *operator->() const { return ptr_; }
     operator bool() const { return ptr_; }

     smart_ptr(const smart_ptr &) = delete;
     smart_ptr &operator=(const smart_ptr &) = delete;
 };
 
 #endif

#if 0
  class test
  {
  private:
  public:
      test(){}
      ~test(){}
  };
  
template <typename T>
class smart_ptr {
  smart_ptr(smart_ptr& other)
  {
    ptr_ = other.release();
  }
  smart_ptr& operator=(smart_ptr& rhs)
  {
    smart_ptr(rhs).swap(*this);
    return *this;
  }

  T* release()
  {
    T* ptr = ptr_;
    ptr_ = nullptr;
    return ptr;
  }

  void swap(smart_ptr& rhs)
  {
    using std::swap;
    swap(ptr_, rhs.ptr_);
  }

  ~smart_ptr()
  {
      std::cout << "delete ptr_" << &ptr_ << std::endl;
      delete ptr_;
  }
};


#endif

enum class shape_type
{
    circle,
    triangle,
    rectangle,
};

class shape
{
private:
public:
    static void shape_out(void) { std::cout << "shape" << std::endl; }
    shape(){}
    ~shape(){}
};

class circle : public shape
{
private:
public:
    void circle_out(void) { std::cout << "circle" << std::endl; }
    circle(){}
    ~circle(){}
};


class triangle : public shape
{
private:
public:
    void triangle_out(void) { std::cout << "triangle" << std::endl; }
    triangle(){}
    ~triangle(){}
};

#if 1
template <typename T>
class  smart_ptr {

private:
    T *ptr_;

public:
    explicit smart_ptr(T *ptr = nullptr) : ptr_(ptr) {}

   /* smart_ptr(smart_ptr &other)
    {
        ptr_ = other.release();
    }*/

    smart_ptr(smart_ptr && other)
    {
        ptr_ = other.release();
    }

    smart_ptr &operator=(smart_ptr rhs)
    {
        rhs.swap(*this);
        return *this;
    }

    T *release()
    {
        T *ptr = ptr_;
        ptr_ = nullptr;
        return ptr;
    }

    void swap(smart_ptr &rhs)
    {
        using std::swap;
        swap(ptr_, rhs.ptr_);
    }

    ~smart_ptr() 
    {
         std::cout << "delete ptr_" << &ptr_ << std::endl;
         delete ptr_;
     }
};

#endif


shape *create_shape(shape_type type)
{
    switch (type)
    {
    case shape_type::circle:
        return new circle();
        break;
    case shape_type::triangle:
        return new triangle();
        break;
    default:
        break;
    }
}

int main()
{
#if 0
    std::cout << "test" << std::endl;
    smart_ptr<char> p(new char[128]);
    strncpy(p.get(), "hello",10);
    std::cout << p.get() << std::endl;
    p.log();

    sleep(1);
    smart_ptr<char> p1(new char[128]);
    strncpy(p1.get(), "hello", 10);
    std::cout << p1.get() << std::endl;
    p1.log();

    smart_ptr<char> p1(p);
    sleep(1);
    p1.log();

#endif


    smart_ptr<shape> ptr1{create_shape(shape_type::circle)};
    //smart_ptr<shape> ptr2{ptr1}; //  编译出错
    smart_ptr<shape> ptr3;
    //ptr3 = ptr1;                            //  编译出错
    ptr3 = std::move(ptr1);                 // OK，可以
    //smart_ptr<shape> ptr4{std::move(ptr3)}; // OK，可以

    return 0;
}