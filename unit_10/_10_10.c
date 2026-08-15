/*编程练习第10题

编写一个函数，把两个数组中相对应的元素相加，
然后把结果存储到第3个数组中。也就是说，
如果数组1中包含的值是 2、4、5、8，数组2中包含的值是 1、0、4、6，
那么该函数就把 3、4、9、14 赋值给第3个数组。函数接受3个数组名和一个数组大小
在一个简单的程序中测试该函数。*/

#include <stdio.h>
#include <stdlib.h>

#define INDEX 5

void malloc_s(void *);
void free_s(void **);
void input_arr(int *,int);
void echo_arr(const int *,int);
void add_fun(int *,int *,int *,int);
static inline void eat(void);

int main(void) {
    int *pst1 = (int *)malloc(INDEX * sizeof(int));
    malloc_s(pst1);
    puts("请输入第一个数组的5个元素: ");
    input_arr(pst1,INDEX);
    puts("第一个数组的元素为: ");
    echo_arr(pst1,INDEX);
    int *pst2 = (int *)malloc(INDEX * sizeof(int));
    malloc_s(pst2);
    puts("请输入第二个数组的5个元素: ");
    input_arr(pst2,INDEX);
    puts("第二个数组的元素为: ");
    echo_arr(pst2,INDEX);
    int *pst3 = (int *)malloc(INDEX * sizeof(int));
    malloc_s(pst3);
    add_fun(pst1, pst2, pst3, INDEX);
    puts("两个数组对应元素相加的结果为: ");
    echo_arr(pst3,INDEX);

    free_s((void **)&pst1);
    free_s((void **)&pst2);
    free_s((void **)&pst3);
    return 0;
}

static inline void eat(void) {
    while (getchar() != '\n')
        ;
}

void malloc_s(void *pst) {
    if (pst == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
}

void free_s(void **ppst) {
    if (ppst == NULL) {
        return;
    }
    if (*ppst != NULL) {
        free(*ppst);
        *ppst = NULL;
    }
}

void input_arr(int *pst,int n) {
    for (int i = 0; i < n; i++) {
        printf("请输入第 %d 个元素: ",i+1);
        source:if (scanf("%d",pst+i) != 1) {
            eat();
            puts("我看你输入错了 重新输入: ");
            goto source;
        }
    }
}

void echo_arr(const int *pst,int n) {
    for (int i = 0; i < n; i++) {
        printf("%d\t",*(pst+i));
    }
    printf("\n");
}

void add_fun(int *pst1,int *pst2,int *pst3,int n) {
    for (int i = 0; i < n; i++) {
        *(pst3+i) = *(pst1+i) + *(pst2+i);
    }
}