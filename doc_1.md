# DOCUMENTATION (prog_1.c)

## Logic

To check if the parentheses in an expression are valid, the latest opening parenthesis must always close first. For example:

```c
    a + [b + (c - d)]
```

Here, the last opening parenthesis `(` must be closed before the square bracket `[`. This behavior follows the **LIFO (Last-In First-Out)** principle of stacks. Therefore, we use a stack to perform the operations required to check for valid parentheses.

---

## Data Structure Implementation

A standard character stack is used in the program. It contains:
- An array of characters to store the parentheses.
- A `top` index to track the current top of the stack.

The stack is defined using a structure:

```c
    typedef struct {
        char data[MAX_SIZE]; //MAX_SIZE is defined as the maximum size of the array
        int top;
    } Stack;
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
    Removes the top element from the stack. If the stack is empty, it prints "Stack Underflow" and does nothing.

6. `peek(Stack* s):`
    Returns the character at the top of the stack without removing it. If the stack is empty, it prints a warning and returns `'\0'`.

7. `rev(char c):`
    Returns the corresponding opening parenthesis for a closing parenthesis.

8. `areParenthesesValid(char c[]):`
    This function checks whether the parentheses in an expression are balanced.
    - It traverses the expression character by character.
    - Opening parenthesis are pushed onto the stack.
    - Closing parenthesis are compared with the top of the stack.
        - If it matches, the opening parenthesis is popped.
        - If it does not match or the stack is empty, the expression is invalid.
    - After processing the entire expression, the expression is valid only if the stack has been emptied.

---

## main() Function

The `main()` function demonstrates the program using three sample expressions:

```c
    char c1[] = "a+(b-c)*(d";
    char c2[] = "m+[a-b*(c+d*{m)]";
    char c3[] = "a+(b-c)";
```

For each expression:
1. `areParenthesesValid()` is called.
2. If it returns true, the expression is printed as valid; otherwise, it is printed not valid.

---

## Sample Output

```c
    c1 is not valid.
    c2 is not valid.
    c3 is valid.
```

---
