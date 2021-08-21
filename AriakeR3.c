#include <stdio.h>

int main(void) {
    int N, max, min, i, tmp;
    scanf("%d", &N);

    scanf("%d", &tmp);
    max = min = tmp;
    for (i = 1; i < N; i++) {
        scanf("%d", &tmp);
        if (tmp > max) {
            max = tmp;
        } else if (tmp < min) {
            min = tmp;
        }
    }

    printf("max = %d\n", max);
    printf("min = %d\n", min);

    return 0;
}