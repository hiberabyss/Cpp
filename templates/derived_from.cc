#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class A {
public:
  A() {}
  virtual ~A() {}
};

class B : public A {
public:
  B() {}
  virtual ~B() {}
};

template<typename B, derived_from<B> D>
class C {
public:
  C() {}
  virtual ~C() {}
  void sayhi() {
    std::cout << "hello from C"  << std::endl;
  }
};

template<typename T>
concept Derived = derived_from<T, A>;

int main(int argc, char *argv[]) {
  C<A, B>().sayhi();
  // std::cout << Derived<B> << std::endl;
  return 0;
}
