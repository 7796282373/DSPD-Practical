//Write a program to insert Number of Nodes in the Binary Tree and Traverse in Inorder , 
// Preorder and Post Order and  Search an element in Binary Tree(Display NULL if not found, If found Display Found)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert nodes in binary tree (for simplicity inserted level order)
struct Node* insertLevelOrder(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    // Use a queue to do level order insertion
    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = createNode(data);
            break;
        } else {
            queue[rear++] = temp->left;
        }

        if (temp->right == NULL) {
            temp->right = createNode(data);
            break;
        } else {
            queue[rear++] = temp->right;
        }
    }

    return root;
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Preorder traversal
void preorder(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// Postorder traversal
void postorder(struct Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// Search element in binary tree (returns 1 if found, 0 otherwise)
int search(struct Node* root, int key) {
    if (root == NULL) return 0;

    if (root->data == key) return 1;

    return search(root->left, key) || search(root->right, key);
}

int main() {
    struct Node* root = NULL;
    int n, value, key;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter node %d data: ", i + 1);
        scanf("%d", &value);
        root = insertLevelOrder(root, value);
    }

    printf("\nInorder traversal: ");
    inorder(root);
    printf("\nPreorder traversal: ");
    preorder(root);
    printf("\nPostorder traversal: ");
    postorder(root);

    printf("\n\nEnter element to search: ");
    scanf("%d", &key);

    if (search(root, key)) {
        printf("Found\n");
    } else {
        printf("NULL\n");
    }

    return 0;
}


