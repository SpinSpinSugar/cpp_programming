#include <iostream>
#include <stdio.h>

int main() {
    FILE* f = fopen("1.txt", "wr");
    fclose(f);
    return 0;
}