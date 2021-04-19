#pragma once




template <typename... T>
struct __types
{
    template <template <typename...> typename U>
    constexpr operator U <T...> ()
    {
        return {};
    }
};


template <typename... T>
constexpr auto types = __types <T...> {};
