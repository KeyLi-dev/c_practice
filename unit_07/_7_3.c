#include <stdio.h>
// 你自己写的eat_c清空缓冲区函数，我直接内置进来，避免头文件缺失报错
static inline void eat_c(void) {
    while (getchar() != '\n');
}

#define INDEX 82

// ========== 错误1修正：C语言结构体内部不能初始化成员，只能外部初始化 ==========
struct value {
    int arr[INDEX];
    int odd_arr[INDEX];
    int even_arr[INDEX];
    int odd_cnt;
    int even_cnt;
    float avg_even;
    float avg_odd;
} values; // 全局结构体变量

// 输入函数：改用一级指针即可，没必要强行二级指针增加复杂度
int input_num (struct value *pst) {
    int count = 0;
    puts("请输入任意数量整数 空格分隔");
    puts("我会对他们进行奇数偶数分类");
    puts("0 不算! 输入'0'退出输入!");

    while (1) {
        int temp;
        if (scanf("%d", &temp)) {
            if (temp == 0) break;

            // 存入结构体数组（数组名不能arr++，要用下标存储）
            pst->arr[count] = temp;
            count++;
        }
        else {
            puts("输入错误，退出输入！");
            eat_c();
            break;
        }
    }
    return count;
}

// 奇偶统计分类函数
void evod_count(struct value *pst, int n) {
    // ========== 两种结构体指针访问方式对照 ==========
    // 写法1：箭头 -> （最常用）
    pst->odd_cnt = 0;
    pst->even_cnt = 0;

    // 写法2：(*指针).点号 等价写法（注释起来对照看）
    // (*pst).odd_cnt = 0;
    // (*pst).even_cnt = 0;

    for (int i = 0; i < n; i++) {
        if (pst->arr[i] % 2 == 0) {
            // 偶数
            pst->even_arr[pst->even_cnt] = pst->arr[i];
            pst->even_cnt++;
        }
        else {
            // 奇数（不要嵌套多余for循环，会覆盖数据）
            pst->odd_arr[pst->odd_cnt] = pst->arr[i];
            pst->odd_cnt++;
        }
    }
}

// 计算偶数平均值
void avg_even_fun(struct value *pst) {
    if (pst->even_cnt == 0) { // 边界判断：防止除0错误
        pst->avg_even = 0.0f;
        return;
    }
    float sum = 0.0f;
    for (int i = 0; i < pst->even_cnt; i++) {
        sum += pst->even_arr[i];
    }
    pst->avg_even = sum / pst->even_cnt; // 错误修正：不是/2，是除以总个数
}

// 计算奇数平均值
void avg_odd_fun(struct value *pst) {
    if (pst->odd_cnt == 0) {
        pst->avg_odd = 0.0f;
        return;
    }
    float sum = 0.0f;
    for (int i = 0; i < pst->odd_cnt; i++) {
        sum += pst->odd_arr[i];
    }
    pst->avg_odd = sum / pst->odd_cnt;
}

int main(void) {
    int counts = 0;
    struct value *pointer = &values; // 结构体一级指针

    // 初始化结构体计数、平均值成员（弥补结构体不能内部初始化的问题）
    pointer->odd_cnt = 0;
    pointer->even_cnt = 0;
    pointer->avg_even = 0.0f;
    pointer->avg_odd = 0.0f;

    counts = input_num(pointer);
    evod_count(pointer, counts);
    avg_even_fun(pointer);
    avg_odd_fun(pointer);

    // 打印结果
    printf("你一共输入了 %d 个整数 其中偶数有 %d 个 奇数有 %d 个\n",
           counts, pointer->even_cnt, pointer->odd_cnt);
    printf("偶数平均值为 %.2f 奇数平均值为 %.2f\n",
           pointer->avg_even, pointer->avg_odd);

    return 0;
}