#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"

NODE *root = NULL;

int main() {
    int choice, accNo;
    float amount;
    char name[50], type[10];

    while (1) {
        printf("\n=== BANK MANAGEMENT SYSTEM ===\n");
        printf("1. Insert Account\n2. Deposit\n3. Withdraw\n4. Balance Enquiry\n5. Search\n6. Delete\n7. Display\n0. Exit\nChoice: ");
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
        case 0:
            printf("Goodbye!\n");
            return 0;
        }
    }
    return 0;
}
