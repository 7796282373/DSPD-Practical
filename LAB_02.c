//Design, Develop and Implement a menu driven Program in C for the following operations on STACK of Integers 
// (Array Implementation of Stack with maximum size MAX) 
//a. Push an Element on to Stack 
//B. Pop an Element from Stack 
//c. Demonstrate how Stack can be used to check Palindrome 
//d. Demonstrate Overflow and Underflow situations on Stack 
//e. Display the status of Stack 
//f. Exit 
//Support the program with appropriate functions for each of the above operations
#include <stdio.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push function
void push(int value) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", value);
    } else {
        stack[++top] = value;
        printf("Pushed %d onto stack.\n", value);
    }
}

// Pop function
int pop() {
    if (top == -1) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return -1; // Indicate error by returning -1
    } else {
        int value = stack[top--];
        printf("Popped %d from stack.\n", value);
        return value;
    }
}

// Display stack status
void display() {
    if (top == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack contents (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

// Function to check if the stack content forms a palindrome
void checkPalindrome() {
    if (top == -1) {
        printf("Stack is empty. Nothing to check.\n");
        return;
    }
    int start = 0, end = top;
    int isPalindrome = 1;
    while (start < end) {
        if (stack[start] != stack[end]) {
            isPalindrome = 0;
            break;
        }
        start++;
        end--;
    }
    if (isPalindrome)
        printf("The stack elements form a palindrome.\n");
    else
        printf("The stack elements do not form a palindrome.\n");
}

int main() {
    int choice, value;

    do {
        printf("\nMenu:\n");
        printf("1. Push an Element onto Stack\n");
        printf("2. Pop an Element from Stack\n");
        printf("3. Check if Stack forms a Palindrome\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &value);
                push(value);
                break;
            case 2:
                pop();
                break;
            case 3:
                checkPalindrome();
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}
