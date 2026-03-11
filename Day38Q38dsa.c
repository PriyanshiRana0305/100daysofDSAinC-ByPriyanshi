/*Problem: Deque (Double-Ended Queue)

A Deque is a linear data structure that allows insertion and deletion of elements from both the front and the rear. It provides more flexibility than a standard queue or stack.

Common Operations:
1. push_front(value): Insert an element at the front of the deque.
2. push_back(value): Insert an element at the rear of the deque.
3. pop_front(): Remove an element from the front of the deque.
4. pop_back(): Remove an element from the rear of the deque.
5. front(): Return the front element of the deque.
6. back(): Return the rear element of the deque.
7. empty(): Check whether the deque is empty.
8. size(): Return the number of elements in the deque.

Additional Operations:
- clear(): Remove all elements from the deque.
- erase(): Remove one or more elements from the deque.
- swap(): Swap contents of two deques.
- emplace_front(): Insert an element at the front without copying.
- emplace_back(): Insert an element at the rear without copying.
- resize(): Change the size of the deque.
- assign(): Replace elements with new values.
- reverse(): Reverse the order of elements.
- sort(): Sort the elements in ascending order.

Time Complexity:
- push_front, push_back, pop_front, pop_back, front, back, empty, size: O(1)
- clear, erase, resize, assign, reverse: O(n)
- sort: O(n log n)

Input:
- Sequence of deque operations with values (if applicable)

Output:
- Results of operations such as front, back, size, or the final state of the deque after all operations*/
#include <stdio.h>
#define MAX 10

int deque[MAX];
int front = -1, rear = -1;

int isFull() {
    return (rear == MAX - 1);
}

int isEmpty() {
    return (front == -1);
}

void push_front(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else if (front == 0) {
        printf("Cannot insert at front\n");
        return;
    } else {
        front--;
    }

    deque[front] = value;
}

void push_back(int value) {
    if (isFull()) {
        printf("Deque Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }

    deque[rear] = value;
}

void pop_front() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear)
        front = rear = -1;
    else
        front++;
}

void pop_back() {
    if (isEmpty()) {
        printf("Deque Underflow\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear)
        front = rear = -1;
    else
        rear--;
}

void getFront() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void getRear() {
    if (isEmpty())
        printf("Deque is empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

void display() {
    if (isEmpty()) {
        printf("Deque is empty\n");
        return;
    }

    printf("Deque elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {

    push_back(10);
    push_back(20);
    push_front(5);

    display();

    getFront();
    getRear();

    pop_front();
    display();

    pop_back();
    display();

    return 0;
}