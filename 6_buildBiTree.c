#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left, *right;
};

struct node * create(struct node *root, int data) {
    root = (struct node *)malloc(sizeof(struct node));
    root->data = data;
    root->left = root->right = NULL;
}

struct node * insert(struct node *root, int data) {
    
    if(root == NULL) {
        root = create(root, data);
    }
    else if(root->data >= data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(struct node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d, ", root->data);
        inorder(root->right);
    }
}

int main()
{
    struct node *root;
    root = NULL;
    
    root = insert(root, 77);
    root = insert(root, 1);
    root = insert(root, 2);
    
    inorder(root);
    
    return 0;
}
