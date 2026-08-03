#include <stdio.h>

#define INDEX 82
typedef unsigned int un_in;

// 结构体：存储姓氏、名字
struct message {
    char name_arr[INDEX];    // 拼接完整姓名
    char last_arr[INDEX];    // 姓氏
    char first_arr[INDEX];   // 名字
    un_in last_len;
    un_in first_len;
    un_in name_len;
} messages = {
    .last_len = 0,
    .first_len = 0,
    .name_len = 0
};

// 清理输入缓冲区
static inline void eat_c(void) {
    while (getchar() != '\n');
}

// 获取姓氏
void input_last(struct message *pst) {
    puts("请输入你的姓氏：");
    scanf("%s", pst->last_arr);
    eat_c();
    // 手动统计姓氏长度
    un_in i = 0;
    while(pst->last_arr[i] != '\0'){
        i++;
    }
    pst->last_len = i;
}

// 获取名字
void input_first(struct message *pst) {
    puts("请输入你的名字：");
    scanf("%s", pst->first_arr);
    eat_c();
    un_in i = 0;
    while(pst->first_arr[i] != '\0'){
        i++;
    }
    pst->first_len = i;
}

// 拼接：姓氏 + 空格 + 名字 存入name_arr
void join_name(struct message *pst) {
    un_in pos = 0;
    // 拷贝姓氏
    for (un_in i = 0; i < pst->last_len; i++) {
        pst->name_arr[pos++] = pst->last_arr[i];
    }
    pst->name_arr[pos++] = ' '; // 姓氏和名字中间添加空格
    // 拷贝名字
    for (un_in i = 0; i < pst->first_len; i++) {
        pst->name_arr[pos++] = pst->first_arr[i];
    }
    pst->name_arr[pos] = '\0'; // 【修改4】追加字符串终止符
    pst->name_len = pos;
}

// 打印完整姓名（逐字符输出）
static inline void echo_arr(struct message *pst) {
    for (un_in i = 0; i < pst->name_len; i++)
        printf("%c", pst->name_arr[i]);
}

// 打印姓氏
static inline void print_last(struct message *pst) {
    for (un_in i = 0; i < pst->last_len; i++) {
        printf("%c", pst->last_arr[i]);
    }
}

// 打印名字
static inline void print_first(struct message *pst) {
    for (un_in i = 0; i < pst->first_len; i++) {
        printf("%c", pst->first_arr[i]);
    }
}

int main(void) {
    struct message *pointer = &messages;
    input_last(pointer);
    input_first(pointer);
    join_name(pointer);  //【修改5】确保调用拼接函数

    printf("=====按照题目要求输出=====\n");
    // ①调用一次printf，姓名一行
    printf("%s\n", pointer->name_arr);

    // ②调用一次printf，姓名分两行
    printf("%s\n%s\n", pointer->last_arr, pointer->first_arr);

    // ③两次printf，姓名打印在同一行
    print_last(pointer);
    putchar(' ');
    print_first(pointer);
    putchar('\n');

    return 0;
}