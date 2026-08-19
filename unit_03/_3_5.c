/*编程练习第5题

一年大约有 3.156×10^7 秒。编写一个程序，提示用户输入年龄，
然后显示该年龄对应的秒数。

要求：

1. 使用宏定义 SEC_PER_YEAR 表示一年的秒数 3.156×10^7；

2. 使用浮点类型存储年龄、秒数；

3. 提示用户输入年龄，读取数据完成计算；

4. 输出：打印年龄，同时打印换算出来的总秒数，用科学计数法输出秒数。

示例效果：
Enter how many years old you are:20
You are: 20.0 years old.
And you are 6.312000e+08 seconds old, too.*/

#include <stdio.h>

#define YEAR 12
#define SEC_PER_YEAR 3.156e7f

int input_age(int *const age,int *const month) {
    puts("告诉我你的年龄: ");
    if (scanf("%d",age) != 1) {
        return 1;
    }
    puts("告诉我处于此年龄段几个月了: ");
    if (scanf("%d",month) != 1 || *month < 0 || *month > 12) {
        return 1;
    } 
    return 0;
}

float calculate_seconds(int age, int month) {
    float total_age = 0.0f;
    float time = 0.0f;
    time = (float)month / YEAR;
    total_age = ((float)age + time) * SEC_PER_YEAR;
    return total_age;
}

int main(void) {
    int age = 0;
    int month = 0;
    float total_age = 0.0f;

    if (input_age(&age,&month) == 1) {
        puts("输入错误!");
        return 1;
    }
    total_age = calculate_seconds(age, month);
    printf("You are: %.1f years old.\n", (float)age);
    printf("And you are %.6e seconds old, too.\n", total_age);
    return 0;
}

//0代表成功，1代表失败，或者更准确的说，非零代表失败，尽量不要使用负一!