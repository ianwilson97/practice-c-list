#include <stdio.h>
#include <stdlib.h>
//In this file I'm inserting data into a linked list, and then removing data from the list.


struct Node {
    int data; //this is the data that is stored in the node.
    struct Node *next; //this is the pointer to the next node.
};

struct Node* head; //this is the head of the list. It is a global variable.

void Insert(int data){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node)); 
    temp->data = data; //this is the data that is stored in the node.
    temp->next = head;
    head = temp;

}//this is the function that inserts a node at the end of the list.

void Print(){
    struct Node* temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}//this is the function that prints the list.

void Delete(int n){
    struct Node* temp = head;
    if(n == 1) {//if the node is the head, then we need to change the head.
        head = temp->next; //the head is now the next node.
        free(temp); //we free the node.
        return;
    }
    int i;
    for(i = 0; i<n-2; i++) {
        temp = temp->next; //temp is the node that is before the node that is to be deleted. (n-1)th node.
    }
    struct Node* temp2 = temp->next; //temp2 is the node that is to be deleted. (nth node)
    temp->next = temp2->next; //temp is now pointing to the node that is after the node that is to be deleted. (n+1)th node.
    free(temp2); //freeing the node that is to be deleted.
}//this is the function that deletes a node at position n.

int main()
{
    head = NULL; //this is currently an empty list
    Insert(2); //Inserting 2 at the end of the list
    Insert(3); //Inserting 3 at the end of the list
    Insert(4); //Inserting 4 at the end of the list
    Insert(5); //Inserting 5 at the end of the list
    Print();
    //List is now: 2 3 4 5
    int n;
    printf("Enter the position of the node to be deleted: ");
    scanf("%d", &n);
    Delete(n);
    Print();

    return 0;
}