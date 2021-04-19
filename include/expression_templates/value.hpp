#pragma once




template <decltype (auto) t>
struct __value
{
    using type = decltype (std::decay_t <decltype (t)> (t));
    static constexpr decltype (t) value = t;
};



template <decltype (auto) t>
constexpr __value <std::forward <decltype (t)> (t)> value {};
