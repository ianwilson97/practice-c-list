#include <stdio.h>
#include <stdlib.h>
// this is for inserting a node at the nth node
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
    printf("How many numbers?\n"); //this is asking the user how many numbers they want to enter
    int n, i, x; //n is the number of numbers they want to enter. i is the counter. x is the number that is being entered
    scanf("%d", &n); //this is taking the number of numbers the user wants to enter
    for(i = 0; i < n; i++) {
        printf("Enter a number: \n"); //this is asking the user to enter a number
        scanf("%d", &x); //this is taking the number that the user wants to enter
        Insert(x, i+1); //this is calling the function Insert
        Print(); //this calls the function Print to print the list
    }
    
    return 0;
}
