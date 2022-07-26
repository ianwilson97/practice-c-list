#include <stdio.h>
#include <stdlib.h>

//implementing a doubly linked list

struct Node {
    int data;
    struct Node* next; //this is the pointer to the next node
    struct Node* prev; //this is the pointer to the previous node
};

struct Node* head; //this is the pointer to the head node. global varialbe

struct Node* GetNewNode(int x)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node)); //this creates a new node
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x)
{
    struct Node* newNode = GetNewNode(x);
    if(head == NULL) {
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void ReversePrint(){
    struct Node* temp = head;
    if(temp == NULL) return; //if the list is empty, exit the function
    while(temp->next != NULL) {
        temp = temp->next; //this moves the pointer to the next node
    }
    //Traversing backwards using the previous pointer here
    printf("Reverse: ");
    while(temp != NULL) { //this loop prints the values in the list in reverse order
        printf("%d", temp->data); //this prints the value of the current node
        temp = temp->prev; //this moves the pointer to the previous node
    }
    printf("\n");
}

void Print() {
    struct Node* temp = head;
    printf("Forward: ");
    while(temp != NULL) { //this loop prints the values in the list in forward order
        printf("%d", temp->data); //this prints the value of the current node
        temp = temp->next; //this moves the pointer to the next node
    }
    printf("\n");
}


int main()
{
    head = NULL;
    InsertAtHead(2);
    Print();
    ReversePrint();
    InsertAtHead(4);
    Print();
    ReversePrint();
    InsertAtHead(6);
    Print();
    ReversePrint();
    return 0;
}