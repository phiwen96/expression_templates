#include <catch2/catch.hpp>
#include <expression_templates/expression.hpp>
#include <expression_templates/type.hpp>
#include <expression_templates/types.hpp>
//using namespace std;
/**
 bool = types <int, char, string> | identical
 bool types <int, char, string> | distinct
 */

struct A{};

auto run () -> int 
{
    constexpr A a;
//    constexpr auto a0 = types <A, char, int> | ;
    auto e0 = type <int> ;
}


