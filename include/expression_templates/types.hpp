#pragma once
#include <compare>
#include "type.hpp"

template <typename>
struct __pop_front;

template <template <typename...> typename list, typename x, typename... y>
struct __pop_front <list <x, y...>>
{
    using type = list <y...>;
};


template <typename>
struct __front;

template <template <typename...> typename list, typename x, typename... y>
struct __front <list <x, y...>>
{
    using type = x;
};


template <typename list, int i>
struct __at : __at <__pop_front <list>, i - 1>
{

};

template <typename list>
struct __at <list, 0> : __front <list>
{
    
};


template <typename... T>
struct __types
{
    template <template <typename...> typename U>
    constexpr operator U <T...> ()
    {
        return {};
    }
    
    
//    template <int I>
    struct __iterator
    {
        int i;
        
        
        auto operator == (__iterator const& o) const -> auto
        {
            return o.i == i;
        }
        
        auto operator != (__iterator const& o) const -> auto
        {
            return o.i != i;
        }
        auto operator++ ()
        {
            ++i;
            return *this;
        }
        auto operator= (__iterator const& o)
        {
            i = o.i;
            return *this;
        }
        
        auto operator*() -> decltype (auto)
        {
//            return __type <typename __at <T..., 1>::type> {};
            switch (i)
            {
#define X(_, n, __) \
case n: \
return __type <typename __at <__types <T...>, n>::type> {}; \
break;
                    BOOST_PP_REPEAT (256, X, _);
            }
            return __type <typename __at <T..., 2>::type> {};
//            return typename __at <__types <T...>, 2>::type {};
        }
    };
    
    
    auto begin () const -> auto
    {
        return __iterator {0};
    }
    
    auto end () const -> auto
    {
        return __iterator {sizeof... (T) + 1};
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



