#include <stdio.h>
#include <stdlib.h>
#include "add.h"

void addLoan(LOAN **head, int accNo, float amount, float rate, int months) {
    LOAN *newNode = (LOAN *)malloc(sizeof(LOAN));
    static int nextId = 1;

    newNode->loanId = nextId++;
    newNode->accNo = accNo;
    newNode->amount = amount;
    newNode->rate = rate;
    newNode->months = months;
    newNode->next = *head;
    *head = newNode;

    printf("Loan %d created for account %d, amount %.2f\n",
           newNode->loanId, accNo, amount);
}

void displayLoans(LOAN *head) {
    if (!head) {
        printf("No loans found.\n");
        return;
    }
    LOAN *temp = head;
    while (temp) {
        printf("LoanID:%d Acc:%d Amount:%.2f Rate:%.2f%% Tenure:%d months\n",
               temp->loanId, temp->accNo, temp->amount,
               temp->rate, temp->months);
        temp = temp->next;
    }
}

void displayLoansForAccount(LOAN *head, int accNo) {
    int found = 0;
    LOAN *temp = head;
    while (temp) {
        if (temp->accNo == accNo) {
            printf("LoanID:%d Amount:%.2f Rate:%.2f%% Tenure:%d months\n",
                   temp->loanId, temp->amount, temp->rate, temp->months);
            found = 1;
        }
        temp = temp->next;
    }
    if (!found) {
        printf("No loans for account %d\n", accNo);
    }
}
