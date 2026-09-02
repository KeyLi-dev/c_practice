/*第8题原题

编写一个程序，要求用户输入两个浮点数，并打印两数之差除以两数之积的结果。
在用户输入非数字之前，程序应循环处理用户输入的每对值。*/

#include <stdio.h>

static inline void flush_stdin(void)
{
    while (getchar() != '\n')
    {
        ;
    }
}

/* 计算：(v1‑v2) / (v1*v2) */
static inline float calculate(float value1, float value2)
{
    return (value1 - value2) / (value1 * value2);
}

void input_float(float *const value1, float *const value2)
{
    int temp = 0;
    puts("请输入两个浮点数：");
    while (1)
    {
        temp = scanf("%f %f", value1, value2);
        if (temp != 2)
        {
            puts("输入结束。");
            flush_stdin();
            break;
        }
        else if (temp == 2)
        {
            /* 增加除数不能为0判断 */
            if ((*value1) * (*value2) == 0.0f)
            {
                puts("错误:两数乘积为0,不能计算!");
                flush_stdin();
                continue;
            }
            printf("两数之差除以两数之积的结果为：%.2f\n", calculate(*value1, *value2));
            puts("请输入两个浮点数：");
        }
    }
}

int main(void)
{
    float value1 = 0.0f;
    float value2 = 0.0f;
    input_float(&value1, &value2);
    return 0;
}