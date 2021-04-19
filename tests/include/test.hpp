#include <catch2/catch.hpp>
#include <expression_templates/expression.hpp>
#include <expression_templates/type.hpp>
#include <expression_templates/types.hpp>
#include <expression_templates/value.hpp>
//using namespace std;
/**
 bool = types <int, char, string> | identical
 bool types <int, char, string> | distinct
 */

struct A{};

constexpr A a;

auto run () -> int 
{
    
    
    constexpr auto d = value <(a)>;
    
    A aa = d.value;
    
    std::cout << std::is_same_v <decltype (d.value), A const&> << std::endl;
//    constexpr auto a0 = types <A, char, int> | ;
    auto e0 = type <int> ;
}


