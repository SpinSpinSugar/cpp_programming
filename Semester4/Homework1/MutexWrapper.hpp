#ifndef MUTEX_WRAPPER
#define MUTEX_WRAPPER 1

#include <functional>
#include <mutex>

template <typename T>
struct FunctorGuard;


template <typename Ret, typename... Args>
struct FunctorGuard<Ret(Args...)> {
    std::function<Ret(Args...)> functor;
    static std::mutex mtx;

    auto operator()(Args&&... args) -> decltype(auto) {
        const std::lock_guard lock {mtx};
        return std::invoke(functor, args...);
    }

    auto operator()(Args&&... args) -> void
        requires std::is_same_v<void, Ret> {
        const std::lock_guard lock {mtx};
        std::invoke(functor, args...);
    }

};

template <typename Ret, typename... Args>
std::mutex FunctorGuard<Ret(Args...)>::mtx;

template <typename Ret, typename... Args>
FunctorGuard(Ret(Args...)) -> FunctorGuard<Ret(Args...)>;

#endif