#include "generic_sort_c_style.h"
#define bool int

bool less(void* rhs, void* lhs) {
    return *((int*) rhs) < *((int*) lhs);
}

void bubble_sort(void* begin, unsigned count, unsigned size, bool (*comp)(void* rhs, void* lhs)) {
    for (int i = 0; i < count; ++i) {
        for (int j = 0; j < count; ++j) {
            if (!(comp((char*)begin + size * i, ((char*) begin) + size * j))) {
                //TODO
            }
        }
    }
}

int main() {
    int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    generic_sort(a, 10, 4, less, bubble_sort);
    return 0;
}