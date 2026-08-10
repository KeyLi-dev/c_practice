/*编程练习第2题原题：

使用嵌套循环，按下面的格式打印字符：
$
$$
$$$
$$$$
$$$$$*/

#include <stdio.h>

int main(void) {
    int i;
    for (i = 1; i <= 5; i++) {
        for (int x = 0; x < i; x++)
            putchar('$');
        putchar('\n');
    }
    return 0;
}