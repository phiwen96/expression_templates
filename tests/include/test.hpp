#include <catch2/catch.hpp>
#include <expression_templates/expression.hpp>
#include <expression_templates/type.hpp>
#include <expression_templates/types.hpp>
#include <expression_templates/value.hpp>
#include <expression_templates/operators/comparison/distinct.hpp>
//using namespace std;
#include <experimental/coroutine>
using namespace std::experimental;
/**
 bool = types <int, char, string> | identical
 bool types <int, char, string> | distinct
 */

struct A{};

constexpr A a;


struct suspend {
    auto await_ready () {
        std::cout<<"suspend::await_ready" << std::endl;
        return false;
    }
    auto await_suspend (coroutine_handle <> c) {
        std::cout<<"suspend::await_suspend" << std::endl;
        return true;
//        return c;
    }
    auto await_resume () {
        std::cout<<"suspend::await_resume" << std::endl;
    }
};

inline static int func {0};

struct co_task
{
    struct promise_type
    {
        std::string created;
        promise_type (std::string created = __builtin_FUNCTION ()) : created {created} {}
        coroutine_handle <> continuation;
        co_task get_return_object () {return co_task {*this};}
        auto initial_suspend () {return suspend_never {};}
        auto final_suspend () noexcept {
            struct a
            {
                auto await_ready () noexcept {return false;}
//                auto await_suspend (coroutine_handle <promise_type> c) noexcept -> coroutine_handle<>
//                {
//                    auto& handle = c.promise ().continuation;
//                    if (handle and not handle.done()) {
//
//                        return handle;
//                    }
//                    else return noop_coroutine();
//                }
                auto await_suspend (coroutine_handle <promise_type> c) noexcept
                {
                    return false;
                }
                auto await_resume () noexcept {}
            };
            return a {};
        }
        auto unhandled_exception () {}
        auto return_void () {}
        auto await_transform (suspend s) {return s;}
        auto await_transform (co_task called_and_perhaps_done) {
            /**
             this is called after
             */
            std::cout << created << " awaiting " << called_and_perhaps_done.m_p.created << std::endl;
            struct awaited {
                promise_type& p;
                coroutine_handle <promise_type> c {coroutine_handle <promise_type>::from_promise(p)};
                
                auto await_ready () {
                    bool called_is_done = c.done();
                    std::cout<<"await_ready 1" << std::endl;
                    return called_is_done;
                }
                auto await_suspend (coroutine_handle <> s) {
                    std::cout<<"await_suspend 1" << std::endl;

                    p.continuation = s;
//                    return coroutine_handle<promise_type>::from_promise(p);
                    return true;
                }
                auto await_resume () {
                    std::cout<<"await_resume 1" << std::endl;
                    if (not coroutine_handle<promise_type>::from_promise(p).done())
                        coroutine_handle<promise_type>::from_promise(p).resume();
                }
            };
            return awaited {called_and_perhaps_done.m_p};
        }
    };
    auto resume () {
        coroutine_handle <promise_type>::from_promise (m_p).resume ();
    }

    
    promise_type& m_p;
    
    co_task (promise_type& p) : m_p {p} {}
//    co_task (coroutine_handle <promise_type>&& o) : m_p {o.promise ()} {}
};


template <typename...>
union uni;


template <typename A, typename... B>
union uni <A, B...>
{
    
};

template <typename A>
union uni <A>
{
    
};


auto run_task3 () -> co_task
{
    std::cout << "...run_task3" << std::endl;
//    co_await suspend {};
    std::cout << "run_task3..." << std::endl;
    co_return;
}


auto run_task2 () -> co_task
{
    std::cout << "...run_task2" << std::endl;
    co_await run_task3 ();
//    co_await suspend {};

    std::cout << "run_task2..." << std::endl;
    co_return;
}


auto run_task () -> co_task
{
    std::cout << "...run_task" << std::endl;
//    co_await suspend {};
    
    co_await run_task2();
    std::cout << "run_task..." << std::endl;
}

auto run () -> int 
{
    auto t = run_task ();
//    t.resume ();
//    t.resume ();
    

    
//    for (auto i : types <char, int, double> )
//    {
//
//    }

    
    auto a0 = types <A, char, int, A, int> | distinct;
    
    if (types <A, char, int> | distinct)
    {
//        std::cout << "yaay" << std::endl;
    }
    
    auto e0 = type <int> ;
}


