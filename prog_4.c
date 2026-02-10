#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

    int data;
    struct Node *nextNode;
    struct Node *prevNode;

} Node;

typedef struct{

    Node *head, *tail;

} LL;

void initLL(LL* list){

    list->head = NULL;
    list->tail = NULL;

}

void printLL(LL* list){

    if(list->head == NULL){
        printf("The list is empty. Cannot print anything.");
        return;
    }

    Node* temp = list->head;

    printf("[ NULL <-> ");

    while(temp != NULL){
        printf("%d <-> ", temp->data);
        temp = temp->nextNode;
    }

    printf("NULL ]\n");

}

void insertBegin(LL* list, int value){

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    
    if(list->head == NULL){
        newNode->nextNode = NULL;
        newNode->prevNode = NULL;
        list->head = newNode;
        list->tail = newNode;
        return;
    }

    newNode->nextNode = list->head;
    newNode->prevNode = NULL;
    list->head->prevNode = newNode;
    list->head = newNode;

}

void insertAfterNode(LL* list, Node* given, int value){

    if(given == NULL){
        printf("Please enter a valid node.\n");
        return;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;

     if (given == list->tail) {
        given->nextNode = newNode;
        newNode->prevNode = given;
        newNode->nextNode = NULL;
        list->tail = newNode;
        return;
    }

    Node* temp = given->nextNode;

    newNode->prevNode = given;
    newNode->nextNode = temp;
    temp->prevNode = newNode;
    given->nextNode = newNode;

}

void deleteNode(LL* list, Node* given){

    if (list->head == NULL || given == NULL) {
        printf("Nothing to delete.\n");
        return;
    }

    //only one node
    if (list->head == list->tail && given == list->head) {
        free(given);
        list->head = NULL;
        list->tail = NULL;
        return;
    }

    //deleting head
    if (given == list->head) {
        list->head = given->nextNode;
        list->head->prevNode = NULL;
        free(given);
        return;
    }

    //deleting tail
    if (given == list->tail) {
        list->tail = given->prevNode;
        list->tail->nextNode = NULL;
        free(given);
        return;
    }

    //elsewhere
    given->prevNode->nextNode = given->nextNode;
    given->nextNode->prevNode = given->prevNode;
    free(given);
}


int main(){

    LL list;

    initLL(&list);

    insertBegin(&list, 1);
    insertBegin(&list, 2);
    insertBegin(&list, 3);
    insertAfterNode(&list, list.head->nextNode, 4);

    deleteNode(&list, list.head->nextNode);
    

    printLL(&list);

    return 0;

}