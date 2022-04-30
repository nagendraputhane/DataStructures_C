#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
}*head;

void reverse(struct node *prev, struct node *cur) {
    if(cur) {
        reverse (cur, cur->next);
        cur->next = prev;
    }
    else {
        head = prev;
    }
}

void createConstList();
void traverseList();

int main()
{
    createConstList();
    traverseList();
    reverse(NULL, head);
    traverseList();
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
