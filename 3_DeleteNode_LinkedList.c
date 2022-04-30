#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void createConstList();
void traverseList();
void deleteBeginning();
void deleteEnding();
void deleteMiddle();

int main() {
    
    createConstList();
    traverseList();
    //deleteBeginning();
    //deleteEnding();
    deleteMiddle();
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
    printf("\n");
}

void deleteBeginning() {
    struct node *temp = head;
    temp = temp->next;
    free(head);
    head = temp;
    traverseList();
}

void deleteEnding() {
    struct node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    traverseList();
}

void deleteMiddle() {
    printf("Enter where to delete node\n");
    int n;
    scanf("%d", &n);
    struct node *temp = head;
    for (int i = 1; i < n-1; i++) {
        temp = temp->next;
    }
    struct node *temp1 = temp->next;
    temp->next = temp->next->next;
    free(temp1);
    traverseList();
}
