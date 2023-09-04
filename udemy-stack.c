#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct Node
{
  int data;
  struct Node *next;
} node_t;

typedef node_t *top;

// push/pop/display/isempty

bool empty(top *head)
{
  return (*head == NULL);
}

void push(top *head, int val)
{
  top new_node = malloc(sizeof(node_t));
  if (new_node == NULL)
  {
    perror("failed to allocate memory for new node");
    return;
  }

  new_node->data = val;
  new_node->next = *head;
  *head = new_node;
  // top new_node = *head;
}

void pop(top *head)
{
  if (*head == NULL)
  {
    return;
  }

  if ((*head)->next == NULL)
  {
    *head = NULL;
    return;
  }

  *head = (*head)->next;
}

void display(top *head)
{
  if (empty(head))
  {
    printf("----------\n");
    printf("empty stack\n");
    printf("----------\n");
    return;
  }
  else
  {
    top new_node = *head;
    printf("----------\n");
    while (new_node != NULL)
    {
      printf("%d\n", new_node->data);
      printf("----------\n");
      new_node = new_node->next;
    }
  }
}

int main(void)
{
  top startnode = NULL;
  int val = 0;
  int userinput = 0;

  printf("\nMenu: \n"
         "1) to push element to stack.\n"
         "2) to pop element from stack.\n"
         "3) maybe search.\n"
         "4) something else idk.\n"
         "5) to exit\n");

  while (userinput != 5)
  {
    printf("Enter a choice: ");
    scanf(" %d", &userinput);
    switch (userinput)
    {
    case 1:
      printf("enter a value: ");
      scanf(" %d", &val);
      push(&startnode, val);
      display(&startnode);
      break;
    case 2:
      pop(&startnode);
      display(&startnode);
      break;
    case 3:
      printf("not implemented yet\n");
      break;
    case 4:
      printf("not implemented yet\n");
      break;
    case 5:
      printf("exiting...\n");
      break;
    }
  }
}