#include <stdio.h>

#define INDEX 81

typedef unsigned int un_in;

int input_num(un_in *pst) {
    int count = 0;
    puts("Please enter a number: ");
    while (scanf("%u",pst)) {
        pst++;
        count++;
    }
    return count;
}

un_in echo_max_num(void) {
    int count = 0;
    un_in arr[INDEX];
    count = input_num(arr);
    un_in *pst = arr;
    un_in max_num = *(pst+0);

    for (int i = 0; i < count; i++) {
        if (*(pst+i) > max_num){
            max_num = *(pst+i);
            printf("%u\t",*(pst+i));
            fflush(stdout);
        }
        else {
            printf("%u\t",*(pst+i));
            fflush(stdout);
        }
    }
    return max_num;
}

signed int main(void) {
    un_in value = 0;
    value =  echo_max_num();
    printf("max value : %u\n",value);
    return 0;
}