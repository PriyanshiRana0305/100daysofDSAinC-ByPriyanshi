/* Problem: Find Intersection Point of Two Linked Lists - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers (first list)
- Third line: integer m
- Fourth line: m space-separated integers (second list)

Output:
- Print value of intersection node or 'No Intersection'

Example:
Input:
5
10 20 30 40 50
4
15 25 30 40 50

Output:
30

Explanation:
Calculate lengths, advance pointer in longer list, traverse both simultaneously. First common node is intersection. */
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

int findIntersection(struct Node* head1, struct Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    int diff = abs(len1 - len2);

    struct Node* ptr1 = head1;
    struct Node* ptr2 = head2;

    if (len1 > len2) {
        for (int i = 0; i < diff; i++)
            ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < diff; i++)
            ptr2 = ptr2->next;
    }

    while (ptr1 != NULL && ptr2 != NULL) {
        if (ptr1->data == ptr2->data) {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return -1;
}

int main() {
    int n, m, value;

    struct Node *head1 = NULL, *head2 = NULL, *temp, *prev = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (head1 == NULL)
            head1 = temp;
        else
            prev->next = temp;
        prev = temp;
    }

    prev = NULL;

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        temp = createNode(value);
        if (head2 == NULL)
            head2 = temp;
        else
            prev->next = temp;
        prev = temp;
    }

    int result = findIntersection(head1, head2);

    if (result == -1)
        printf("No Intersection");
    else
        printf("%d", result);

    return 0;
}