# LinkListPractice

```bash

$ ./udemy-linklist

Menu:
1) to insert an element in sorted order.
2) to insert an element at beginning.
3) to insert an element at end.
4) to delete an element at value index.
5) to delete an element at beginning.
6) to delete an element at end.
7) to search for an element in list
8) to update an element value in list
9) to exit
Enter choice: 2
enter a char: a
entered: a
 a --> NULL
Enter choice: 2
enter a char: b
entered: b
 b --> a --> NULL
Enter choice: 2
enter a char: c
entered: c
 c --> b --> a --> NULL
Enter choice: 2
enter a char: z
entered: z
 z --> c --> b --> a --> NULL
Enter choice: 1
enter a char: g
 z --> g --> c --> b --> a --> NULL
Enter choice: 8
char to update: g
new char: l
 z --> l --> c --> b --> a --> NULL
Enter choice: 9
exiting...

```

### stack-array

```bash

enter a choice: 1
enter a val: 3
-------------
3
-------------
4
-------------
5
-------------
enter a choice: 2
-------------
4
-------------
5
-------------
enter a choice: 2
-------------
5
-------------
enter a choice: 2
-------------
stack empty
-------------
enter a choice: 2
-------------
stack empty
-------------
enter a choice: 3
exiting...


```

### circular queue array

```bash
--------
5
--------
===============================
    1   -->   ENQUEUE
    2   -->   DEQUEUE
    3   -->   EXIT
===============================
enter a choice: 4
debug print indexes:
front_idx: 4
rear_idx: 4
===============================
    1   -->   ENQUEUE
    2   -->   DEQUEUE
    3   -->   EXIT
===============================
enter a choice: 4
debug print indexes:
front_idx: 4
rear_idx: 4
===============================
    1   -->   ENQUEUE
    2   -->   DEQUEUE
    3   -->   EXIT
===============================
enter a choice: 2

Key dequeue'd: 5

queue is empty
===============================
    1   -->   ENQUEUE
    2   -->   DEQUEUE
    3   -->   EXIT
===============================
enter a choice: 4
debug print indexes:
front_idx: -1
rear_idx: -1
===============================
    1   -->   ENQUEUE
    2   -->   DEQUEUE
    3   -->   EXIT
===============================
enter a choice: 1
Insert key into queue: 2
--------
2
--------
===============================
    1   -->   ENQUEUE
    2   -->   DEQUEUE
    3   -->   EXIT
===============================
enter a choice:


```
