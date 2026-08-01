#include <stdio.h>

static inline void eat_c(void) {
    while (getchar() != '\n')
        ;
}