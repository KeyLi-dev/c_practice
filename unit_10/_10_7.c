/*第10章 编程练习第7题

编写一个程序，初始化一个 double 类型的二维数组，
使用编程练习2中的一个复制函数把该数据中的数据复制至另一个二维数组中
因为二维数组是数组的数组，所以可以使用处理一维数组的复制函数来处理数组中的每个子数组*/

#include <stdio.h>

#define ONE 3
#define TWO 5

struct number {
   double arr[ONE][TWO];
}numbers = {
    .arr = {{0}}
};

void input(struct number *pst1,int one,int two) {
    int index = one * two;
    double *pointer = (double *)pst1->arr; 
    puts("准备输入数据: ");
    for (int i = 0; i < index; i++) {
        if (scanf("%lf",pointer) == 1) {
            pointer++;
        }
    }
}

void cpy(struct number *pst1,struct number *pst2,int one,int two) {
    for (int i = 0; i < one; i++) {
        for (int x = 0; x < two; x++) {
            pst2->arr[i][x] = pst1->arr[i][x];
        }
    }
}

void echo(struct number *pointer,int one,int two) {
    for (int i = 0; i < one; i++) {
        for (int x = 0; x < two; x++) {
            printf("%.2f",pointer->arr[i][x]);
            putchar('\t');
        }
    }
    putchar('\n');
}

int main(void) {
    struct number *pointer1 = &numbers;
    struct number number2;
    struct number *pointer2 = &number2;
    input(pointer1,ONE,TWO);
    puts("正在拷贝数据.");
    cpy(pointer1,pointer2,ONE,TWO);
    puts("已显示第一组数据: ");
    echo(pointer1,ONE,TWO);
    puts("已显示第二组数据: ");
    echo(pointer2,ONE,TWO);
    return 0;
}