#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class A {
public:
  A() {}
  virtual ~A() {}
  static void hi() {
    std::cout << "hi from A" << std::endl;
  }
};

class B : public A {
public:
  B() {}
  virtual ~B() {}

  // static void hi() {
  //   std::cout << "hi from B" << std::endl;
  // }
};

int main(int argc, char *argv[]) {
  B::hi();
  return 0;
}
