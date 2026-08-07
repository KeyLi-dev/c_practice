/*第10章 编程练习第13题 完整题目

编写一个程序，提示用户输入3组数，每组数包含5个 double 类型的数
假设用户都正确地响应，不会输入非数值数据。该程序完成下列任务：
a. 把用户输入的数据存储在 3×5 数组中；
b. 计算每组（5个）数据的平均值；
c. 计算所有数据的平均值；
d. 找出这15个数据中的最大值；
e. 打印结果。*/

#include <stdio.h>

#define ONE_INDEX 3
#define TWO_INDEX 5
#define SUM_COUNT 15

typedef double doub;

struct number {
    doub arr1[TWO_INDEX];
    doub arr2[TWO_INDEX];
    doub arr3[TWO_INDEX];
    doub arr4[ONE_INDEX][TWO_INDEX];
    doub arr1_avg;
    doub arr2_avg;
    doub arr3_avg;
    doub arr4_avg;
    doub max_value;
} numbers = {
    .arr1 = {0},
    .arr2 = {0},
    .arr3 = {0},
    .arr1_avg = 0.0,
    .arr2_avg = 0.0,
    .arr3_avg = 0.0,
    .arr4_avg = 0.0,
    .max_value = 0.0
};

void input_value(struct number *pst,int two_index) {
    doub *pst1 = pst->arr1;
    doub *pst2 = pst->arr2;
    doub *pst3 = pst->arr3;
    puts("请输入五个浮点值:(第一组数据)" );
    for (int i = 0; i < two_index; i++) {
        scanf("%lf",pst1);
        pst1++;
    }
    puts("请输入五个浮点值:(第二组数据)" );
    for (int i = 0; i < two_index; i++) {
        scanf("%lf",pst2);
        pst2++;
    }
    puts("请输入五个浮点值:(第三组数据)" );
    for (int i = 0; i < two_index; i++) {
        scanf("%lf",pst3);
        pst3++;
    }
    puts("输入完毕!");
}

void sum_arr(struct number *pst,int one_index,int two_index) {
    int i,x;
    for (i = 0; i < one_index; i++) {
        for (x = 0; x < two_index; x++) {
            pst->arr4[i][x] = pst->arr1[x];
        }
        if (i == 1) {
            for (x = 0; x < two_index; x++) {
                pst->arr4[i][x] = pst->arr2[x];
            }
        }
        if (i == 2) {
            for (x = 0; x < two_index; x++) {
                pst->arr4[i][x] = pst->arr3[x];
            }
        }
    }
}

void echo_arr4(struct number *pst,int one_index,int two_index) {
    for (int i = 0; i < one_index; i++) {
        for (int x = 0; x < two_index; x++) {
            printf("%.2f\t",pst->arr4[i][x]);
        }
    }
    fflush(stdout);
}

void arr1_avg(struct number *pst,int two_index) {
    for (int i = 0; i < two_index; i++) {
        pst->arr1_avg += pst->arr1[i];
    }
    pst->arr1_avg /= two_index;
}

void arr2_avg(struct number *pst,int two_index) {
    for (int i = 0; i < two_index; i++) {
        pst->arr2_avg += pst->arr2[i];
    }
    pst->arr2_avg /= two_index;
}

void arr3_avg(struct number *pst,int two_index) {
    for (int i = 0; i < two_index; i++) {
        pst->arr3_avg += pst->arr3[i];
    }
    pst->arr3_avg /= two_index;
}

void arr4_avg(struct number *pst,int one_index,int two_index,int sum_count) {
    for (int i = 0; i < one_index; i++) {
        for (int x = 0; x < two_index; x++) {
            pst->arr4_avg += pst->arr4[i][x];
        }
    }
    pst->arr4_avg /= sum_count;
}

void max_arr4(struct number *pst,int one_index,int two_index) {
    (*pst).max_value = pst->arr4[0][0];
    for (int i = 0; i < one_index; i++) {
        for (int x = 0; x < two_index; x++) {
            if (((*pst).max_value) < (pst->arr4[i][x])) {
                (*pst).max_value = pst->arr4[i][x];
            }
        }
    }
}

int main(void) {
    struct number *pointer = &numbers;

    input_value(pointer,TWO_INDEX);
    sum_arr(pointer,ONE_INDEX,TWO_INDEX);
    puts("以获取用户的输入 合并数组完成.");

    puts("合并后的二维数组内容: ");
    echo_arr4(pointer,ONE_INDEX,TWO_INDEX);

    putchar('\n');
    arr1_avg(pointer,TWO_INDEX);
    printf("数组\'arr1\'内\'5\'元素平均值为: %.2f\n",pointer->arr1_avg);

    arr2_avg(pointer,TWO_INDEX);
    printf("数组\'arr2\'内\'5\'元素平均值为: %.2f\n",(*pointer).arr2_avg);

    arr3_avg(pointer,TWO_INDEX);
    printf("数组\'arr3\'内\'5\'元素平均值为: %.2f\n",(*pointer).arr3_avg);

    arr4_avg(pointer,ONE_INDEX,TWO_INDEX,SUM_COUNT);
    printf("数组\'arr4\'内\'15\'元素平均值为: %.2f\n",pointer->arr4_avg);

    max_arr4(pointer,ONE_INDEX,TWO_INDEX);
    printf("共计\'15\'个浮点元素值 其中最大值为: %.2f\n",pointer->max_value);

    return 0;
    
}