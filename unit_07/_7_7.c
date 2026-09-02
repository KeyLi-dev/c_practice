#include <stdio.h>

#define PAY_RATE1 8.75
#define PAY_RATE2 9.33
#define PAY_RATE3 10.00
#define PAY_RATE4 11.20

#define OVERTIME_HOURS 40.0
#define OVERTIME_MULTIPLIER 1.5

#define TAX_BRACKET1 300.0
#define TAX_RATE1 0.15
#define TAX_BRACKET2 150.0
#define TAX_RATE2 0.20
#define TAX_RATE3 0.25

int printMenu(void)
{
    int choice;

    while (1) {
        printf("*****************************\n");
        printf("Enter the number corresponding to the desired pay rate or action\n");
        printf("1) $8.75/hr\n");
        printf("2) $9.33/hr\n");
        printf("3) $10.00/hr\n");
        printf("4) $11.20/hr\n");
        printf("5) Quit\n");
        printf("*****************************\n");
        printf("Please enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                ;
            }
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        if (choice >= 1 && choice <= 5) {
            return choice;
        }

        printf("Invalid choice. Please select a number between 1 and 5.\n");
    }
}

double inputHours(void)
{
    double hours;

    while (1) {
        printf("Please enter the number of hours worked in a week: ");
        if (scanf("%lf", &hours) != 1) {
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {
                ;
            }
            printf("Invalid input. Please enter a valid number for hours.\n");
            continue;
        }

        if (hours < 0.0) {
            printf("Hours cannot be negative. Please try again.\n");
            continue;
        }

        return hours;
    }
}

double calculateSalary(double payRate, double hours)
{
    double regularPay;
    double overtimePay = 0.0;

    if (hours <= OVERTIME_HOURS) {
        regularPay = hours * payRate;
    } else {
        regularPay = OVERTIME_HOURS * payRate;
        overtimePay = (hours - OVERTIME_HOURS) * payRate * OVERTIME_MULTIPLIER;
    }

    return regularPay + overtimePay;
}

double calculateTax(double salary)
{
    double tax = 0.0;

    if (salary <= TAX_BRACKET1) {
        tax = salary * TAX_RATE1;
    } else if (salary <= (TAX_BRACKET1 + TAX_BRACKET2)) {
        tax = TAX_BRACKET1 * TAX_RATE1 + (salary - TAX_BRACKET1) * TAX_RATE2;
    } else {
        tax = TAX_BRACKET1 * TAX_RATE1 + TAX_BRACKET2 * TAX_RATE2 +
              (salary - TAX_BRACKET1 - TAX_BRACKET2) * TAX_RATE3;
    }

    return tax;
}

int main(void)
{
    int choice;
    double hours;
    double payRate = 0.0;
    double salary;
    double tax;
    double netIncome;

    while (1) {
        choice = printMenu();

        if (choice == 5) {
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        switch (choice) {
            case 1:
                payRate = PAY_RATE1;
                break;
            case 2:
                payRate = PAY_RATE2;
                break;
            case 3:
                payRate = PAY_RATE3;
                break;
            case 4:
                payRate = PAY_RATE4;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                continue;
        }

        hours = inputHours();
        salary = calculateSalary(payRate, hours);
        tax = calculateTax(salary);
        netIncome = salary - tax;

        printf("Gross Salary: $%.2f\n", salary);
        printf("Taxes: $%.2f\n", tax);
        printf("Net Income: $%.2f\n", netIncome);
    }

    return 0;
}