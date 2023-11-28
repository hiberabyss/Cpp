#include <tuple>
#include <utility>
#include <iostream>
#include <tuple>
#include <utility>

template<std::size_t I = 0, typename FuncT, typename ... Tp>
void ForEach(std::tuple<Tp...>&, FuncT) requires(I == sizeof...(Tp)) {}

template<std::size_t I = 0, typename FuncT, typename ... Tp>
void ForEach(std::tuple<Tp...> &t, FuncT f) requires(I < sizeof...(Tp)) {
  f(std::get<I>(t));
  ForEach<I + 1, FuncT, Tp...>(t, f);
}

template<typename T>
void Typeid() {
  std::cout << typeid(T).name() << std::endl;
}

template<typename... ARGS>
void ForEachType() {
  ((Typeid<ARGS>()), ...);
}

int main() {
    typedef std::tuple<int, float, double> T;
    T t = std::make_tuple(2, 3.14159F, 2345.678);
    ForEach(t, [](auto i) {
      std::cout<<i<<std::endl;
    });

    ForEachType<int, float, double>();
}
