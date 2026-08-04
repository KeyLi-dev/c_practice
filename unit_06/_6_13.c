/*编程练习第13题 题目原文

编写一个程序，创建一个包含 8 个元素的 int 类型数组，
分别把数组元素设置为 2 的前 8 次幂，使用 for 循环设置数组元素的值，
使用 do…while 循环显示数组元素的值。*/

#include <stdio.h>

#define INDEX 8

typedef unsigned int un_in;

void w_arr(un_in *pst,int n) {
    *(pst+0) = 2;
    
    for (int i = 1;i < n;i++) {
        *(pst+i) = *(pst +i -1) *2;
    }
}

void echo_arr(un_in *pst,int n) {
    int i = 0;
    do {
        printf("%u\t",*(pst+i));
        i++;
        fflush(stdout);
    }
    while (i < n);
}

int main(void) {
    un_in arr[INDEX] = {0};
    w_arr(arr,INDEX);
    echo_arr(arr,INDEX);
    return 0;
}