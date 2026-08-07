/*第9章 编程练习第3题

编写一个函数，接受3个参数——一个字符和两个整数。
字符参数是待打印的字符，第1个整数指定1行中打印字符的次数，
第2个整数指定打印指定字符的行数。同时，编写一个调用该函数的程序。*/

#include <stdio.h>

static inline void eat(void) {
    while (getchar() != '\n')
        ;
}

void input_c(char *pst) {
    sour:puts("请输入要打印的字符: ");
    if (scanf(" %1c",pst) != 1) {
        eat();
        goto sour;
    }
}

void input_n(int *row,int *cols) {
    puts("温馨提示 不要超过10 不然屏幕装不下!");
    sourc:puts("请输入行数和列数 空格分隔: ");
    if (scanf("%1d %1d",row,cols) != 2) {
        eat();
        goto sourc;
    }
}

void echo(char *pst,int *row,int *cols) {
    for (int i = 0; i < (*row); i++) {
        for (int x = 0; x < (*cols); x++) {
            putchar(*pst);
        }
        putchar('\n');
    }
}

int main(void) {
    char ch = '\0';
    int row = 0,cols = 0;
    input_c(&ch);
    input_n(&row,&cols);
    echo(&ch,&row,&cols);
    return 0;
}