typedef void (*algo_type)(void*, unsigned count, unsigned size, int (*)(void*,void*));
void generic_sort(void* begin, unsigned count, unsigned size, int (*comp)(void*,void*), algo_type algo){
    algo(begin, count, size, comp);
}