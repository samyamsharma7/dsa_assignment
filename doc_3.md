# DOCUMENTATION (prog_3.c)

## Logic

Reverse traversal means visiting and printing the elements of a linked list from the last node to the first node, without modifying the original list structure.

Since a singly linked list cannot be traversed backward directly, recursion is used to achieve reverse traversal. 

The algorithm works as follows:

1. Start from the head node of the linked list.
2. Recursively call the function for the next node until the end of the list (`NULL`) is reached.
3. Once the recursion reaches the end, the recursion stack starts to unwind.
4. During this unwinding phase, each node's data is printed.
5. This results in elements being printed in reverse order (tail->head).

---

## Data Structure Implementation

A singly linked list is used in the program.

### Node Structure

Each node contains:
- An integer data field
- A pointer to the next node

```c
    typedef struct Node{
        int data;
        struct Node* nextNode;
    } Node;
```

### Linked List Structure

The linked list maintains:
- A pointer to the first node (`head`)
- A pointer to the last node (`tail`)

```c
    typedef struct{
        Node *head, *tail;
    } LL;
```

---

## Functions Used

1. `initLL(LL* list):`
    Initializes the linked list by setting both `head` and `tail` to `NULL`.

2. `insertBegin(LL* list, int value):`
    Inserts a new node at the beginning of the linked list by dynamically allocating memory for the new node using `malloc`, assigning the given value to the node, and updating the `head` pointer to point to the newly created node. If the list is initially empty, both `head` and `tail` are updated to point to the new node.

3. `printLL(LL* list):`
    Displays the linked list in forward order starting from the `head`.

4. `reverseTraversal(Node* current):`
    Performs the reverse traversal of a singly linked list using recursion. It recursively calls itself for the next node until a `NULL` pointer is reached, indicating the end of the list. As the recursive calls return, the data of each node is printed, resulting in the elements being displayed in the reverse order. The function does not modify the structure of the linked list.

5. `freeLL(LL* list):`
    Frees all dynamically allocated memory used by the linked list and prevents memory leaks.

---

## main() Function

The `main()` function demonstrates the working of reverse traversal:

1. Initializes the linked list using `initLL()`.
2. Inserts elements at the beginning of the list using `insertBegin()`.
3. Prints the linked list (forward order) using `printLL()`.
4. Performs reverse traversal with `reverseTraversal()`.
5. Frees all allocated memory using `freeLL()` before program termination.

```c
    insertBegin(&list, 1);
    insertBegin(&list, 2);
    insertBegin(&list, 3);
```

This implies that the elements (in the linked list) will be aligned in the following format:

```c
    3   2   1   NULL
```

---

## Sample Output

```c
    [ 3 -> 2 -> 1 -> NULL]

    Reverse Traversal:
    1   2   3
```