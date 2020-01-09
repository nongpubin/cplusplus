#include <iostream>

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
    shape();
    ~shape();
};

shape::shape()
{
}

shape::~shape()
{
}


class circle: public shape
{
private:

public:
    void circle_out(void) { std::cout << "circle" << std::endl; }
    circle();
    ~circle();
};

circle::circle()
{
}

circle::~circle()
{
}

class triangle:public shape
{
private:

public:
    void triangle_out(void) { std::cout << "triangle" << std::endl; }
    triangle();
    ~triangle();
};

triangle::triangle()
{
}

triangle::~triangle()
{
}

class rectangle : public shape
{
private:
 
public:
    void rectangle_out(void) { std::cout << "rectangle" << std::endl; }
    rectangle();
    ~rectangle();
};

rectangle::rectangle()
{
}

rectangle::~rectangle()
{
}


shape* create_shape(shape_type type)
{
    switch (type)
    {
    case shape_type::circle:
        return new circle();
        break;
    case shape_type::rectangle:
        return new rectangle();
        break;
    case shape_type::triangle:
        return new triangle();
        break;
    default:
        break;
    }
}

class shape_wrapper
{
public:

    explicit shape_wrapper(shape *ptr = nullptr):ptr_(ptr) {}

    ~shape_wrapper()
    {
        delete ptr_;
    }
    shape *get() const { return ptr_; }

private:
    shape *ptr_;
};


int main()
{
    circle shp;
    shp.circle_out();
    shape *ps = create_shape(shape_type::rectangle);
    ps->shape_out();

   shape_wrapper shape_pt((triangle*)create_shape(shape_type::triangle));
   shape_pt.get()->shape_out();

   return 0;
}