/*编程练习第2题 题目原文

题目要求：

编写一个程序，要求提示输入一个 ASCII 码值(如 66),然后打印输入的字符.
*/
#include <stdio.h>

typedef unsigned int un_in;

static un_in ascii_val = 0;

static inline void eat_c(void) {
    while (getchar() != '\n')
        ;
}

void input_val(un_in *pst) {
    const un_in max_value = 127;
    puts("请输入一个正整数: ");
    scanf("%u",pst);
    eat_c();
    if (*pst <= max_value) {
        printf("已成功存入 %u\n",*pst);
    }
    else {
        puts("quit!");
    }
}

static inline void echo_ascii(un_in *pst) {
    printf("%u 对应的ASCII字符为 %c\n",*pst,*pst);
}

void again(void) {
    char ch;
    statr:puts("再来一次吗?");      //goto模拟循环，合理使用goto
    puts("y or n");
    scanf(" %c",&ch);
    if (ch == 'y') {
        input_val(&ascii_val);
        echo_ascii(&ascii_val);
        goto statr;
       } 
    else {
        puts("quit!");
    }
}

int main(void) {
    input_val(&ascii_val);
    echo_ascii(&ascii_val);
    again();
    return 0;
}