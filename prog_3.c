#include <stdio.h>
#include <stdlib.h> //to use DMA (malloc, calloc functions)

typedef struct Node{  //defining a node structure for linked lists

    int data;
    struct Node* nextNode;

} Node;

typedef struct{ //defining a linked list (with head and tail pointers)

    Node *head, *tail;

} LL;

void initLL(LL* list){ //head and tail are pointed to NULL at the start

    list->head = NULL;
    list->tail = NULL;

}

void insertBegin(LL* list, int value){ //standard insertion in single linked list (with tail)

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

    if(list->head == NULL){
        newNode->nextNode = NULL;
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->nextNode = list->head;
    list->head = newNode;

}

void printLL(LL* list){ //standard display function 

    if(list->head == NULL){
        printf("The list is empty.\n");
        return;
    }

    Node* temp = list->head;

    printf("[ ");

    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->nextNode;
    }

    printf("NULL ]\n");

}

void reverseTraversal(Node* current){ //REVERSE TRAVERSAL FUNCTION (uses recursion)

    if(current == NULL){ //if the node is NULL, it will return
        return;
    }

    reverseTraversal(current->nextNode); //if it is not NULL, then it will keep on recursing until NULL is reached

    printf("%d\t", current->data); //finally starts going from top of function call stack and prints values in reverse order (tail->head)

}

void freeLL(LL* list){ //Function to free the memories occupied by nodes after all processes are completed

    Node* temp = list->head;

    while(temp != NULL){
        Node* next = temp->nextNode;
        free(temp);
        temp = next;
    }

    list->head = NULL;
    list->tail = NULL;

}

int main(){

    LL list;

    initLL(&list);

    insertBegin(&list, 1);
    insertBegin(&list, 2);
    insertBegin(&list, 3);

    printLL(&list);

    printf("\nReverse Traversal:\n");
    reverseTraversal(list.head);

    freeLL(&list);

    return 0;

}