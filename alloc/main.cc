/**
 * Copyright (c) 2021, Soul Inc
 * Author: Hongbo Liu <liulu3@soulapp.com>
 * Date  : 2021-11-02 23:23:08
 */

#include "alloc.h"

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Foo {
public:
  explicit Foo (int v) : data_(v) {}
  ~Foo () {}

  static void* operator new(size_t N) {
    return alloc_.allocate(N);
  }

  string ToString() {
    return to_string(data_);
  }

  static void operator delete(void* p, size_t size) {
    alloc_.deallocate(p, size);
  }

private:
  inline static Alloc alloc_;
  uint64_t data_ = 0;
};

int main(int argc, char *argv[]) {
  Foo* p[100];
  for (int i = 0; i < 20; ++i) {
    p[i] = new Foo(i+1);

    std::cout << p[i]->ToString() << std::endl;
  }

  for (int i = 0; i < 20; ++i) {
    delete p[i];
  }

  return 0;
}
