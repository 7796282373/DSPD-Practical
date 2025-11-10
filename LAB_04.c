//This C program creates a linked list to store integer elements. 
// It prompts the user to enter elements and add them to the list until the user enters 0. 
// It then traverses the list and prints each element and "=>" until reaching the null pointer. 
// Finally, it displays the number of nodes in the list
#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add node at the end of the linked list
void appendNode(struct Node** headRef, int data) {
    struct Node* newNode = createNode(data);
    if (*headRef == NULL) {
        *headRef = newNode;
        return;
    }
    struct Node* temp = *headRef;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d => ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to count number of nodes
int countNodes(struct Node* head) {
    int count = 0;
    struct Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    struct Node* head = NULL;
    int value;

    printf("Enter integers to add to the list (enter 0 to stop):\n");
    while (1) {
        scanf("%d", &value);
        if (value == 0) {
            break;
        }
        appendNode(&head, value);
    }

    printf("Linked list elements:\n");
    printList(head);

    int n = countNodes(head);
    printf("Number of nodes in the list: %d\n", n);

    return 0;
}
