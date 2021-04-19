#pragma once
#include "type.hpp"

template <typename...>
struct __identical;


template <typename T>
struct __identical <T>
{
    using type = bool;
};

constexpr auto identical = __identical {};



template <
