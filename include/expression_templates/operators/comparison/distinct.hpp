#pragma once
#include "../../types.hpp"


struct __distinct
{
private:
    template <typename...>
    struct __imp;

    template <typename T>
    struct __imp <T>
    {
        template <template <typename...> typename B, typename... A>
        using type = std::conditional_t <has_type <A...>::template value <T>, B <A...>, B <A..., T>>;
        
        template <template <typename...> typename B, typename... A>
        static constexpr bool value = has_type <A...>::template value <T> ? false : true;
    };

    
    template <typename T, typename... U>
    struct __imp <T, U...>
    {
        template <template <typename...> typename B, typename... A>
        using type = std::conditional_t <has_type <A...>::template value <T>, typename __imp <U...>::template type <B, A...>, typename __imp <U...>::template type <B, A..., T>>;
        
        template <template <typename...> typename B, typename... A>
        static constexpr bool value = has_type <A...>::template value <T> ? __imp <U...>::template value <B, A...> : __imp <U...>::template value <B, A..., T>;
    };
    
public:
    template <template <typename...> typename T, typename... U>
    using transform = typename __imp <U...>::template type <T>;
    
    template <template <typename...> typename T, typename... U>
    static constexpr bool value = __imp <U...>::template value <T>;
};






constexpr auto distinct = __distinct {};

