//
// Created by xcite on 5/5/2024.
//

#ifndef PROJECT_CLIENT_H
#define PROJECT_CLIENT_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct client {
    double balance;
    char name[100];
    char password[20];
    struct client *next;
    int id;
} client;

client *Create_Bank_List();

void display_data(client *head);

void Add_newClient(client **head);

void display_all(client *head);

void Delete_client(client **head, int id);

void Add_Balance(client *head);

client* Create_Admin_Client() ;

void Deposit(client *head);
#endif //PROJECT_CLIENT_H
