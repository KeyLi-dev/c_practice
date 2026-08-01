#include <stdio.h>

#define INDEX 3

static inline void eat_c(void) {
    while (getchar() != '\n')
        ;
}

void input_value(double *pst,int n) {
    puts("请输入三个浮点值，空格进行分隔: ");
    for (int i = 0; i < n; i++) {
        if (scanf("%lf",pst) != 1) {
            puts("请重新输入: ");
            eat_c();
            continue;
        }
        pst++;
    }
}    

void echo_arr(double *pst,int n) {
    for (int i = 0; i < n; i++) {
        printf("%.2f\t",*(pst+i));
        fflush(stdout);
    }
}

void val_fun(int n) {
    double arr[INDEX] = {0.0};
    static double min,age,max;  //我不会浮点数初始化
    input_value(arr,INDEX);
    double *pointer = arr;
    echo_arr(arr,INDEX);
    //假设最大值，找出最大值
    max = *(pointer+0);
    min = *(pointer+1);
    for (int i = 0; i < n; i++) {
        if (max <= *(pointer+i))
            max = *(pointer+i);
    }
    for (int i = 0; i < n; i++) {
        if (*(pointer+i) < max && *(pointer+i) < min) {
            min = *(pointer+i);
        }
    }
    for (int i = 0; i < n; i++) {
        if (*(pointer+i) < max && *(pointer+i) > min) {
            age = *(pointer+i);
        }
    }
    printf("max = %.2f age = %.2f min = %.2f\n",max,age,min);
}

signed int main(void) {
    val_fun(INDEX);
    return 0;
}