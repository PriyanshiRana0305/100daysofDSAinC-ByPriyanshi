#include <stdio.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    return stack[top--];
}

int precedence(char op)
{
    if(op == '+' || op == '-')
        return 1;
    if(op == '*' || op == '/')
        return 2;
    if(op == '^')
        return 3;
    return 0;
}

int main()
{
    char infix[100], postfix[100];
    int i = 0, k = 0;

    scanf("%s", infix);

    while(infix[i] != '\0')
    {
        char ch = infix[i];

        if(isalnum(ch))   // operand
        {
            postfix[k++] = ch;
        }
        else if(ch == '(')
        {
            push(ch);
        }
        else if(ch == ')')
        {
            while(stack[top] != '(')
                postfix[k++] = pop();
            pop(); // remove '('
        }
        else   // operator
        {
            while(top != -1 && precedence(stack[top]) >= precedence(ch))
                postfix[k++] = pop();
            push(ch);
        }

        i++;
    }

    while(top != -1)
        postfix[k++] = pop();

    postfix[k] = '\0';

    printf("%s", postfix);

    return 0;
}