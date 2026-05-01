/*Problem: Given n real numbers in [0,1), sort using bucket sort algorithm.
Distribute into buckets, sort each, concatenate.*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float val;
    struct Node* next;
} Node;

// Insert in sorted order (for bucket)
Node* sortedInsert(Node* head, float val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (head == NULL || head->val >= val) {
        newNode->next = head;
        return newNode;
    }

    Node* curr = head;
    while (curr->next != NULL && curr->next->val < val) {
        curr = curr->next;
    }

    newNode->next = curr->next;
    curr->next = newNode;

    return head;
}

int main() {
    int n;
    scanf("%d", &n);

    float arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%f", &arr[i]);
    }

    Node* buckets[n];
    for (int i = 0; i < n; i++) buckets[i] = NULL;

    // Distribute into buckets
    for (int i = 0; i < n; i++) {
        int idx = arr[i] * n;  // bucket index
        buckets[idx] = sortedInsert(buckets[idx], arr[i]);
    }

    // Concatenate
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[k++] = curr->val;
            curr = curr->next;
        }
    }

    // Output
    for (int i = 0; i < n; i++) {
        printf("%.6f ", arr[i]);
    }

    return 0;
}