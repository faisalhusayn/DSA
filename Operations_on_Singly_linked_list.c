#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode -> data = data;
    newNode -> next = NULL;
    return newNode;
}

struct node* insertAtBeginning(struct node* head, int data){
    struct node* newNode = createNode(data);
    newNode -> next = head;
    return newNode;
}

struct node* insertAtEnd(struct node* head, int data){
    struct node* newNode = createNode(data);
    if(head == NULL) return newNode;
    struct node* temp = head;

    while (temp -> next != NULL) temp = temp -> next;
    temp -> next = newNode;
    return head;
}

struct node* insertAtPosition(struct node* head, int data, int position){
    struct node* newNode = createNode(data);
    if (position == 1){
        newNode -> next = head;
        return newNode;
    }

    struct node* temp = head;
    for(int i = 1; i < position - 1 && temp != NULL; i++){
        temp = temp -> next;
    }

    if (temp == NULL)
    {
        printf("Invalid position\n");
        free(newNode);
        return head;
    }

    newNode -> next = temp -> next;
    temp -> next = newNode;
    return head;
    
}

struct node* deleteAtBeginning(struct node* head){
    struct node* temp = head;

    if(head == NULL){
        printf("List is empty\n");
        return NULL;
    }
    head = temp -> next;
    free(temp);
    return head;
}

struct node* deleteAtEnd(struct node* head){
    
    if(head == NULL){
        printf("List is empty\n");
        return NULL;
    }

    if(head -> next == NULL){
        free(head);
        return NULL;
    }

    struct node* temp = head;
    while(temp -> next -> next != head){
        temp = temp -> next;
    }
    free(temp -> next);
    temp -> next = NULL;
    return head;
}

struct node* deleteAtPosition(struct node* head, int position){

    if(head == NULL){
        printf("List is empty\n");
        return NULL;
    }

    if(position == 1){
        struct node* temp = head;
        head = head -> next;
        free(temp);
        return head;
    }

    struct node* temp = head;
    for(int i = 1; temp -> next != NULL && i < position - 1; i++){
        temp = temp -> next;
    }

    if(temp -> next == NULL){
        printf("Out of bounds\n");
        return head;
    }

    struct node* delNode = temp -> next;
    temp -> next = temp -> next -> next;
    free(delNode);
    return head;
}

void PrintList(struct node* head){
    struct node* temp = head;
    while(temp != NULL){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head = NULL;
    head = insertAtBeginning(head, 10);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 30);
    head = insertAtEnd(head, 500);
    head = insertAtPosition(head, 9999, 3);
    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = deleteAtPosition(head, 2);
    PrintList(head);
    return 0;
}