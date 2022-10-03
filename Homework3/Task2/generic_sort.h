#include <forward_list>
#include <list>

// generic_sort overload set
typedef bool (*Comp)(void*, void*);
typedef void (*Algo_type)(void*, std::size_t total_elems, std::size_t size, Comp cmp);

void generic_sort(void* begin, std::size_t total_elems, std::size_t size, Comp cmp, Algo_type algo) {
    algo(begin, total_elems, size, cmp);
}

template<typename T, typename Comp = std::less<>>
void generic_sort(std::forward_list<T>& list, Comp cmp = std::less<>{}) {
    list.sort(cmp);
}

template<typename T, typename Comp = std::less<>>
void generic_sort(std::list<T>& list, Comp cmp = std::less<>{}) {
    list.sort(cmp);
}

// Namespace for algorithms and comparators
#define SWAP(a, b, size)						                      \
    do									                              \
        {									                          \
            std::size_t tmpsize = (size);						          \
            char *tmpa = (a), *tmpb = (b);					          \
            do								                          \
                {								                      \
                    char tmptmp = *tmpa;						      \
                    *tmpa++ = *tmpb;						          \
                    *tmpb++ = tmptmp;						          \
                } while (--tmpsize > 0);						      \
        } while (0)


namespace generic_sort_utility {
    // Comparators
    bool less_int(void* rhs, void* lhs) {
        return *(reinterpret_cast<int*>(rhs)) < *(reinterpret_cast<int*>(lhs));
    }

    bool greater_int(void* rhs, void* lhs) {
        return *(reinterpret_cast<int*>(rhs)) > *(reinterpret_cast<int*>(lhs));
    }


    bool less_double (void* rhs, void* lhs) {
        return *(reinterpret_cast<double*>(rhs)) < *(reinterpret_cast<double*>(lhs));
    }

    bool greater_double (void* rhs, void* lhs) {
        return *(reinterpret_cast<double*>(rhs)) > *(reinterpret_cast<double*>(lhs));
    }
    
    //Sortings
    void insertion_sort() {}

    void bubble_sort(void* begin, std::size_t total_elems, std::size_t size, Comp cmp) {
        char* tmp1 = reinterpret_cast<char*>(begin);
        char* tmp2;
        for (int i = 0; i < total_elems; ++i) {
            tmp1 += i * size;
            for(int j = total_elems; j > i; --j) {
                tmp2 = reinterpret_cast<char*>(begin) + (j - 1) * size;
                if (!((*cmp)(reinterpret_cast<void*> (tmp1), reinterpret_cast<void*> (tmp2)))) SWAP(tmp1, tmp2, size);
            }
            tmp1 = reinterpret_cast<char*>(begin);
        }
    }
}