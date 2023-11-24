#include <cstdio>
#include <iostream>
#include <algorithm>
#include <type_traits>
#include <vector>

using namespace std;

template<typename T>
struct is_container :
  bool_constant<requires(const T& t) {t.empty();}> {};

template<typename T>
inline constexpr bool is_container_v = is_container<T>::value;

int main(int argc, char *argv[]) {
  vector<int> v = {1, 2, 3};
  std::cout << is_container_v<const vector<int>&>  << std::endl;
  std::cout << is_container_v<int>  << std::endl;
  return 0;
}
