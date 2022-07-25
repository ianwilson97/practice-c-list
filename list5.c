#include <stdio.h>
#include <stdlib.h>

//this linked list implementation is for reversing a linked list


struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

struct Node* Insert(struct Node* head, int x) {//inserts a node at the end of the list
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = head;
    head = temp;
    return head;
}

void Print(struct Node* head) {
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* Reverse(struct Node* head)
{
    struct Node* temp, *prev, *next; //temp is the current node, prev is the previous node, next is the next node
    temp = head; //set temp to the head of the list
    prev = NULL; //initialize prev to NULL
    while(temp != NULL)
    {
        next = temp->next; //this changes the next node to the next node
        temp->next = prev; //this changes the next node to the previous node
        prev = temp; //this changes the previous node to the current node
        temp = next; //this changes the current node to the next node
    }
    head = prev; //this changes the head to the previous node
    return head;
}

int main()
{
    struct Node* head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 8);
    Print(head);
    head = Reverse(head); //reverses the list
    Print(head);
    return 0;
}