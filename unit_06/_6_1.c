/*6.6 编程练习 第1题

编写一个程序，创建一个包含 26 个元素的数组，
并在其中存储 26 个小写字母。然后打印数组的所有内容。*/

#include <stdio.h>

int main(void)
{
    int len = 26;
    char alphabet[len];

    for (int i = 0; i < len; i++)
    {
        alphabet[i] = 'a' + i;
    }

    for (int i = 0; i < len; i++)
    {
        printf("%c ", alphabet[i]);
    }
    return 0;
}