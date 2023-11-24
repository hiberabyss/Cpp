/**
 * Copyright (c) 2019, Tencent Inc
 * Author: Hongbo Liu <hongboliu@tencent.com>
 * Date  : 2019-11-10 18:04:34
 */

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void removeElement(vector<int>& vec, const vector<int>::iterator& it) {
  while (it != vec.end()) {
    vec.erase(it);
  }
}

int main(int argc, char *argv[]) {
  vector<int> arr = {1, 2, 3, 4, 5};
  vector<int>::iterator it = arr.begin() + 2;
  removeElement(arr, it);
  for (auto& n : arr) {
    std::cout << n << std::endl;
  }
  return 0;
}
