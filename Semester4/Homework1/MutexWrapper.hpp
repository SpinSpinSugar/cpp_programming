#ifndef MUTEX_WRAPPER
#define MUTEX_WRAPPER 1

#include <functional>
#include <mutex>

template <typename T>
struct FunctorGuard;

template <typename Ret, typename... Args>
struct FunctorGuard<Ret(Args...)> {
    std::function<Ret(Args...)> functor;
    static inline std::mutex mtx {};
    //wtf inline linkage
    //TODO один мьютекс на все FIX
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
FunctorGuard(Ret(Args...)) -> FunctorGuard<Ret(Args...)>;

#endif