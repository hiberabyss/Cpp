#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <mutex>

using namespace std;

class DeadLock {
public:
  DeadLock () {}
  ~DeadLock () {}

  void fun2() {
    lock_guard<mutex> g(m);

    std::cout << "Enter fun2" << std::endl;
  }

  void dead_lock_test(int num) {
    if (num <= 0) {
      return;
    }

    lock_guard<mutex> guard(m);

    std::cout << "Begin process" << std::endl;

    fun2();
  }

private:
  mutex m;
};

mutex m;

int main(int argc, char *argv[]) {
  DeadLock l;
  l.dead_lock_test(3);
  return 0;
}
