#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node * createList(struct node *head, int n) {
    int data;
    head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    
    printf("Enter value of node 1 = ");
    scanf("%d", &data);
    
    head->data = data;
    head->prev = NULL;
    head->next = NULL;
    
    for(int i = 1; i < n; i++) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        temp->next = newNode;
        printf("Enter value of node %d = ", i+1);
        scanf("%d", &data);
        newNode->data = data;
        newNode->prev = temp;
        newNode->next = NULL;
        temp = temp->next;
    }
    return head;
}

void traverseList(struct node *head) {
    struct node *temp = head;
    while(temp) {
        printf("%d, ", temp->data);
        temp = temp->next;
    }
}

int main() {
    struct node *head = NULL;
    head = createList(head, 3);
    traverseList(head);
    
    return 0;
}
