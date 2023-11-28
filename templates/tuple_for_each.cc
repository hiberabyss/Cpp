#include <tuple>
#include <utility>
#include <iostream>
#include <tuple>
#include <utility>

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

int main()
{
    typedef std::tuple<int, float, double> T;
    T t = std::make_tuple(2, 3.14159F, 2345.678);
    for_each(t, [](auto& i){std::cout<<i<<std::endl;});
}
