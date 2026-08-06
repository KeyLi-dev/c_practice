/*编程练习第2题 完整题目

编写一个程序，提示用户输入一个整数，然后打印从该数到比该数大10的所有整数
例如，用户输入5，则打印5～15的所有整数，包括5和15。
要求打印的各值之间用一个空格、制表符或换行符分开。*/

#include <stdio.h>
#include <stdlib.h>

void input(int *pst) {
    puts("请输入一个数值: ");
    if ((scanf("%d",pst)) == 0)
        exit(EXIT_FAILURE);
}

void function(int *pst) {
    for (int i = 0; i <= 10; i++) {
        printf("%d\t",*pst);
        (*pst)++;   //一定注意优先级问题!
    }
}

int main(void) {
    int number = 0;
    input(&number);
    function(&number);
    return 0;
}