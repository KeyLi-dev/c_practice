/*第7章 编程练习第4题 完整题目

使用if...else语句编写一个程序，读取输入，读到#字符时停止。
用感叹号替换句号，用两个感叹号替换原来的感叹号，最后报告替换了多少次。*/

#include <stdio.h>

#define MES '.'
#define MES1 '!'

void input_print(int *pst,int *count) {
    while ((*pst = getchar()) != '#')
        if (*pst == MES) {
            *pst = '!';
            putchar(*pst);
            (*count)++;
        }
        else if (*pst == MES1) {
            *pst = '!';
            putchar(*pst);
            putchar('!');
            (*count)++;
        }
        else {
            putchar(*pst);
        }
}

int main(void) {
    int ch = EOF;
    int count = 0;
    input_print(&ch,&count);
    printf("一共进行替换 %d 次\n",count);
    return 0;
}
