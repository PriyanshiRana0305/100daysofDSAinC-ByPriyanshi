#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int x)
{
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    struct node *temp;
    int val;

    if(top == NULL)
        return 0;

    temp = top;
    val = temp->data;
    top = top->next;
    free(temp);

    return val;
}

int main()
{
    char exp[100];
    int i = 0, a, b;

    fgets(exp, sizeof(exp), stdin);

    while(exp[i] != '\0')
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }
        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            b = pop();
            a = pop();

            if(exp[i] == '+')
                push(a + b);
            else if(exp[i] == '-')
                push(a - b);
            else if(exp[i] == '*')
                push(a * b);
            else if(exp[i] == '/')
                push(a / b);
        }
        i++;
    }

    printf("%d", pop());

    return 0;
}