
#include <stdio.h>
#include <stdlib.h>

#include "Client.h"


int main(void) {

    client *head = Create_Admin_Client();

    int count = 0;
    int choice;
    do {
        system("cls");
        printf("\n1. Add new client\n");
        printf("2. Display all clients\n");
        printf("3. Delete client\n");
        printf("4. Add balance\n");
        printf("5. Deposit\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input\n");
            while (getchar() != '\n');
            continue;
        }

        switch (choice) {
            case 1:
                Add_newClient(&head);
                count++;
                break;
            case 2:
                display_all(head);
                break;
            case 3: {
                if (count == 0) {
                    printf("No clients in the bank\n");
                    break;
                }
                int id;
                printf("Enter the id of the client to delete: ");
                if (scanf("%d", &id) != 1) {
                    printf("Invalid input\n");
                    while (getchar() != '\n');
                    break;
                }
                if (id == head->id) {
                    printf("Admin client cannot be deleted\n");
                } else {
                    Delete_client(&head, id);
                    count--;
                }
                break;
            }
            case 4:
                Add_Balance(head);
                break;
            case 5:
                Deposit(head);
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
        }
    } while (choice != 6);

    free(head);

    return 0;
}
