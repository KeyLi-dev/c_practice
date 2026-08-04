/*题目要求：

不使用全局变量，重写程序清单 12.4 的代码。

程序清单12.4 原版代码（带中文注释，对应书上global.c）
#include <stdio.h>
// 外部全局变量（整个文件内所有函数都能访问）
int units = 0;

void critic(void);

int main(void)
{
    // extern 在这里是可选的重复声明，同文件下可以省略
    extern int units;

    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);

    while (units != 56)
    {
        critic(); // 调用另一个函数修改全局变量units
    }
    printf("You must have looked it up!\n");

    return 0;
}

void critic(void)
{
    // 直接读写全局变量 units
    printf("No luck, my friend. Try again.\n");
    scanf("%d", &units);
}
*/

#include <stdio.h>

void guess_score(int *pst) {
    puts("请给我的颜值打个分,满分100.");
    again:scanf("%3d",pst);
    if (((*pst) != 99) || ((*pst) <= 0) ) {
        puts("我相信你手滑输入错了!");
        puts("再来一次!");
        goto again;
    }
    else {
        printf("每座, \'%3d\' 分刚好符合我的实际颜值!");
    }
}

void again_fun(int *pst) {
    puts("如果这个分数不是你的本意，我可以给你一个偷偷修改的机会.");
    puts("请最后真心真意的输入给我颜值的分数.");
    again1:scanf("%3d",pst);
    if (*pst < 60) {
        puts("不能低于60!很难接受!");
        goto again1;
    }
    else {
        printf("最终分数 %3d\n",*pst);
    }
}

int main(void) {
    int score = 0;
    guess_score(&score);
    again_fun(&score);
    return 0;
}