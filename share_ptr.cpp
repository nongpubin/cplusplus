#include <iostream>
#include <string.h>
#include <unistd.h>
/*
template <typename U>
smart_ptr(smart_ptr<U>&& other)
{
    ptr_ = other.release();
}*/

using namespace std;

class share_count
{
public:
    share_count():count_(1){}
    ~share_count(){}

    void add_count()
    {
        ++count_;
    }

    long reduce_count()
    {
        return --count_;
    }

    long get_count() const
    {
        return count_;
    }

private:
    long count_;
};



template <typename T>
class smart_ptr
{

public:
    explicit smart_ptr(T* ptr = nullptr):ptr_(ptr)
    {
        
        if(ptr) {
            share_count_ = new share_count();
        }
    }

    template <typename U>
    friend class smart_ptr;

    smart_ptr(const smart_ptr& other)
    {
        ptr_ = other.ptr_;
        if(ptr_) {
            other.share_count_->add_count();
            share_count_ = other.share_count_;
        }
    }

    template <typename U>
    smart_ptr(const smart_ptr<U> &other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            other.share_count_->add_count();
            share_count_ = other.share_count_;
        }
    }

    template <typename U>
    smart_ptr(smart_ptr<U> &&other)
    {
        ptr_ = other.ptr_;
        if (ptr_) {
            share_count_ = other.share_count_;
            other.ptr_ = nullptr;
        }
    }

    long use_count() const {
        if (ptr_) {
            return share_count_->get_count();
        } else {
            return 0;
        }
    }

    T &operator*() const noexcept { return *ptr_; }
    T *operator->() const noexcept { return ptr_; }
    operator bool() const noexcept { return ptr_; }

    ~smart_ptr()
    {
        if(ptr_ && !share_count_->reduce_count()) {
            delete ptr_;
            delete share_count_;
        }
    }

private:
    T *ptr_;
    share_count *share_count_;
};

class shape
{
public:
    virtual ~shape() {}
};

class circle : public shape
{
public:
    ~circle() { puts("~circle()"); }
    void circle_log() { cout << ">>>>>>>>>>   circle log out  <<<<<<<<<<<    " << endl; }
};


int main()
{
    smart_ptr<circle> ptr1(new circle());
    cout << "ptr1 count =  " << ptr1.use_count() << endl;
    smart_ptr<shape> ptr2;
    cout << "ptr2 count =  " << ptr2.use_count() << endl;
    smart_ptr<shape> ptr3;
    cout << "ptr3 count =  " << ptr3.use_count() << endl;

    ptr2 = ptr1;
    cout << "ptr2 count =  " << ptr2.use_count() << endl;

    ptr3 = ptr2;
    cout << "ptr3 count =  " << ptr3.use_count() << endl;

    ptr1->circle_log();

    if (ptr1) {
        puts("ptr1 is not empty");
    }
}