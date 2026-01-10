#include <stdio.h>
#define MAX_SIZE 100

typedef struct{

    char data[MAX_SIZE];
    int top;

} Stack;

void initStack(Stack* s){

    s->top = -1; //-1 indicates an empty stack

}

int isEmpty(Stack* s){

    return(s->top == -1);

}

int isFull(Stack* s){

    return(s->top == MAX_SIZE-1);

}

void push(Stack* s, char c){

    if(isFull(s)){
        printf("Stack Overflow. Cannot push.\n");
        return;
    }

    s->top += 1;
    s->data[s->top] = c;

}

char pop(Stack* s){

    if(isEmpty(s)){
        printf("Stack Underflow. Cannot pop.\n");
        return '\0';
    }

    char temp = s->data[s->top];
    s->top -= 1;
    return temp;

}

char peek(Stack* s){

    if(isEmpty(s)){
        printf("The stack is empty. Nothing to peek.\n");
        return '\0';
    }

    return s->data[s->top];

}

int isOperand(char c){

    if(c>=48 && c<=57){
        return 1;
    }
    else{
        return 0;
    }

}

int isOpeningParenthesis(char c){

    if(c=='(' || c=='{' || c=='['){
        return 1;
    }
    else{
        return 0;
    }

}

int isClosingParenthesis(char c){

    if(c==')' || c=='}' || c==']'){
        return 1;
    }
    else{
        return 0;
    }

}

int isOperator(char c){

    if(c=='+' || c=='-' || c=='*' || c=='/'){
        return 1;
    }
    else{
        return 0;
    }

}

int precedence(char c){

    if(c=='+' || c=='-'){
        return 1;
    }
    else if(c=='*' || c=='/'){
        return 2;
    }
    else{
        return 0;
    }

}

char rev(char c){

    if(c=='('){
        return ')';
    }
    else if(c=='{'){
        return '}';
    }
    else if(c=='['){
        return ']';
    }
    else{
        return '\0';
    }

}

int bracketsMatch(char opening, char closing){

    if(closing == rev(opening)){
        return 1;
    }
    else{
        return 0;
    }

}

void infixToPostfix(char infix[], char postfix[]){

    Stack s;
    initStack(&s);

    int index = 0;
    int i = 0;

    while(infix[i] != '\0'){

        char c = infix[i];

        if(isOperand(c)){ //if it is an operand, it simply adds it to the postfix expression.
            postfix[index] = c;
            index++;
        }
        else if(isOpeningParenthesis(c)){ //if it is an opening parenthesis, it pushes it onto the operator stack.
            push(&s, c);
        }
        else if(isClosingParenthesis(c)){ //for closing parenthesis
            while(!bracketsMatch(peek(&s), c)){ //it keeps on popping characters (from operator stack) step by step (adding it to the postfix expression simultaneously) until its opening parenthesis pair is encountered.
                postfix[index] = pop(&s);
                index++;
            }
            pop(&s); //pops the remaining opening parenthesis
        }
        else{ //for operator
            while(precedence(peek(&s))>=precedence(c) && !isOpeningParenthesis(peek(&s))){ //keeps on popping operators and stops only if the precedence level is higher or if an opening parenthesis is encountered.
                postfix[index] = pop(&s);
                index++;
            }
            push(&s, c); //pushes only if appropriate (i.e. if its precedence is higher; after completing the above while-loop operations)
        }

        i++;

    }

    while(!isEmpty(&s)){ //adds the remaining characters (if missed any)
        postfix[index] = pop(&s);
        index++;
    }

    postfix[index] = '\0';

}

int calculate(int x, int y, char z){

    switch(z){

        case '+':
            return y+x;
        case '-':
            return y-x;
        case '*':
            return y*x;
        case '/':
            return y/x;
        default:
            return 0;

    }

}

int evaluatePostfix(char postfix[]){

    Stack s;
    initStack(&s);

    int result = 0;

    int i = 0;

    while(postfix[i] != '\0'){

        char c = postfix[i];

        if(isOperand(c)){ //if it is an operand, it pushes directly onto the stack
            push(&s, c);
        }
        else if(isOperator(c)){ //for an operator, it pops the "TOP" and "NEXT-TO-TOP" values using the operator and pushes the result onto the stack again
            int num1 = pop(&s) - '0';
            int num2 = pop(&s) - '0';
            push(&s, calculate(num1, num2, c)+'0');
        }

        i++;

    }

    result = peek(&s) - '0'; //the last remaining "TOP" value is the answer

    return result;

}

int main(){

    char infix[] = "(3+2)/1+(2-1)*2";
    char postfix[100];

    infixToPostfix(infix, postfix);

    int i = 0;

    printf("Postfix Expression: ");

    while(postfix[i] != '\0'){

        printf("%c", postfix[i]);
        i++;

    }
    printf("\n");

    printf("Result: %d", evaluatePostfix(postfix));

    return 0;

}

