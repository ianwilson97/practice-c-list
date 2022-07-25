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
    temp = head;
    prev = NULL;
    while(temp != NULL)
    {
        next = temp->next; //next is the next node in the list
        temp->next = prev; //temp->next is the pointer to the next node
        prev = temp; //prev is the previous node in the list
        temp = next; //temp is the current node in the list
    }
    head = prev; //head is the new head of the list
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