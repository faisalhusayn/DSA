#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *newNode = createNode(data);

    if (head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
    }
    return newNode;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *newNode = createNode(data);

    if (head == NULL)
        return newNode;
    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct node *insertAtPosition(struct node *head, int data, int position)
{
    struct node *newNode = createNode(data);

    if (position == 1)
    {
        newNode->next = head;
        if (head != NULL)
            head->prev = newNode;
        return newNode;
    }

    struct node *temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Out of bounds\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
    newNode->prev = temp;

    return head;
}

struct node *deleteAtBeginning(struct node *head)
{

    if (head == NULL)
        return NULL;

    struct node *temp = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    free(temp);
    return head;
}

struct node *deleteAtEnd(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->prev->next = NULL;
    free(temp);
    return head;
}

struct node *deleteAtPosition(struct node *head, int position)
{
    if (head == NULL)
        return NULL;

    if (position == 1)
    {
        struct node *temp = head;
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return head;
    }

    struct node *temp = head;
    for (int i = 1; temp != NULL && i < position - 1; i++)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Out of Bounds\n");
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    return head;
}

void displayForward(struct node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse(struct node *head)
{

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 40);
    head = insertAtBeginning(head, 50);

    head = insertAtPosition(head, 999, 4);
    head = insertAtEnd(head, 5);
    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = deleteAtPosition(head, 4);
    displayForward(head);
    displayReverse(head);
    return 0;
}