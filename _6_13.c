#include <stdio.h>

#define INDEX 8

typedef unsigned int un_in;

void w_arr(un_in *pst,int n) {
    *(pst+0) = 2;
    
    for (int i = 1;i < n;i++) {
        *(pst+i) = *(pst +i -1) *2;
    }
}

void echo_arr(un_in *pst,int n) {
    int i = 0;
    do {
        printf("%u\t",*(pst+i));
        i++;
        fflush(stdout);
    }
    while (i < n);
}

int main(void) {
    un_in arr[INDEX] = {0};
    w_arr(arr,INDEX);
    echo_arr(arr,INDEX);
    return 0;
}