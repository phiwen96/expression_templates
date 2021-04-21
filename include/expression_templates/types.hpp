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




template <typename...>
struct has_type;

template <>
struct has_type <>
{
    template <typename T>
    static constexpr bool value = false;
};

template <typename T, typename... U>
struct has_type <T, U...>
{
    template <typename A>
    static constexpr bool value = std::is_same_v <T, A> ? true : has_type <U...>::template value <A>;
};



