#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int main()
{
    int n, k, i, x;
    struct node *head = NULL, *temp, *newnode, *tail;
    
    scanf("%d", &n);

    // Creating linked list
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    scanf("%d", &k);

    k = k % n;

    if(k == 0)
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }

    // Make list circular
    tail->next = head;

    int steps = n - k;
    temp = head;

    for(i = 1; i < steps; i++)
    {
        temp = temp->next;
    }

    head = temp->next;
    temp->next = NULL;

    // Print rotated list
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}