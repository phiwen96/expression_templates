#pragma once



template <typename T>
struct __type
{
    using type = T;
};

template <typename T>
constexpr auto type = __type <T> {};
