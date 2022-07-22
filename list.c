#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data; //created a linked list with an integer data type. This is the data that is stored in the node.
    struct Node *next; //This is the pointer to the next node. Node is called next because it is the next node in the list.
};

struct Node* head; //This is the head of the list.

void Insert(int x) {
    //The type of each node must be defined. Ex. struct Node *head;
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); //This is the temporary node that is created.
    temp->data = x; //This is the data that is stored in the node.
    temp->next = head; //This is the pointer to the next node.
    head = temp; 
}

void Print() {
    struct Node* temp = head; //This is the temporary node that is created.
    while(temp != NULL) { //This is the while loop that prints the list.
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = NULL; //This list is currently empty.
    printf("How many numbers?\n"); //This is asking the user how many numbers they want to enter.
    int n, i, x; //n is the number of numbers they want to enter. i is the counter. x is the number that is being entered.
    scanf("%d", &n); //This is taking the number of numbers the user wants to enter.
    for(i = 0; i < n; i++)
    {
        printf("Enter the number: \n"); //This is asking the user to enter a number.
        scanf("%d", &x); //This is taking the number that the user wants to enter.
        Insert(x); //This is calling the function Insert.
        Print(); //This is calling the function Print.
    }

    return 0;
}
