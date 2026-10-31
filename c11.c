#include <stdio.h>

#define MAX 100

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void createAccount(struct Account a[], int *n) {
    if (*n >= MAX) {
        printf("Account limit reached!\n");
        return;
    }

    printf("Enter account number: ");
    scanf("%d", &a[*n].accountNumber);

    printf("Enter customer name (no spaces): ");
    scanf("%49s", a[*n].name);

    printf("Enter initial deposit: ");
    scanf("%f", &a[*n].balance);

    if (a[*n].balance < 0) {
        printf("Invalid deposit amount!\n");
        return;
    }

    (*n)++;
    printf("Account created successfully!\n");
}

int findAccount(struct Account a[], int n, int number) {
    for (int i = 0; i < n; i++) {
        if (a[i].accountNumber == number)
            return i;
    }

    return -1;
}

void depositMoney(struct Account a[], int n) {
    int number, index;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &number);

    index = findAccount(a, n, number);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Enter a valid positive amount!\n");
        return;
    }

    a[index].balance += amount;

    printf("Deposit successful!\n");
    printf("Current balance: %.2f\n",
           a[index].balance);
}

void withdrawMoney(struct Account a[], int n) {
    int number, index;
    float amount;

    printf("Enter account number: ");
    scanf("%d", &number);

    index = findAccount(a, n, number);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Enter a valid positive amount!\n");
        return;
    }

    if (amount > a[index].balance) {
        printf("Insufficient balance!\n");
        return;
    }

    a[index].balance -= amount;

    printf("Withdrawal successful!\n");
    printf("Remaining balance: %.2f\n",
           a[index].balance);
}

void checkBalance(struct Account a[], int n) {
    int number, index;

    printf("Enter account number: ");
    scanf("%d", &number);

    index = findAccount(a, n, number);

    if (index == -1) {
        printf("Account not found!\n");
        return;
    }

    printf("Account holder: %s\n", a[index].name);
    printf("Account number: %d\n",
           a[index].accountNumber);
    printf("Available balance: %.2f\n",
           a[index].balance);
}

void displayAccounts(struct Account a[], int n) {
    if (n == 0) {
        printf("No accounts available.\n");
        return;
    }

    printf("\n===== ALL BANK ACCOUNTS =====\n");

    for (int i = 0; i < n; i++) {
        printf("\nAccount number: %d\n",
               a[i].accountNumber);
        printf("Name: %s\n", a[i].name);
        printf("Balance: %.2f\n", a[i].balance);
    }
}

int main() {
    struct Account accounts[MAX];
    int count = 0;
    int choice;

    do {
        printf("\n===== BANK MANAGEMENT SYSTEM =====\n");
        printf("1. Create Account\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Check Balance\n");
        printf("5. Display All Accounts\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount(accounts, &count);
                break;

            case 2:
                depositMoney(accounts, count);
                break;

            case 3:
                withdrawMoney(accounts, count);
                break;

            case 4:
                checkBalance(accounts, count);
                break;

            case 5:
                displayAccounts(accounts, count);
                break;

            case 6:
                printf("Thank you for using the system!\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
                continue;
        }

    } while (choice != 6);

    return 0;
}
