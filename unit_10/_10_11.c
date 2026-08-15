/*第10章 编程练习第11题

编写一个程序，声明一个int类型的3×5二维数组，并用合适的值初始化它。
该程序打印数组中的值，然后把各值翻倍（即是原值的2倍）并显示出各元素的新值。
编写一个函数以显示数组的内容，再写一个函数把各个元素翻倍。
这两个函数都以数组名和行数作为参数。
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

struct number {
    int arr[3][5];
    long int twice_arr[3][5];
} numbers = {
    .arr = {
        {1,2,3,4,5},
        {6,7,8,9,10},
        {11,12,13,14,15}
    }
};

//不可修改指针指向的数值;
void echo(const struct number *pst,int rows) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < 5; j++) {
            printf("%d\t", pst->arr[i][j]);
        }
        putchar('\n');
    }
    fflush(stdout);
}

void print(struct number *pst,int rows,const char *pst_c) {
    pid_t pid = fork();
    if (pid < 0) {
        perror(pst_c);
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) {
        printf("子进程开始执行任务 我的pid是:%d,我的父进程pid是:%d\n",getpid(), getppid());

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 5; j++) {
                pst->twice_arr[i][j] = (long int)pst->arr[i][j] * 2; 
                printf("%ld\t", pst->twice_arr[i][j]);
            }
            putchar('\n');
        }
        fflush(stdout);
    }
    else {
        wait(NULL); //防僵尸;
        printf("我的子进程 %d 或许已经完成了任务\n",pid);
        printf("我是它的父进程 %d\n",getpid());
    }
}

int main(void) {
    struct number *pointer = &numbers;
    echo(pointer, 3);
    print(pointer, 3, "fork 创建子进程失败");
    return 0;
}