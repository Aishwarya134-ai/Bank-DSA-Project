#ifndef ADD_H
#define ADD_H

typedef struct node
{
    int accNo;
    char name[20];
    char type[10];
    float balance;
    struct node *left;
    struct node *right;
} NODE;

NODE* insertAccount(NODE *root, int accNo, char name[], char type[], float amount);
NODE* deleteAccount(NODE* root, int accNo); 
NODE *search(NODE *root, int acc);
void deposit(NODE *root, int accNo, float amount);
void withdraw(NODE *root, int accNo, float amount);
void displayAccountDetails(NODE *root, int accNo);
void display(NODE *root);

/* ---- Loan part starts here ---- */

typedef struct loan {
    int loanId;
    int accNo;
    float amount;
    float rate;          // interest rate %
    int months;          // duration
    struct loan *next;
} LOAN;

void addLoan(LOAN **head, int accNo, float amount, float rate, int months);
void displayLoans(LOAN *head);
void displayLoansForAccount(LOAN *head, int accNo);

/* ---- Loan part ends here ---- */

#endif
