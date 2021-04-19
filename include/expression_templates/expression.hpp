#pragma once
#include "concepts/c_transformer.hpp"


template <typename...>
struct expression;



template <typename transformer,
          template <typename...> typename types_container,
          typename... types>
requires requires {
    requires can_transform <transformer, types_container, types...>;
}
struct expression <types_container <types...>, transformer>
{
    using type = typename transformer::template transform <types_container, types...>;
    
    operator auto () {
        return type {};
    }
};
