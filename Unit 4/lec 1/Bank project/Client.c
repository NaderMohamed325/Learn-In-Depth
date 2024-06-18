#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "Client.h"


client *Create_Bank_List() {
    client *temp = malloc(sizeof(client));
    if (!temp) {
        printf("Failed to allocate memory\n");
        return NULL;
    } else {
        printf("Enter the name of the client: ");
        fgets(temp->name, sizeof(temp->name), stdin);
        temp->name[strcspn(temp->name, "\n")] = '\0';
        printf("Enter the password of the client: ");
        fgets(temp->password, sizeof(temp->password), stdin);
        temp->password[strcspn(temp->password, "\n")] = '\0';
        printf("Enter the balance of the client: ");
        scanf("%lf", &temp->balance);
        while (temp->balance < 0) {
            printf("Balance cannot be negative. Enter again: ");
            scanf("%lf", &temp->balance);
        }
        fflush(stdin);
        temp->next = NULL;
        temp->id = 0;

        printf("Waiting");
        for (int i = 0; i < 3; ++i) {
            printf(".");
            sleep(1);
        }
        printf("\n");
        return temp;
    }
}

void Add_newClient(client **head) {
    if (!head) {
        printf("Null bank list \n");
    } else {
        client *temp = malloc(sizeof(client));
        if (!temp) {
            printf("Failed to allocate memory\n");
        } else {
            fflush(stdout);
            fflush(stdin);
            printf("Enter the name of the client: ");
            fgets(temp->name, sizeof(temp->name), stdin);
            temp->name[strcspn(temp->name, "\n")] = '\0';
            printf("Enter the password of the client: ");
            fgets(temp->password, sizeof(temp->password), stdin);
            temp->password[strcspn(temp->password, "\n")] = '\0';
            printf("Enter the balance of the client: ");
            scanf("%lf", &temp->balance);
            while (temp->balance < 0) {
                printf("Balance cannot be negative. Enter again: ");
                scanf("%lf", &temp->balance);
            }
            fflush(stdin);
            temp->next = *head;
            temp->id = (*head)->id + 1;
            *head = temp;

            printf("Waiting");
            for (int i = 0; i < 3; ++i) {
                printf(".");
                sleep(1);
            }
            printf("\n");
        }
    }
}

void display_data(client *head) {
    printf("Client Data:\n");
    printf("Name: %s\n", head->name);
    printf("Password: %s\n", head->password);
    printf("Balance: %.2lf\n", head->balance);
    printf("ID: %d\n", head->id);
    printf("\n");
}

void display_all(client *head) {
    if (!head) {
        printf("No clients in the bank\n");
    } else {
        client *temp = head;
        while (temp && temp->id >= 0) {
            display_data(temp);
            temp = temp->next;
            sleep(2);
        }
    }
}

void Delete_client(client **head, int id) {
    if (!head) {
        printf("Null bank list\n");
    } else {
        client *temp = *head;
        client *prev = NULL;
        while (temp && temp->id != id) {
            prev = temp;
            temp = temp->next;
        }
        if (!temp) {
            printf("Client not found\n");
        } else {
            if (!prev) {
                *head = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(temp);
            printf("Client deleted\n");
        }
    }
}

void Add_Balance(client *head) {
    if (!head) {
        printf("Null bank list\n");
    } else {
        client *temp = head;
        int id;
        printf("Enter the id of the client: ");
        scanf("%d", &id);
        while (temp && temp->id != id) {
            temp = temp->next;
        }
        if (!temp) {
            printf("Client not found\n");
        } else {
            int password;
            printf("Enter the password of the client: ");
            scanf("%d", &password);
            while (password != atoi(temp->password)) {
                printf("Incorrect password. Enter again: ");
                scanf("%d", &password);
            }
            double amount;
            printf("Enter the amount to add: ");
            scanf("%lf", &amount);
            temp->balance += amount;
            printf("Balance updated\n");
        }
    }
}

void Deposit(client *head) {
    if (!head) {
        printf("Null bank list\n");
    } else {
        client *temp = head;
        int id;
        printf("Enter the id of the client: ");
        scanf("%d", &id);
        while (temp && temp->id != id) {
            temp = temp->next;
        }
        if (!temp) {
            printf("Client not found\n");
        } else {
            int password;
            printf("Enter the password of the client: ");
            scanf("%d", &password);
            while (password != atoi(temp->password)) {
                printf("Incorrect password. Enter again: ");
                scanf("%d", &password);
            }
            double amount;
            printf("Enter the amount to deposit: ");
            scanf("%lf", &amount);
            while (amount > temp->balance) {
                printf("Insufficient balance. Enter again: ");
                scanf("%lf", &amount);
            }
            temp->balance -= amount;
            printf("Balance updated\n");
        }
    }
}

client *Create_Admin_Client() {
    // Allocate memory for the admin client node
    client *admin = (client *) malloc(sizeof(client));
    if (admin == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }


    admin->id = -1;
    admin->balance = 0;
    admin->next = NULL;

    return admin;
}