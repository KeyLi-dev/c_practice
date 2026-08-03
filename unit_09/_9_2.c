#include <stdio.h>

void echo_ch(char *pst,int x,int y) {
    puts("请输入一个字符: ");
    scanf(" %c",pst);

    for (int i = 0; i < x; i++) {
        for (int i = 0; i < y; i++)
            putchar(*pst);
        putchar('\n');
    }
}

void input_num(int *pst,int *pst1) {
    puts("请输入两个数字，代表待打印字符的行数和列数: ");
    scanf("%d %d",pst,pst1);
}

int main(void) {
    char ch = '0';
    int x = 0;
    int y = 0;
    input_num(&x,&y);
    echo_ch(&ch,&x,&y);
    return 0;
}