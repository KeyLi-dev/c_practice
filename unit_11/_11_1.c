/*11.7 编程练习 第1题 原题：

设计并测试一个函数，从输入中获取 n 个字符（包括空白、制表符、换行符）
把结果存储在一个数组里，作为一个参数传递数组的地址。*/

#include <stdio.h>
#include <stdlib.h>

// 函数声明
// 参数：字符指针（数组首地址）、要读取的字符个数n
void read_n_chars(char *buf, int n);
void print_buffer(char *buf, int n);

int main(void)
{
    int n;
    char *buffer = NULL;

    printf("请输入要读取的字符数量 n：");
    if (scanf("%d", &n) != 1 || n <= 0)
    {
        printf("输入无效\n");
        return 1;
    }

    // malloc 动态分配堆内存
    buffer = (char *)malloc(n * sizeof(char));
    if (buffer == NULL)   // 必须判断malloc是否分配失败
    {
        perror("malloc failed");
        return 1;
    }

    // 吃掉scanf留下的换行符，否则第一个getchar会读到回车
    while (getchar() != '\n');

    printf("请输入任意字符（可输入空格、换行、制表符，一共录入%d个）：\n", n);
    read_n_chars(buffer, n);    // 指针传递动态数组

    printf("\n你录入的 %d 个字符依次是：\n", n);
    print_buffer(buffer, n);

    // 释放堆内存
    free(buffer);
    buffer = NULL;

    return 0;
}

// 自定义读取函数：指针遍历，读取n个字符（包含空白、换行、Tab）
void read_n_chars(char *buf, int n)
{
    for (int i = 0; i < n; i++)
    {
        *(buf + i) = getchar();  // 指针偏移赋值，等价于 buf[i]
    }
}

// 自定义打印函数：指针遍历输出
void print_buffer(char *buf, int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = *(buf + i);
        // 美化输出：换行符单独标记显示
        if (ch == '\n')
            printf("[换行] ");
        else if (ch == '\t')
            printf("[制表] ");
        else
            printf("%c ", ch);
    }
    putchar('\n');
}