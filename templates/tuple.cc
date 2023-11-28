#include <cstdio>
#include <iostream>
#include <algorithm>
#include <memory>
#include <tuple>
#include <vector>

using namespace std;

template<std::size_t I = 0, typename FuncT, typename ... Tp>
inline typename std::enable_if<I == sizeof...(Tp), void>::type
for_each(std::tuple<Tp...>&, FuncT) // Unused arguments are given no names.
{
}

template<std::size_t I = 0, typename FuncT, typename ... Tp>
inline typename std::enable_if<I < sizeof...(Tp), void>::type
for_each(std::tuple<Tp...> &t, FuncT f)
{
    f(std::get<I>(t));
    for_each<I + 1, FuncT, Tp...>(t, f);
}

template<typename... ARGS>
class A {
public:
  A() {}
  virtual ~A() {}
  void GenAll() {
    for_each(items_, [](auto& type) {
      using Type = remove_cvref_t<decltype(*type)>;
      type.reset(new Type());
      std::cout << typeid(Type).name() << std::endl;
    });
  }

private:
  std::tuple<unique_ptr<ARGS>...> items_;
};

int main(int argc, char *argv[]) {
  tuple<int, int, double> t{12, 3, 4.5};
  std::cout << get<0>(t) << std::endl;

  A<int, double, int> a;
  a.GenAll();
  return 0;
}
