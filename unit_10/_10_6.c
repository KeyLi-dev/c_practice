#include <stdio.h>

#define INDEX 82

struct message {
    double doub_value[INDEX];
    double doub_rev_value[INDEX];
    unsigned int count;
} messages = {
    .count = 0,
    .doub_value = {0.0},
    .doub_rev_value = {0.0}
};

static inline void eat_c(void) {
    while ((getchar()) != '\n')         //增加圆括号，提升优先级
        ;
}

void stderr_fun(int *pst) {
    char temp_val;
    if (*pst != 1) {
        puts("输入错误!");
        puts("是否继续输入? (y or n)");
        scanf(" %c",&temp_val);
        if (temp_val == 'y') {
            eat_c();
            temp_val = 1;
        }
        else {                      //有花括号，所以与最近的if配对;
            eat_c();
            temp_val = 0;
            puts("Bye!");
        }
    }
}

void input_value(struct message *pst) {
    int temp;
    int i = 0;
    puts("请输入任意数量浮点值 空格分隔: "); 
    while ((temp = scanf("%lf",pst->doub_value[i])) == 1) {
        i++;
        (*pst).count++;
        if (temp != 1) {
            stderr_fun(&temp);
            continue;
        }
    }
}

void rev_arr(struct message *pst) {
    for (int i = 0,l = (*pst).count; l > (-1); l--,i++) {
        pst->doub_rev_value[i] = pst->doub_value[l];
    }
}

void echo_arr(struct message *pst) {
    puts("doub_value");
    for (int i = 0; i < pst->count; i++) {
        printf("%.2f\t",pst->doub_value[i]);
        fflush(stdout);
    }
    putchar('\n');
    puts("doub_rev_value");
    for (int i = 0; i < (*pst).count; i++) {
        printf("%.2f\t",pst->doub_rev_value[i]);
        fflush(stdout);
    }
}

int main(void) {
    struct message *pointer = &messages;
    input_value(pointer);
    rev_arr(pointer);
    echo_arr(pointer);
    return 0;
}


/*#include <stdio.h>

#define INDEX 82

struct message {
    double doub_value[INDEX];
    double doub_rev_value[INDEX];
    unsigned int count;
} messages = {
    .count = 0,
    .doub_value = {0.0},
    .doub_rev_value = {0.0}
};

static inline void eat_c(void) {
    while ((getchar()) != '\n');
}

// 返回值：1继续输入  0终止输入
int stderr_fun(void) {
    char temp_val;
    puts("输入格式错误!");
    puts("是否继续输入? (y or n)");
    scanf(" %c",&temp_val);
    eat_c();
    if (temp_val == 'y') {
        return 1;
    } else {
        puts("Bye!");
        return 0;
    }
}

void input_value(struct message *pst) {
    puts("请输入任意数量浮点值 空格分隔，输入字母结束输入: ");
    while (1) {
        int temp = scanf("%lf", &pst->doub_value[pst->count]);
        if (temp == 1) {
            pst->count++;
            // 防止数组越界
            if(pst->count >= INDEX) break;
        } else {
            // 输入错误，调用错误处理
            eat_c();
            int flag = stderr_fun();
            if(flag == 0) break;
        }
    }
}

void rev_arr(struct message *pst) {
    int len = pst->count;
    for (int i = 0; i < len; i++) {
        pst->doub_rev_value[i] = pst->doub_value[len - 1 - i];
    }
}

void echo_arr(struct message *pst) {
    puts("原始数组 doub_value：");
    for (int i = 0; i < pst->count; i++) {
        printf("%.2f\t", pst->doub_value[i]);
    }
    putchar('\n');

    puts("倒序数组 doub_rev_value：");
    for (int i = 0; i < pst->count; i++) {
        printf("%.2f\t", pst->doub_rev_value[i]);
    }
    putchar('\n');
}

int main(void) {
    struct message *pointer = &messages;
    input_value(pointer);
    rev_arr(pointer);
    echo_arr(pointer);
    return 0;
}*/
