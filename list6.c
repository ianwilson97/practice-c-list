#include <stdio.h>
#include <stdlib.h>

//printing a linked list in reverse order

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

struct Node* Insert(struct Node* head, int data) {//inserts a node at the end of the list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(head == NULL) head = temp;
    else {
        struct Node* temp1 = head;
        while(temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
    return head;
}

void Print(struct Node* head) 
{
    if(head == NULL) return; //Exits the condition
    printf("%d", head->data); //First print the value in the node
    Print(head->next); //recursive call
}

void ReversePrint(struct Node* head) {
    if(head == NULL) return;
    Print(head->next);
    printf("%d", head->data);
}

int main() 
{
    struct Node* head = NULL; // this is a local variable
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    ReversePrint(head);

    return 0;
}