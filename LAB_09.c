//Assume that you have a seven-slot closed hash table (the slots are numbered o through 6)
//  Write program  to final hash table that would result if you used the hash function h(k) - k mod 7.
#include <stdio.h>

#define TABLE_SIZE 7

// Function to insert a key using closed hashing (linear probing)
void insert(int hashTable[], int key) {
    int hashIndex = key % TABLE_SIZE;
    int originalIndex = hashIndex;

    while (hashTable[hashIndex] != -1) {
        // Slot occupied, try next
        hashIndex = (hashIndex + 1) % TABLE_SIZE;
        if (hashIndex == originalIndex) {
            printf("Hash table is full. Cannot insert key %d\n", key);
            return;
        }
    }
    hashTable[hashIndex] = key;
}

int main() {
    int hashTable[TABLE_SIZE];
    int n, key;

    // Initialize hash table with -1 to indicate empty slots
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }

    printf("Enter number of keys to insert: ");
    scanf("%d", &n);

    printf("Enter keys:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(hashTable, key);
    }

    printf("\nFinal hash table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1)
            printf("Slot %d: Empty\n", i);
        else
            printf("Slot %d: %d\n", i, hashTable[i]);
    }

    return 0;
}
