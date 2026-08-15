/*修改后的自定义题目（替换原来第7题）

修改版编程第7题题目：
编写一个程序，提示用户输入一个int整型数字。自定义一个函数，
接收这个整型参数，依次计算并打印该数字从 0 次方一直到 10 次方的结果。
main 函数负责提示输入、读取整数，再把这个整数传递给自定义函数完成计算输出。*/

#include <stdio.h>
#include <stdlib.h>

// 0~10 一共 11 个数
#define NUM 11

typedef long long int ll_int;

// 优化版malloc检查函数：支持自定义错误提示
void malloc_s(void *ptr, const char *err_msg)   //指针知识读取，一级指针
{
    if (ptr == NULL)    //指针的指向是否为空 不是指针的值是否为空!
    {
        perror(err_msg);
        exit(EXIT_FAILURE);
    }
}

// 优化版安全释放函数：判空、释放、自动置空，逻辑健壮
void free_s(void **pptr)    //指针要修改指针，所以是二级指针
{
    if (pptr == NULL)
        return;
    if (*pptr != NULL)
    {
        free(*pptr);
        *pptr = NULL;   //这里体现出指针修改指针
    }
}

// 修复bug：不再硬编码*2，而是乘输入的value，通用计算0~10次方
void fun(int value, ll_int *pst, int n)
{
    if (n <= 0)
        return;

    *(pst + 0) = 1; // 任何数0次方都是1
    if (n > 1)
        *(pst + 1) = value; // 1次方等于自身

    for (int i = 2; i < n; i++)
    {
        *(pst + i) = *(pst + i - 1) * value;
    }
}

// 打印函数加const，保护数组不被意外修改，更规范
void echo(const ll_int *pst, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%lld\t", *(pst + i));
    }
    putchar('\n');
    fflush(stdout);
}

int main(void)
{
    int value = 0;
    ll_int *pst = (ll_int *)malloc(NUM * sizeof(ll_int));
    // 使用优化后的malloc_s，带上错误描述
    malloc_s(pst, "malloc 次方数组失败");

    puts("请输入你想求的数字：");
    scanf("%d", &value);

    fun(value, pst, NUM);
    echo(pst, NUM);

    // 最小转换，编译器不再报不兼容指针警告
    free_s((void**)&pst);

    return 0;
}