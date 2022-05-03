#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_SIZE 100

void main () {
    char *c = (char *)malloc(DEFAULT_SIZE);
    char ch;
    int count = 0, capacity = DEFAULT_SIZE;
    while ((ch = getchar()) != '0') {
        if (count == capacity) {
            capacity += DEFAULT_SIZE;
            c = realloc(c, capacity);
        }
        c[count++] = ch;
    }
    c[count] = '\0';
    printf("%s", c);
}