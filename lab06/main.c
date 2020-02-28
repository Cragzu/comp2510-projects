#include <stdio.h>
#include <limits.h>

int main() {
    int x = -2;
    int y = -3;
    printf("%d", (x & y) + ((x ^ y) >> 1));

    return 0;
}
