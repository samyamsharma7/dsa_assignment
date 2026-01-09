#include <stdio.h>
#define MAX_SIZE 100

typedef struct {

    char data[MAX_SIZE];
    int top;

} Stack;

void initStack(Stack* s){

    s->top = -1; //top value of -1 indicates an empty stack

}

int isEmpty(Stack* s){

    return(s->top == -1); //top value of -1 indicates an empty stack

}

int isFull(Stack* s){

    return(s->top == MAX_SIZE-1); //stack is full when it reaches the last index of char data[MAX_SIZE]

}

void push(Stack* s, char c){ //standard push()

    if(isFull(s)){
        printf("Stack Overflow. Cannot push.\n");
        return;
    }

    s->top += 1;
    s->data[s->top] = c;

}

void pop(Stack* s){ //standard pop()

    if(isEmpty(s)){
        printf("Stack Underflow. Cannot pop.\n");
        return;
    }

    s->top -= 1;

}

char peek(Stack* s){ //standard peek()

    if(isEmpty(s)){
        printf("The stack is empty. Nothing to peek.\n");
        return '\0';
    }

    return s->data[s->top];

}

void displayStack(Stack *s){

    if(isEmpty(s)){
        printf("Empty stack.\n");
        return;
    }

    printf("TOP TO BOTTOM.\n");
    for(int i=s->top; i>=0; i--){
        printf("%c\n", s->data[i]);
    }

}

char rev(char c){

    if(c==')'){
        return '(';
    }
    else if(c==']'){
        return '[';
    }
    else if(c=='}'){
        return '{';
    }

}

int areParenthesesValid(char c[]){ //logic: push opening parentheses and logically pop the equivalent closing parentheses

    Stack parentheses;

    initStack(&parentheses);

    int i = 0;

    while(c[i] != '\0'){

        if(c[i] == '(' || c[i] == '[' || c[i] == '{'){
            push(&parentheses, c[i]);
        }
        else if(c[i] == ')' || c[i] == ']' || c[i] == '}'){
            if(peek(&parentheses) == rev(c[i])){
                pop(&parentheses);
            }
            else{
                return 0;
            }
        }

        i++;

    }

    return isEmpty(&parentheses); //if all the parentheses pair are popped (i.e. empty stack), the expression is valid.

}

int main(){

    char c1[] = "a+(b-c)*(d";
    char c2[] = "m+[a-b*(c+d*{m)]";
    char c3[] = "a+(b-c)";

    if(areParenthesesValid(c1)){
        printf("c1 is valid.\n");
    } else{
        printf("c1 is not valid.\n");
    }

    if(areParenthesesValid(c2)){
        printf("c2 is valid.\n");
    } else{
        printf("c2 is not valid.\n");
    }

    if(areParenthesesValid(c3)){
        printf("c3 is valid.\n");
    } else{
        printf("c3 is not valid.\n");
    }

    return 0;

}