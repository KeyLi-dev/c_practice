#include <stdio.h>

#define INDEX 81

void input_s(char *pst) {
    puts("Go!");
    int ch = 0;
    while ((ch = getchar()) != '#'){
        *pst = ch;
        pst++;
    }
        *pst = '\0';
}

int ch_function(void) {
    char ch_arr[INDEX] = {0};
    input_s(ch_arr);
    char *pst = ch_arr;
    int num = 0;

    for (int i = 0; *(pst+i) != '\0'; i++) {
        if (*(pst+i) == 'e' && *(pst+i+1) == 'i')
            num++;
    }

    return num;
}

signed int main(void) {
    int num = ch_function();
    printf("ei 出现了 %i次\n",num);
    return 0;
}

/*#include <stdio.h>

int main(void) {
    int count = 0;
    int halfpair = 0;
    int = ch;
    puts("Please input chars (# for exit): ");
    while ((ch = getchar()) != '#') {
        switch (ch) {
            case 'e' : halfpair = 1; break;
            case 'i' : 
                if (halfpair == 1) {
                    count++;
                    halfpair = 0;
                }
                break;
            default : halfpair = 0;
        }
    }
    printf("ei 出现的次数 %i次\n",count);
    return 0;
}*/