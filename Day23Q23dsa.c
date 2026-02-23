#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node* create(int n)
{
    struct node *head = NULL, *temp = NULL, *newnode;
    int x;
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = x;
        newnode->next = NULL;
        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }
    }
    return head;
}

struct node* merge(struct node *l1, struct node *l2)
{
    struct node *head = NULL, *tail = NULL;

    while(l1 && l2)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        if(l1->data < l2->data)
        {
            newnode->data = l1->data;
            l1 = l1->next;
        }
        else
        {
            newnode->data = l2->data;
            l2 = l2->next;
        }
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

    while(l1)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = l1->data;
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
        l1 = l1->next;
    }

    while(l2)
    {
        struct node *newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = l2->data;
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
        l2 = l2->next;
    }

    return head;
}

void display(struct node *head)
{
    while(head)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

int main()
{
    int n, m;
    scanf("%d", &n);
    struct node *l1 = create(n);
    scanf("%d", &m);
    struct node *l2 = create(m);

    struct node *result = merge(l1, l2);
    display(result);

    return 0;
}