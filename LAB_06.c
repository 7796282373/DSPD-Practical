//Implement Binary search tree(BST) with following Menu operations.
//1.	Search an element in BST(Display NULL if not found, If found Display Found)
//2.	Insert an element in BST
//3.	Delete leaf element in BST
//4.	Exit
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
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert node in BST
struct Node* insert(struct Node* root, int data) {
    if (root == NULL) return createNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else if (data > root->data)
        root->right = insert(root->right, data);
    // If data already exists, do nothing
    return root;
}

// Search for an element in BST
struct Node* search(struct Node* root, int data) {
    if (root == NULL || root->data == data)
        return root;

    if (data < root->data)
        return search(root->left, data);
    else
        return search(root->right, data);
}

// Delete a leaf node from BST
struct Node* deleteLeaf(struct Node* root, int data) {
    if (root == NULL) return NULL;

    if (data < root->data)
        root->left = deleteLeaf(root->left, data);
    else if (data > root->data)
        root->right = deleteLeaf(root->right, data);
    else {
        // Node found
        if (root->left == NULL && root->right == NULL) {
            free(root);
            printf("Leaf node %d deleted.\n", data);
            return NULL;
        } else {
            printf("Node %d is not a leaf and cannot be deleted.\n", data);
        }
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    struct Node* foundNode;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Search an element in BST\n");
        printf("2. Insert an element in BST\n");
        printf("3. Delete leaf element in BST\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to search: ");
                scanf("%d", &value);
                foundNode = search(root, value);
                if (foundNode == NULL)
                    printf("NULL\n");
                else
                    printf("Found\n");
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("Element inserted.\n");
                break;
            case 3:
                printf("Enter leaf element to delete: ");
                scanf("%d", &value);
                root = deleteLeaf(root, value);
                break;
            case 4:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

