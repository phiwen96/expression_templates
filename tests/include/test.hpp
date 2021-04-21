#include <catch2/catch.hpp>
#include <expression_templates/expression.hpp>
#include <expression_templates/type.hpp>
#include <expression_templates/types.hpp>
#include <expression_templates/value.hpp>
#include <expression_templates/operators/comparison/distinct.hpp>
//using namespace std;
/**
 bool = types <int, char, string> | identical
 bool types <int, char, string> | distinct
 */

struct A{};

constexpr A a;







auto run () -> int 
{
//    lol (__types <double, double, int> {});

//    std::cout << __imp_distinct <int, double, char, std::string, char>::value << std::endl;
 
    
    auto a0 = types <A, char, int, A, int> | distinct;
    auto e0 = type <int> ;
}


