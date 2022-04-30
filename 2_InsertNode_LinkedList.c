#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void createConstList();
void traverseList();
void insertBeginning();
void insertEnding();
void insertMiddle();

int main() {
    
    createConstList();
    //traverseList();
    //insertBeginning();
    //insertEnding();
    insertMiddle();
}

void createConstList() {
    head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    head->data = 1;
    head->next = second;
    second->data = 2;
    second->next = third;
    third->data = 3;
    third->next = fourth;
    fourth->data = 4;
    fourth->next = NULL;
}

void traverseList() {
    struct node *temp = head;
    for (int i = 0; ; i++) {
        if (temp != NULL)
            printf("%d, ", temp->data);
        else
            break;
        temp = temp->next;
    }
}

void insertBeginning() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 66;
    newNode->next = head;
    head = newNode;
    traverseList();
}

void insertEnding() {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    newNode->data = 55;
    newNode->next = NULL;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    traverseList();
}

void insertMiddle() {
    printf("Enter where to insert new node\n");
    int n;
    scanf("%d", &n);
    struct node *temp = head;
    for (int i = 1; i < n; i++) {
        temp = temp->next;
    }
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = 55;
    newNode->next = temp->next;
    temp->next = newNode;
    traverseList();
}
