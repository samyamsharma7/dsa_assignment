# DOCUMENTATION (prog_4.c)

## Logic

A doubly linked list is a linear data structure in which each node contains three parts: data, a pointer to the next node, and a pointer to the previous node. This allows traversal in both forward and reverse directions.

The program demonstrates the implementation of a doubly linked list using structures and supports the following operations:

- Insertion at the beginning of the list
- Insertion after a given node
- Deletion of a specific node
- Displaying the list contents

---

## Data Structure Implementation

A doubly linked list is used in the program.

### Node Structure

Each node contains:
- an integer data field
- a pointer to the next node
- a pointer to the previous node

```c
    typedef struct Node{
        int data;
        struct Node *prevNode;
        struct Node *nextNode;
    } Node;
```

### Linked List Structure

The linked list maintains:
- a pointer to the first node(`head`)
- a pointer to the last node (`tail`)

```c
    typedef struct{
        Node *head, *tail;
    } LL;
```

---

## Functions Used

1. `initLL(LL* list):`
    Initializes the doubly linked list by setting both `head` and `tail` pointers to `NULL`, indicating an empty list.

2. `insertBegin(LL* list, int value):`
    Inserts a new node at the beginning of the list. Memory is allocated dynamically for the new node, and its pointers are updated accordingly. If the list is initially empty, both `head` and `tail` are set to the new node.

3. `insertAfterNode(LL* list, Node* given, int value):`
    Inserts a new node after a specified node in the doubly linked list. If the given node is a tail, the new node becomes the new tail. Otherwise, the pointers of the surrounding nodes are updated to maintain the bidirectional links.

4. `deleteNode(LL* list, Node* given):`
    Deletes a specified node from the list. The function handles all possibles cases:
    - Deleting the only node in the list
    - Deleting the head node
    - Deleting the tail node
    - Deleting a node from the middle of the list
    Memory occupied by the deleted node is freed to prevent memory leaks.

5. `printLL(LL* list):`
    Displays the elements of the list in forward order.

---

## main() Function

The `main()` function demonstrates the working of the doubly linked list operations:
1. Initializes the linked list using `initLL()`.
2. Inserts elements at the beginning of the list using `insertBegin()`.
3. Inserts a new node after a given node using `insertAfterNode()`.
3. Deletes a specific node from the list using `deleteNode()`.    
4. Prints the final state of the doubly linked list using `printLL()`.

```c
    initLL(&list);

    insertBegin(&list, 1);
    insertBegin(&list, 2);
    insertBegin(&list, 3);
    insertAfterNode(&list, list.head->nextNode, 4);

    deleteNode(&list, list.head->nextNode);

    printLL(&list);
```

---

## Sample Output

```c
    [ NULL <-> 3 <-> 4 <-> 1 <-> NULL]
```