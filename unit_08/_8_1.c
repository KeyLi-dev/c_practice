/*编程练习 第1题

设计一个程序，统计在读到文件结尾之前读取的字符数。*/

#include <stdio.h>

unsigned int count_fun(void) {
    unsigned int count = 0;
    int ch = '\0';
    while ((ch = getchar()) != EOF) {
        count++;
    }
    return count;
}

int main(void) {
    unsigned int count = 0;
    count = count_fun();
    printf("count = %u\n",count);
    return 0;
}