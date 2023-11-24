#include <iostream>

struct A
{
    ~A()
    {
        std::cout << "A::~A()" << std::endl;
    }
};

struct B
{
  virtual ~B() {}
};

struct C : public B
{
    A a;
};

int main(int argc, char *argv[])
{
    B *b = new C;
    delete b; // UB, and won't print "A::~A()"
    return 0;
}
