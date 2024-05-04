#include <stdio.h>
#include <stdlib.h>
   
typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;
     
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}
 
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
  
int search(Node* root, int data) {
    if (root == NULL) return 0;
    else if (root->data == data) return 1;
    else if (data <= root->data) return search(root->left, data);
    else return search(root->right, data);
}
  
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}
 
int main() {
    Node* root = NULL;
    root = insert(root, 10);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 3);
    root = insert(root, 7);
 
    printf("Inorder traversal: ");
    inorderTraversal(root);
    printf("\n");
  
    int searchKey = 7;
    if (search(root, searchKey)) {
        printf("%d is found in the tree.\n", searchKey);
    } else {
        printf("%d is not found in the tree.\n", searchKey);
    }
 
    searchKey = 12;
    if (search(root, searchKey)) {
        printf("%d is found in the tree.\n", searchKey);
    } else {
        printf("%d is not found in the tree.\n", searchKey);
    }
  
    return 0;
}
