# DOCUMENTATION (prog_2.c)

## Logic

### 1. Infix to Postfix Conversion:

The algorithm works as follows:

1. Operands (`0-9`) are directly written to the postfix expression as they are encountered.
2. Operators (`+`, `-`, `*`, `/`) are pushed onto a stack according to precedence rules:
   - `*` and `/` have higher precedence than `+` and `-`.
   - An operator with equal or lower precedence than the one on top of the stack cannot be placed on top and causes the stack to be popped until it is safe to push.
3. Parentheses:
   - When an opening parenthesis is encountered, it is pushed onto the stack.
   - When a closing parenthesis is encountered, all operators are popped from the stack and added to the postfix expression until the matching opening parenthesis is found (which is then removed from the stack).
4. This process continues until the entire infix expression is read.
5. After reading the infix expression, any remaining operators in the stack are popped and written to the postfix expression.

### 2. Postfix Evaluation:

The algorithm works as follows:

1. Operands (`0-9`) are pushed onto the stack as they are encountered.
2. When an operator is encountered:
   - The top two values are popped from the stack.
   - The operation is applied in the order:
   
     ```c
        NEXT-TO-TOP operator TOP
     ```
   - The result is then pushed back onto the stack.
3. This continues until the end of the postfix expression.
4. The last remaining value on the stack is the final result.

### Assumptions/Limitations

1. The program supports only single-digit integers (`0-9`) as operands.
2. Operators are limited to `+`, `-`, `*`, `/`.
3. Integer division is performed (`/`) according to C rules.
4. The stack is used as a character stack, so all operands and intermediate results are stored as characters.
5. Results of intermediate operations **must remain single-digit** to work correctly with this implementation.

---

## Data Structure Implementation

A standard character stack is used in the program to manage operators, operands (as characters), and parentheses during infix-to-postfix conversion and postfix evaluation.

The stack contains:

- An array of characters to store operands, operators, and parentheses.
- A `top` index to track the current top of the stack.

The stack is defined using a structure:

```c
    typedef struct{
        char data[MAX_SIZE]; //MAX_SIZE is defined as the maximum size of the array
        int top;
    }
```

---

## Functions Used

1. `initStack(Stack* s):`
    Initializes the stack by setting `top = -1`, meaning the stack is empty at the start.

2. `isEmpty(Stack* s):`
    Checks if the stack is empty. Returns `1` (true) if empty, else `0`.

3. `isFull(Stack* s):`
    Checks if the stack is full. Returns `1` (true) if full, else `0`.

4. `push(Stack* s, char c):`
    Adds a character to the top of the stack. If the stack is full, it prints "Stack Overflow" and does nothing.

5. `pop(Stack* s):`
    Removes and returns the top element from the stack. If the stack is full, it prints "Stack Underflow" and returns `'\0'`.

6. `peek(Stack* s):`
    Returns the character at the top of the stack without removing it. If the stack is empty, it prints a warning and returns `'\0'`.

7. `isOperand(char c):`
    Checks whether a character is a numeric operand (`0-9`). Returns `1` if it is an operand, otherwise `0`.

8. `isOperator(char c):`
    Checks whether a character is an operator (`+`, `-`, `*`, `/`). Returns `1` if it is, otherwise `0`.

9. `isOpeningParenthesis(char c):`
    Checks if a character is an opening parenthesis (`(`, `{`, `[`).

10. `isClosingParenthesis(char c):`
    Checks if a character is a closing parenthesis (`)`, `}`, `]`).

11. `bracketsMatch(char opening, char closing):`
    Returns `1` if the given opening and closing parentheses match, otherwise `0`.

12. `rev(char c):`
    Returns the corresponding closing parenthesis for a given opening parenthesis.

13. `precedence(char c):`
    Returns the precedence of an operator: `*` and `/` have precedence 2, `+` and `-` have precedence 1, and non-operators have 0.

14. `infixToPostfix(char infix[], char postfix[]):`
    Converts an infix expression to postfix notation using the stack. Operands are added directly to the postfix expression, while operators are pushed to the stack according to precedence and parentheses rules.

15. `calculate(int x, int y, char z):`
    Performs the operation `y operator x` (NEXT-TO-TOP operator TOP) and returns the result.

16. `evaluatePostfix(char postfix[]):`
    Evaluates a postfix expression using a stack. Operands are pushed onto the stack, and when an operator is encountered, the top two operands are popped, the operation is applied, and the result is pushed back. The final result is the last remaining value in the stack.

---

## main() Function

The `main()` function demonstrates the program using a sample infix expression:

```c
    char infix[] = "(3+2)/1+(2-1)*2";
```

For this expression:
1. `infixToPostfix()` is called to convert the infix expression to postfix notation.
2. The resulting postfix expression is printed.
3. `evaluatePostfix()` is called to compute the value of the postfix expression.
4. The final evaluated result is printed.

---

## Sample Output

```c
    Postfix Expression: 32+1/21-2*+
    Result: 7
```

---
