#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "add.h"

NODE *search(NODE *root, int acc) {
    if (root != NULL) {
        if (acc < root->accNo) return search(root->left, acc);
        else if (acc > root->accNo) return search(root->right, acc);
        else {
            printf("\n%d\t%s\t%s\t%f\n", root->accNo, root->name, root->type, root->balance);
            return root;
        }
    }
    printf("\nResult not found.\n");
    return NULL;
}

NODE* insertAccount(NODE *root, int accNo, char name[], char type[], float amount) {
    if (root == NULL) {
        NODE *newNode = (NODE*)malloc(sizeof(NODE));
        newNode->accNo = accNo; strcpy(newNode->name, name); strcpy(newNode->type, type);
        newNode->balance = amount; newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (accNo < root->accNo) root->left = insertAccount(root->left, accNo, name, type, amount);
    else if (accNo > root->accNo) root->right = insertAccount(root->right, accNo, name, type, amount);
    return root;
}

NODE* minValueNode(NODE* node) {
    while (node && node->left != NULL) node = node->left;
    return node;
}

NODE* deleteAccount(NODE* root, int accNo) {
    if (root == NULL) return root;
    if (accNo < root->accNo) root->left = deleteAccount(root->left, accNo);
    else if (accNo > root->accNo) root->right = deleteAccount(root->right, accNo);
    else {
        if (root->left == NULL) { NODE* temp = root->right; free(root); return temp; }
        else if (root->right == NULL) { NODE* temp = root->left; free(root); return temp; }
        NODE* temp = minValueNode(root->right);
        root->accNo = temp->accNo; strcpy(root->name, temp->name); strcpy(root->type, temp->type); root->balance = temp->balance;
        root->right = deleteAccount(root->right, temp->accNo);
    }
    return root;
}

void deposit(NODE *root, int accNo, float amount) {
    NODE *acc = search(root, accNo);
    if (acc) { acc->balance += amount; printf("Deposited %.2f. New balance: %.2f\n", amount, acc->balance); }
}

void withdraw(NODE *root, int accNo, float amount) {
    NODE *acc = search(root, accNo);
    if (acc && acc->balance >= amount) { acc->balance -= amount; printf("Withdrew %.2f. New balance: %.2f\n", amount, acc->balance); }
    else printf("Insufficient balance\n");
}

void displayAccountDetails(NODE *root, int accNo) {
    NODE *acc = search(root, accNo);
    if (acc) printf("Acc:%d Name:%s Type:%s Balance:%.2f\n", acc->accNo, acc->name, acc->type, acc->balance);
}

void display(NODE *root) {
    if (root) {
        display(root->left);
        printf("Acc:%d %s %s %.2f\n", root->accNo, root->name, root->type, root->balance);
        display(root->right);
    }
}
