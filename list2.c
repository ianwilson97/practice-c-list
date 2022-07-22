#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
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
    printf("List is: ");
    while(head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}



int main()
{
    struct Node* head = NULL;//Initialize head to NULL

    printf("How many numbers?\n");
    int n, i, x;
    scanf("%d", &n);
    for(i = 0; i < n; i++) { //insert n numbers into the list
        printf("Enter the number: \n");
        scanf("%d", &x);
        head = Insert(head, x);
        Print(head); 
    }

    return 0;
}