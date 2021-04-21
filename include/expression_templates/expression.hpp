#pragma once
#include "concepts/c_transformer.hpp"
#include "types.hpp"


template <typename...>
struct expression;



template <typename transformer, template <typename...> typename types_container, typename... types>
requires requires {
    requires can_transform <transformer, types_container, types...>;
}
struct expression <types_container <types...>, transformer>
{
    using type = typename transformer::template transform <types_container, types...>;
    
    constexpr operator auto () {
        return type {};
    }
};




template <template <typename...> typename T, typename... U, typename transformer>
requires requires {
    requires can_transform <transformer, T, U>;
}
constexpr auto operator| (T <U...> const&, transformer const&) -> expression <T <U...>, transformer>
{
    return {};
}



