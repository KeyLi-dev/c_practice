#include <stdio.h>

static inline void eat_c(void) {
    while (getchar() != '\n')
        ;
}

void input_value(double *pst) {
    puts("请输入两个浮点数，用空格进行分隔!: ");
    while (1) {
        if (scanf("%lf %lf",pst,pst+1) != 2) {
            puts("是否继续？(y or n)");
            char message;
            scanf(" %c",&message);
            switch(message) {
                case 'y' : eat_c(); continue; break;
                case 'n' : goto if_value;
                default : eat_c(); break;
            }
        }
    if_value : break;
    }
}

void if_value(void) {
    double arr[2] = {0};
    input_value(arr);
    double *pst = arr;
    double max = (*(pst+0) > *(pst+1)) ? *(pst+0) : *(pst+1);
    for (int i = 0; i < 2; i++)
        *(pst+i) = max;
    for (int i = 0; i < 2; i++)
        printf("%.2f\t",*(pst+i));
    fflush(stdout);
}

int main(void) {
    if_value();
    return 0;
}