/*第7章 编程练习第1题
编写一个程序，读取输入，读到#字符停止
然后报告读取的空格数、换行符数和所有其他字符的数量。*/

#include <stdio.h>

void input(void) {
    int ch;     //signed char 也可行，但最好不要这样做
    int blank = 0,newline = 0,others = 0;
    while ((ch = getchar()) != '#') {   //注意优先级
        if (ch == ' ')
            blank++;
        else if (ch == '\n')
            newline++;
        else 
            others++;
    }
    printf("读取空格个数:%d 读取换行符个数:%d 其他字符个数:%d\n",blank,newline,others);
}

int main(void) {
    printf("请输入任意个数字符: \n");
    input();
    puts("程序退出.");
    return 0;
}