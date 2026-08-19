/*编程练习（修改后的题目）

编写程序：现有一个包含 **7 个元素的 double 类型源数组，
把源数组里面的第 3～5 号元素复制到只有 3 个元素的目标数组当中。

说明：
1. 数组下标注意区分：日常生活说的第3、4、5个元素，注意C语言从0开始编号；

2. 复制函数需要你自己实现，不能调用库里面现成复制函数；

3. 要求写一个复制函数，函数形参使用指针形式，实现内存数据拷贝；

4. main函数完成测试：定义源数组、目标数组，调用你写的复制函数，
最后打印目标数组全部元素，验证结果。
*/

#include <stdio.h>
#include <stdlib.h>

#define VALUE1 7
#define VALUE2 3

void copy(const double *pst1,double *pst2,int num1,int num2) {
    for (int i = 0; i < num2; i++) {
        *(pst2+i) = *(pst1+num1);
        num1++;
    }
}

void input(int *const pst,int n) {
    puts("你想在源数组的哪一个下标开始拷贝?");
    if (scanf("%d",pst) != 1)
        exit(EXIT_FAILURE);
    if (*pst < 0 || *pst >= n)
        exit(EXIT_FAILURE);
}

void print(const double *pst,int n) {
    puts("目标数组的元素为：");
    for (int i = 0; i < n; i++) {
        printf("%.2f\t",*(pst+i));
    }
    putchar('\n');
}

int main(void) {
    int index = 0;
    input(&index, VALUE1);
    double arr1[VALUE1] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7};
    double arr2[VALUE2] = {0.0};
    copy(arr1, arr2, index, VALUE2);
    print(arr2, VALUE2);
    return 0;
}
