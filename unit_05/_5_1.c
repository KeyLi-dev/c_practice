/*题目要求

编写一个程序，把用分钟表示的时间转换成用小时和分钟表示的时间。

1. 使用 #define 或者 const 创建一个常量，用来代表60（一小时等于60分钟）；

2. 通过 while 循环，让用户可以重复输入分钟数值进行转换；

3. 循环终止条件：当用户输入小于或等于 0 的数值时，停止循环，结束程序。*/ 

#include <stdio.h>
#include <iso646.h>
#include <stdbool.h>
//不可修改指针的指向，不可修改指针指向的值;
//浮点数除法可以避免整数除法的截断现象;
//练习代码，练习知识点为主，一开始想使用double类型，后来发现double类型不可取模，于是使用了typedef;
typedef signed int doubl;

void input_fun(doubl *pst,const doubl * const pst_val) {
    do {
        puts("开始!");  //%d在scanf()里只会读取十进制，%i就不一样了;
        if (scanf("%d",pst) != 1 or !((*pst) > 0) || (*pst) == 0) {   //注意优先级问题;
            puts("程序退出!");
            break;
        }
        doubl hour = 0,min = 0;
        if (*pst > *pst_val) {
            hour = (*pst) / (*pst_val);
            min = (*pst) % (*pst_val);
            printf("你的输入 %2i 换算为小时 %2i 剩余分钟 %2i\n",*pst,hour,min);
        }
        //else与距离最近且有花括号的if配对
        else {
            min = ((*pst) % (*pst_val));     //取模，被除数小于除数，返回被除数本身,取模的两种返回值;
            puts("不足一小时!");
            printf("%2i分钟\n",min); 
        }
    } while (true);
}

int main(void) {
    doubl min_val = 0;
    doubl doub_value = 60;
    input_fun(&min_val,&doub_value);
    return 0;
}
//浮点数不可以使用取模符号，我开始不知道，目前更改为有符号整型;