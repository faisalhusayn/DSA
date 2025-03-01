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

struct node *insertAtBeginning(struct node *head, int data)
{
    struct node *newNode = createNode(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return newNode;
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *newNode = createNode(data);

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }
    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return head;
}

struct node *insertAtPosition(struct node *head, int data, int position)
{
    if (position == 1)
        return insertAtBeginning(head, data);

    struct node *newNode = createNode(data);
    struct node *temp = head;

    for (int i = 1; temp->next != head && i < position - 1; i++)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
}

struct node *deleteAtBeginning(struct node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct node *temp = head;
    while (temp->next != head)
        temp = temp->next;

    struct node *newHead = head->next;
    temp->next = newHead;
    free(head);
    return newHead;
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

    struct node* temp = head;
    while(temp -> next -> next != head) temp = temp -> next;

    free(temp -> next);
    temp -> next = head;
    return head;
}



void display(struct node *head)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("Back to Head\n");
}

int main()
{

    struct node *head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 40);
    head = insertAtEnd(head, 5);
    head = insertAtPosition(head, 999, 3);
    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    printf("%d\n", head->next->next->next->next->next->next->data); // just to check if the node after the last node is the final node
    display(head);
    return 0;
}