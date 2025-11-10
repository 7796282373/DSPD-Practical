//Design, Develop and Implement a menu driven Program in C for the following operations on QUEUE of Characters 
// (Array Implementation of Queue with maximum size MAX)
//a. Insert an Element on to QUEUE
//b. Delete an Element from QUEUE
//c. Demonstrate Overflow and Underflow situations on QUEUE
//d. Display the status of QUEUE
//e. Exit
//Support the program with appropriate functions for each of the above operations.
#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1;
int rear = -1;

// Function to insert an element into the queue
void insert(char element) {
    if ((rear + 1) % MAX == front) {
        printf("Queue Overflow! Cannot insert '%c'\n", element);
        return;
    }
    if (front == -1) { // Insert first element
        front = 0;
    }
    rear = (rear + 1) % MAX;
    queue[rear] = element;
    printf("Inserted '%c' into queue.\n", element);
}

// Function to delete an element from the queue
void delete() {
    if (front == -1) {
        printf("Queue Underflow! Cannot delete from empty queue.\n");
        return;
    }
    char deletedElement = queue[front];
    if (front == rear) {
        // Queue has only one element, reset after deletion
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("Deleted '%c' from queue.\n", deletedElement);
}

// Function to display the queue elements
void display() {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue contents: ");
    int i = front;
    while (1) {
        printf("%c ", queue[i]);
        if (i == rear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice;
    char element;

    do {
        printf("\nMenu:\n");
        printf("1. Insert an Element into Queue\n");
        printf("2. Delete an Element from Queue\n");
        printf("3. Display Queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter character to insert: ");
                scanf(" %c", &element);
                insert(element);
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}
