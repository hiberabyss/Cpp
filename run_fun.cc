#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

struct Test {
  int x;
  string y;
};

Test test;

class RunFun {
public:
  RunFun(const function<void()>& fun) {
    fun();
  }
};

void init_test() {
  test.x = 207;
  test.y = "hello";
}

function<void()> fun = init_test;

static RunFun __init_test([](){
  test.x = 207;
  test.y = "hello";
});

int main(int argc, char *argv[]) {
  std::cout << test.y << test.x << std::endl;
  return 0;
}
