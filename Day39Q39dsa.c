/*Problem Statement:
Implement a Min Heap using an array where the smallest element is always at the root.

Supported Operations:
- insert x
- extractMin
- peek

Input Format:
- First line contains integer N
- Next N lines contain heap operations

Output Format:
- Print results of extractMin and peek
- Print -1 if operation cannot be performed

Example:
Input:
6
insert 40
insert 10
insert 30
peek
extractMin
peek

Output:
10
10
30*/

#include <stdio.h>
#define MAX 100

int heap[MAX];
int size = 0;

// Swap function
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify Up (used after insert)
void heapifyUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;

        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else {
            break;
        }
    }
}

// Heapify Down (used after extractMin)
void heapifyDown(int index) {
    int left, right, smallest;

    while (1) {
        left = 2 * index + 1;
        right = 2 * index + 2;
        smallest = index;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;

        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

// Insert element
void insert(int value) {
    if (size == MAX)
        return;

    heap[size] = value;
    heapifyUp(size);
    size++;
}

// Peek minimum element
int peek() {
    if (size == 0)
        return -1;

    return heap[0];
}

// Extract minimum element
int extractMin() {
    if (size == 0)
        return -1;

    int min = heap[0];
    heap[0] = heap[size - 1];
    size--;

    heapifyDown(0);

    return min;
}

int main() {
    int N;
    scanf("%d", &N);

    char operation[20];
    int value;

    for (int i = 0; i < N; i++) {
        scanf("%s", operation);

        if (operation[0] == 'i') { // insert
            scanf("%d", &value);
            insert(value);
        }
        else if (operation[0] == 'p') { // peek
            printf("%d\n", peek());
        }
        else if (operation[0] == 'e') { // extractMin
            printf("%d\n", extractMin());
        }
    }

    return 0;
}