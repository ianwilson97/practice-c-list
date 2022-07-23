#include <stdio.h>
#include <stdlib.h>
// this is file is for inserting a node at position n in a linked list

struct Node {
    int data; 
    struct Node *next;
};
struct Node* head; //this is the head of the list

void Insert(int data, int n) {
   struct Node* temp1 = (struct Node*)malloc(sizeof(struct Node*)); //this is the temporary node that is created.
   temp1->data = data; //this is the data that is stored in the node.
   temp1->next = NULL; //this is the pointer to the next node.
   if(n == 1) {
    temp1->next = head;
    head = temp1;
    return;
   }
   struct Node* temp2 = head;
   for(int i = 0; i<n-2; i++) {
    temp2 = temp2->next;
   }
   temp1->next = temp2->next;
   temp2->next = temp1;
}

void Print() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL; //this is currently an empty list
    Insert(2, 1);
    Insert(3, 2);
    Insert(4, 1);
    Insert(5, 2)
    return 0;
}
