#ifndef MUTEX_WRAPPER
#define MUTEX_WRAPPER 1

#include <functional>
#include <mutex>

template <typename T>
class FunctorGuard;

template <typename Ret, typename... Args>
struct FunctorGuard<Ret(Args...)> {
    std::function<Ret(Args...)> functor;
    std::mutex mutex;

    constexpr auto operator()(Args&&... args) -> decltype(auto) {
        while (!mutex.try_lock()) {} //TODO WTF
        decltype(auto) ret = std::invoke(functor, args...);
        mutex.unlock();
        return ret;
    }

    constexpr auto operator()(Args&&... args) -> void 
        requires std::is_same_v<void, Ret> {
        while (!mutex.try_lock()) {} //TODO WTF
        std::invoke(functor, args...);
        mutex.unlock();
    }

};

template <typename Ret, typename... Args>
FunctorGuard(Ret(Args...)) -> FunctorGuard<Ret(Args...)>;


#endif