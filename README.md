<<<<<<< HEAD
Bank Account Management System
    Mini Project- C Program
A C-based banking system with BST for accounts and a linked list for loans. It performs the entire CRUD operation on accounts along with the management of loans.

Features:
•	Account Management BSTaa
•	Insert new accounts
•	Search by account number
•	Deposit & Withdraw cash
•	Balance enquiry
•	Delete accounts
•	Display all accounts (in-order traversal)
•	Loan Management (Linked List)
•	Add loans (tied to account number)
•	View all loans
•	View loans for specific account
(It keeps track of the loan ID, amount, interest rate, and duration)

The system uses:
•	C Language
•	Binary Search Tree : Account Records Fast Search
•	Singly Linked List (loans - easy append)
GCC Compiler
      Git Version Control

File Structure:
•	bank-acc-management-sys/
├── add.h          # BST account functions + loan declarations
├── add.c          # BST implementations (insert, delete, etc.)
├── loan.c         # Loan linked list functions
├── main.c         # Menu-driven interface
├── bank.exe       # Compiled executable
└── README.md      # This file

How to run and compile:
   bash
     gcc main.c add.c loan.c -o bank.exe
   bash
      .bak.exe

Test Cases and Menu Actions:

| Option | Action/Menu          | Description                       |
|--------|----------------------|-----------------------------------|
| 1      | Create Account       | New customer account              |
| 2      | Deposit              | Put money into account            |
| 3      | Withdraw             | Take out money(with balance check)|
| 4      | Balance Enquiry      | Account balance enquiry           |
| 5      | Search               | Find account by number            |
| 6      | Delete               |   Remove account                  |
| 7      | Display              | View all accounts (sorted)        |
| 8      | Add Loan             | Create loan for account           |
| 9      | View All Loans       | List every loan                   |
| 10     | See Loans for Account| Loans for specific account        |
| 0      | Quit                 | Exit program                      |
=======
>>>>>>> b557deae82b922f2100fe501924462443a086d4e

