#include <stdio.h>
#include <stdlib.h>

//reversing a linked-list utilizing recursion

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;

//create an insert function with Node p and int data
struct Node* Insert(struct Node* p, int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    if(p == NULL) p = temp;
    else {
        struct Node* temp1 = p;
        while(temp1->next != NULL) temp1 = temp1->next;
        temp1->next = temp;
    }
    return p;
}

void Reverse(struct Node* p)
{
    if(p->next == NULL) //this statement contains the exit condition for the recursive function
    {
        head = p;
        return;
    }
    Reverse(p->next); //this statement contains the recursive call
    struct Node* q = p->next; //this statement is used to store the value of the next node
    q->next = p; //this statement changes the next pointer of the next node to the current node
    p->next = NULL; //this statement changes the next pointer of the current node to NULL
}

//Create a print function with Node p
void Print(struct Node* p)
{
    if(p == NULL) return; //this statement contains the exit condition for the recursive function
    printf("%d", p->data); //this statement prints the value of the current node
    Print(p->next); //this statement contains the recursive call
}


int main()
{
    head = NULL;
    head = Insert(head, 2);
    head = Insert(head, 4);
    head = Insert(head, 6);
    head = Insert(head, 5);
    Print(head);
    printf("\n");
    Reverse(head);
    Print(head);
    return 0;
}