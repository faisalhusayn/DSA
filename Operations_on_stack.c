#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node *push(struct node *top, int data)
{
    struct node *newNode = createNode(data);
    newNode->next = top;
    return newNode;
}

struct node *pop(struct node *top)
{
    if (top == NULL)
    {
        printf("The stack is Empty\n");
        return NULL;
    }
    struct node *temp = top;
    top = top->next;
    printf("Popped: %d\n", temp->data);
    free(temp);
    return top;
}

void peek(struct node *top)
{
    if (top == NULL)
        printf("Stack is Empty!\n");
    else
        printf("Top element is: %d\n", top->data);
}

void display(struct node* top){
    if(top == NULL) {
        printf("The Stack is Empty!\n");
        return;
    }
    
    struct node* temp = top;
    printf("Stack: ");
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main()
{
    struct node *top = NULL;

    top = push(top, 10);
    top = push(top, 20);
    top = push(top, 30);
    top =push(top, 40);
    display(top);
    top = pop(top);
    display(top);
    top = pop(top);
    display(top);
    return 0;
}