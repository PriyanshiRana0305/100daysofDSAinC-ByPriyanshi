#include <stdio.h>
#define MAX 100

int main() {
    int n, i;
    int queue[MAX], stack[MAX];
    int top = -1;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    // Push queue elements into stack
    for(i = 0; i < n; i++)
        stack[++top] = queue[i];

    // Pop from stack to print reversed queue
    while(top != -1)
        printf("%d ", stack[top--]);

    return 0;
}