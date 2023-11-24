#include <cstdio>
#include <array>
#include <string_view>
#include <iostream>

using namespace std;

template <const char *S, size_t Start = 0, char... C>
struct __PastLastSlash {
  constexpr auto operator()() {
    if constexpr (S[Start] == '\0') {
      return std::array{C..., '\0'};
    } else if constexpr (S[Start] == '/') {
      return __PastLastSlash<S, Start + 1>()();
    } else {
      return __PastLastSlash<S, Start + 1, C..., (S)[Start]>()();
    }
  }
};

template <const char *S>
struct PastLastSlash {
  static constexpr auto a = __PastLastSlash<S>()();
  static constexpr const char * value{a.data()};
};

constexpr auto captialFirst(std::string_view s) {
  return s.substr(0, 1);
}

#define GetName(s) PastLastSlash<s>::value

#define DEFINE_DATA_WITH_GETTER(s) \
public: \
  int GetName(s)() { \
    return s##_; \
  } \
private: \
  int s##_ = 100;

class Test {
  DEFINE_DATA_WITH_GETTER(first_data);
};

int main() {
  Test t;
  // std::cout << t.first_data() << std::endl;
  // std::cout << DEFINE_DATA_WITH_GETTER("hello") << std::endl;
  // printf(DEFINE_DATA_WITH_GETTER("hello"));
  // static constexpr char f[] = __FILE__;
  // puts(PastLastSlash<f>::value);
  return 0;
}
