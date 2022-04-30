#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *link;
}*head;

void createList(int n);
void traverseList();

int main(){
    createList(5);
    traverseList();
    return 0;
}

void traverseList() {
    struct node *temp = head;
    for (int i = 0; ; i++) {
        if (temp != NULL)
            printf("%d : %d\n", i, temp->data);
        else
            break;
        temp = temp->link;
    }
}

void createList(int n) {
    head = (struct node *)malloc(sizeof(struct node));
    struct node *temp = head;
    printf("Enter value of head\n");
    int data;
    scanf("%d", &data);
    head->data = data;
    for (int i = 2; i <= n; i++) {
        struct node *newNode = (struct node *)malloc(sizeof(struct node));
        printf("enter value of %d node\n", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->link = NULL;
        temp->link = newNode;
        temp = newNode;
    }
}
