#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"

NODE *root = NULL;
LOAN *loanHead = NULL;

int main() {
    int choice, accNo;
    float amount;
    char name[50], type[10];

    while (1) {
        printf("\n=== BANK MANAGEMENT SYSTEM ===\n");
       printf("1. Insert Account\n");
       printf("2. Deposit\n");
printf("3. Withdraw\n");
printf("4. Balance Enquiry\n");
printf("5. Search\n");
printf("6. Delete\n");
printf("7. Display\n");
printf("8. Add Loan\n");
printf("9. View All Loans\n");
printf("10. View Loans for Account\n");
printf("0. Exit\nChoice: ");

        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Account No: "); scanf("%d", &accNo);
            printf("Name: "); scanf("%s", name);
            printf("Type: "); scanf("%s", type);
            printf("Amount: "); scanf("%f", &amount);
            root = insertAccount(root, accNo, name, type, amount);
            break;
        case 2:
            printf("Account No: "); scanf("%d", &accNo);
            printf("Amount: "); scanf("%f", &amount);
            deposit(root, accNo, amount);
            break;
        case 3:
            printf("Account No: "); scanf("%d", &accNo);
            printf("Amount: "); scanf("%f", &amount);
            withdraw(root, accNo, amount);
            break;
        case 4:
            printf("Account No: "); scanf("%d", &accNo);
            displayAccountDetails(root, accNo);
            break;
        case 5:
            printf("Account No: "); scanf("%d", &accNo);
            search(root, accNo);
            break;
        case 6:
            printf("Account No: "); scanf("%d", &accNo);
            root = deleteAccount(root, accNo);
            break;
        case 7:
            display(root);
            break;
        case 8: {
    int accNo, months;
    float amount, rate;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    printf("Enter loan amount: ");
    scanf("%f", &amount);
    printf("Enter interest rate (%%): ");
    scanf("%f", &rate);
    printf("Enter duration in months: ");
    scanf("%d", &months);
    addLoan(&loanHead, accNo, amount, rate, months);
    break;
}
case 9:
    displayLoans(loanHead);
    break;
case 10: {
    int accNo;
    printf("Enter account number: ");
    scanf("%d", &accNo);
    displayLoansForAccount(loanHead, accNo);
    break;
}
    
        case 0:
            printf("Goodbye!\n");
            return 0;
        }
    }
    return 0;
}
