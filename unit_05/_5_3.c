/*第3题

3. 编写一个程序，提示用户输入天数，然后将其转换成周数和天数。
例如，如果用户输入 18，则转换成2周4天，以下面的格式显示结果。
18 days are 2 weeks, 4 days
*/

#include <stdio.h>
#include <errno.h>
#include <limits.h>
#include <stdlib.h>

#define DAYS_IN_WEEK 7

static void print_conversion(int days) {
    printf("%d days are %d weeks, %d days\n",
           days, days / DAYS_IN_WEEK, days % DAYS_IN_WEEK);
}

int main(void) {
    char input[100];

    puts("Enter the number of days (negative to quit):");
    while (fgets(input, sizeof input, stdin) != NULL) {
        char *end = NULL;
        long days;

        errno = 0;
        days = strtol(input, &end, 10);

        if (end == input || (*end != '\n' && *end != '\0') || errno == ERANGE ||
            days > INT_MAX || days < INT_MIN) {
            puts("Please enter a valid integer.");
        } else if (days < 0) {
            break;
        } else {
            print_conversion((int) days);
        }

        puts("Enter another number of days (negative to quit):");
    }

    return 0;
}