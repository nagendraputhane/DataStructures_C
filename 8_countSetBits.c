#include <stdio.h>

void main() {
    int n, i;

    printf("Enter a number\n");
    scanf("%d", &n);
    for(i = 0; n != 0; n >>= 1) {
        printf("%d, ", n);
        if(n & 1) {
            i++;
        }
    }
    printf("\nNumber of 1's: %d", i);
}