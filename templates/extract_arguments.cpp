#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

template<typename T> 
struct function_traits;  

template<typename R, typename ...Args> 
struct function_traits<std::function<R(Args...)>>
{
    static const size_t nargs = sizeof...(Args);

    typedef R result_type;

    template <size_t i>
    struct arg
    {
        typedef typename std::tuple_element<i, std::tuple<Args...>>::type type;
    };
};

template<typename ClassType, typename Result, typename...Args>
struct function_traits<Result(ClassType::*)(Args...)>
{
    using return_type = Result;
    using args_tuple = std::tuple<Args...>;
    template <size_t i> struct arg
    {
        typedef typename std::tuple_element<i, args_tuple>::type type;
    };

    constexpr static bool is_int_res() {
      return std::is_same<int, Result>::value;
    }
};

class Solution {
public:
  Solution() {}
  virtual ~Solution() {}

  int maxProduct(vector<int>& nums) {
    return 0;
  }
};

int main()
{
   // typedef std::function<R(A,B)> fun;
   // typedef std::function<decltype(maxProduct)> fun1;

   std::cout << std::is_same<vector<int>&, function_traits<decltype(&Solution::maxProduct)>::arg<0>::type>::value << std::endl;

   std::cout << function_traits<decltype(&Solution::maxProduct)>::is_int_res() << std::endl;
   // std::cout << function_traits<fun1>::result_type>::value << std::endl;

   // std::cout << std::is_same<R, function_traits<fun>::result_type>::value << std::endl;
   // std::cout << std::is_same<A, function_traits<fun>::arg<0>::type>::value << std::endl;
   // std::cout << std::is_same<B, function_traits<fun>::arg<1>::type>::value << std::endl;
} 
