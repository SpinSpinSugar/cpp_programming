#include "generic_sort_c_style.h"
#define bool int

bool less(void* rhs, void* lhs) {
    return *((int*) rhs) < *((int*) lhs);
}

int main() {
    int a[10] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    generic_sort(a, 10, 4, less, bubble_sort);
    return 0;
}