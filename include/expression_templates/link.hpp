#pragma once
#include "concepts/c_transformer.hpp"



template <typename lhs, typename rhs>
struct __link
{
    using me = __link <lhs, rhs>;
    
    template <typename NewTransformer>
    requires requires {
        can_add_transformer <rhs, lhs>;
    }
    using add_transformer = __link <lhs, typename rhs::template add_transformer <rhs>>;

    template <typename... types>
    using transform = typename rhs::template transform <typename lhs::template transform <types...>>;
};
