#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

int countLeafNodes(struct Node* root) {
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return countLeafNodes(root->left) + countLeafNodes(root->right);
}

int main() {
    int n, val;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    struct Node* nodes[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        nodes[i] = createNode(val);
    }

    for (int i = 0; i < n; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        if (l != -1)
            nodes[i]->left = nodes[l];
        if (r != -1)
            nodes[i]->right = nodes[r];
    }

    printf("%d", countLeafNodes(nodes[0]));
    return 0;
}