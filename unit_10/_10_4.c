/*第10章 编程练习第4题

编写一个程序，返回存储在 double 类型数组中的最大值的下标，
并在一个简单的程序中测试该函数。*/

#include <stdio.h>

#define INDEX 1   // 指针数组里面只放1个一级指针

int input_value(double **pp, int data_len) {
    // pp 是二级指针，对应指针数组 arr
    double *data_ptr = pp[0];  // 取出指针数组里第一个一级指针
    int cnt = 0;
    puts("输入小数，空格分隔，输入q结束：");
    while (scanf("%lf", data_ptr) == 1 && cnt < data_len-1) {
        data_ptr++;
        cnt++;
    }
    return cnt;
}

void echo_arr(double **pp, int n) {
    double *p = pp[0]; // 拿到指针数组里的一级指针
    for(int i=0; i<n; i++){
        printf("%.2f ", p[i]);
    }
    printf("\n");
}

void max_index(double **pp, int n) {
    if(n <= 0) return;
    double *p = pp[0];
    unsigned short max_ind = 0;
    for(int i=1; i<n; i++){
        if(p[i] > p[max_ind]){
            max_ind = i;
        }
    }
    printf("最大值下标：%hu\n", max_ind);
}

int main(void) {
    // 1. 定义一个真正存数字的double数组
    double real_data[81] = {0.0};
    // 2. 定义【指针数组】，里面只有1个一级指针
    double *ptr_arr[INDEX];
    // 指针数组的第0个元素，指向真实数据数组
    ptr_arr[0] = real_data;

    // 指针数组名 ptr_arr 天然就是 double** 二级指针，直接传
    int valid_num = input_value(ptr_arr, 81);
    
    echo_arr(ptr_arr, valid_num);
    max_index(ptr_arr, valid_num);

    return 0;
}