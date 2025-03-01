#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode -> next = NULL;
    return newNode;
}

struct node* enqueue(struct node* rear, int data){
    struct node* newNode = createNode(data);
    if(rear == NULL) return newNode;

    rear -> next = newNode;
    return newNode;
}

struct node* dequeue(struct node* front){
    if(front == NULL){
        printf("Queue is Empty, nothing to dequeue\n");
        return NULL;
    }
    struct node* temp = front;
    front = front -> next;
    free(temp);
    return front;
}

void peek(struct node* front){
    if(front == NULL){
        printf("Queue is Empty\n");
        return;
    }
    else printf("Front element is: %d\n", front -> data);
}

void display(struct node* front){
    if(front == NULL){
        printf("Queue is empty\n");
        return;
    }
    struct node* temp = front;
    printf("Queue is: ");
    while(temp){
        printf("%d -> ", temp -> data);
        temp = temp -> next;
    }
    printf("NULL\n");
}

int main(){

    struct node* front = NULL;
    struct node* rear = NULL;
    rear = enqueue(rear, 10);
    if(front == NULL) front = rear;
    rear = enqueue(rear, 20);
    rear = enqueue(rear, 30);
    rear = enqueue(rear, 40);
    rear = enqueue(rear, 50);

    peek(front);
    display(front);
    front = dequeue(front);
    front = dequeue(front);
    display(front);
    return 0;
}