/*修改后的编程练习第7题

1英寸等于2.54厘米，1米 = 100厘米。编写一个程序，提示用户输入身高（单位：厘米）
然后分别以厘米、米、英寸为单位输出显示该身高。

要求：

1. 使用宏定义保存换算系数：1英寸=2.54厘米；

2. 使用浮点型变量存储身高数据；

3. 程序要提示用户输入，读取数据，完成换算，最后打印三种单位的结果。
举例：用户输入 175
输出示例：
你的身高：175.00 厘米，也就是 1.75 米，折合 68.90 英寸。*/

#include <stdio.h>

#define INCH 2.54

int input(float *const pst) {
    puts("请输入你的身高（单位：厘米）：");
    if (scanf("%f",pst) != 1) {
        puts("输入错误！");
        return -1;
    }
    return 0;
}

void print(const float height) {
    printf("你的身高: %.2f 厘米\n",height);
    printf("也就是: %.2f 米\n",height/100);
    printf("折合: %.2f 英寸\n",height/INCH);
}

int main(void) {
    float height = 0.0f;
    int ret = 0;
    ret = input(&height);
    if (ret != 0) {
        return -1;
    }
    print(height);
    return 0;
}