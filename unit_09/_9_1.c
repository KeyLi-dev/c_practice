#include <stdio.h>
#include <stdlib.h>

static inline double min_doub(double x,double y) {
    return (x > y) ? y : x;
}

void input_doub(double *pst) {
    puts("Please enter a double number: ");
    while (scanf("%lf %lf",pst,pst+1) != 2) {
        puts("quit!");
        exit(EXIT_FAILURE); 
    }
    printf("最小数值为 %.2f\n",min_doub(*(pst+0),*(pst+1)));
}

int main(void) {
    double doub_arr[2] = {0};
    input_doub(doub_arr);
    return 0;
}