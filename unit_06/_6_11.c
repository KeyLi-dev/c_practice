/*第6章 编程练习第11题 原题：

编写一个程序，在数组中读入8个整数，然后倒序打印这8个整数。*/

#include <stdio.h>
#include <stdlib.h>

static inline void quit(void) {
    fprintf(stderr,"输入错误 程序已退出.");
    exit(EXIT_FAILURE);
}

static inline void eat(void) {
    while(getchar() != '\n')
        ;
}

int input_index(void) {
    int index;
    puts("请输入数组长度: ");
    if (scanf("%d",&index) != 1) {
        quit();
    }
    eat();
    // 增加合法性校验，防止分配0/负数内存
    if (index <= 0)
    {
        fprintf(stderr,"长度必须是正整数！\n");
        quit();
    }
    return index;
}

void input_value(int *pst,int index) {
    printf("请输入 %d 个整数: ",index);
    for (int i = 0; i < index; i++) {
        if (scanf("%d", pst + i) != 1) {
            quit();
        }
    }
    eat();
}

void echo_arr(int *pst,int index) {
    // 新建变量存最大下标，不修改传入的index（保留你的原始逻辑思路）
    int last_idx = index - 1;
    for (int i = 0; i <= last_idx; i++) {
        // 沿用你原来的指针运算写法，不改风格
        printf("%d\t", *((pst + last_idx) - i));
    }
}

int main(void) {
    int index = input_index();

    // ✅ 替换变长数组，使用malloc在堆上分配内存
    int *p_arr = (int *)malloc(index * sizeof(int));
    // 必须判断malloc是否分配成功（操作系统内存不足会返回NULL）
    if (p_arr == NULL)
    {
        perror("malloc 内存分配失败");
        quit();
    }

    input_value(p_arr, index);
    printf("\n倒序输出结果：");
    echo_arr(p_arr, index);

    // ✅ 使用完毕一定要释放堆内存，避免内存泄漏
    free(p_arr);
    p_arr = NULL;   // 好习惯：释放后置空，防止野指针

    return 0;
}