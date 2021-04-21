#pragma once



template <typename...>
struct __imp_distinct;


template <typename T>
struct __imp_distinct <T>
{
    using type = T;
    static constexpr bool value = true;
};

template <typename T, typename U, typename... V>
struct __imp_distinct <T, U, V...>
{
//    using type = T;
    static constexpr bool value = true;
};




struct __distinct
{
    template <template <typename...> typename T, typename... U>
    using transform = T <U...>;
};




constexpr auto distinct = __distinct {};



//template <template <typename...> typename T, typename... U>
//auto operator | ()
