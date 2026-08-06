/*第7章 编程练习第5题 完整题目

使用 switch 语句重做编程练习4。
（功能和第4题完全一致：读取输入，读到#字符时停止。
用感叹号替换句号，用两个感叹号替换原来的感叹号，最后报告替换了多少次，
只是把if-else结构换成switch结构实现。）*/

#include <stdio.h>

int main(void) {
    int ch = EOF;
    int count = 0;
    while ((ch = getchar()) != '#') {
        switch(ch) {
            case '.' : 
                putchar('!');
                count++;
                break;
            case '!' :
                putchar('!');
                putchar('!');
                count++;
                break;
            default :
                putchar(ch);
        }
    }
    printf("%d\n",count);
    return 0;
}