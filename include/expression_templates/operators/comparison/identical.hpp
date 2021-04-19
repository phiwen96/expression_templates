#pragma once
#include "type.hpp"
#include "value.hpp"

template <typename...>
struct __identical;

template <>
struct __identical <>
{
    
};


template <typename T>
struct __identical <T> //: __value <true>
{
};

constexpr auto identical = __identical {};



