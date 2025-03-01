#include <stdio.h>
#include <ctype.h> // For isalnum()
#include <string.h>

#define SIZE 100

struct Stack
{
    char items[SIZE];
    int top;
};

void initStack(struct Stack *s)
{
    s->top = -1;
}

void push(struct Stack *s, char value)
{
    s->items[++s->top] = value;
}

char pop(struct Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->items[s->top--];
}

char peek(struct Stack *s)
{
    if (s->top == -1)
        return '\0';
    return s->items[s->top];
}

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    if (ch == '*' || ch == '/')
        return 2;
    if (ch == '+' || ch == '-')
        return 1;
    return 0;
}

void infixToPostfix(char *infix)
{
    struct Stack s;
    initStack(&s);
    char postfix[SIZE];
    int j = 0;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j++] = ch;
        }
        else if (ch == '(')
        {
            push(&s, ch);
        }
        else if (ch == ')')
        {
            while (peek(&s) != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (precedence(peek(&s)) >= precedence(ch))
            {
                postfix[j++] = pop(&s);
            }
            push(&s, ch);
        }
    }

    while (s.top != -1)
    {
        postfix[j++] = pop(&s);
    }

    postfix[j] = '\0';
    printf("Postfix: %s\n", postfix);
}

int main()
{
    char infix[] = "(A/B)+(C*E)";
    printf("Infix: %s\n", infix);
    infixToPostfix(infix);
    return 0;
}
