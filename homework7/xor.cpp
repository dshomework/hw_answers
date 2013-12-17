#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n;

int main() {
    scanf("%d", &n);
    long s = 0;
    long x;
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        s ^= x;
    }
    printf("%d\n", s);

    return 0;
}
