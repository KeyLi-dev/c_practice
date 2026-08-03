#include <stdio.h>

#define INDEX 81

static inline void eat_c(void) {
    while(getchar() != '\n')
        ;
}

int input_value(double *pst) {
    int count = 0;
    puts("请输入任意数量实数 我会在其中找出最大值和最小值 并进行差值计算: ");
    while (1) {
        if (scanf("%lf",pst)) {
            pst++;
            count++;
        }
        else {
            puts("输入完毕!");
            eat_c();
            break;
        }
    }
    return count;
}

double max_value(double *pst) {
    double **ppst = &pst;
    int num = input_value(*ppst);
    double max = 0.0,min = 0.0,cha_zhi = 0.0;
    max = *((*ppst) + 0);
    min = *((*ppst) + 0);
    for (int i = 0; i < num; i++) {
        if (*((*ppst) + i) > max)
            max = *((*ppst) + i);
        if (*((*ppst) + i) < min)
            min = *((*ppst) + i); 
    }
    return (cha_zhi = max - min);
} 

int main(void) {
    double values = 0.0;
    double arr[INDEX] = {0.0};
    values = max_value(arr);
    printf("差值为: %f\n",values);
    return 0;
}