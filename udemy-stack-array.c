/* array stacks are fixed in size, cannot grow dynamically */

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE (5)

typedef struct Stack
{
  int stk[MAX_SIZE];
  int top; /* represent the top of the stack */
} stack_t;

// protos
void push(stack_t *head, int val);
int pop(stack_t *head);
void display(stack_t *head);
int empty(stack_t *head);

void push(stack_t *head, int val)
{
  if ((*head).top == (MAX_SIZE - 1))
  {
    printf("stack is full\n");
    return;
  }
  else
  {
    (*head).top = (*head).top + 1;
    (*head).stk[(*head).top] = val;
  }

  return;
}

int pop(stack_t *head)
{
  if ((*head).top == -1)
  {
    // printf("stack is empty\n");
    return (*head).top;
  }
  else
  {
    int num = (*head).stk[(*head).top];
    (*head).top = (*head).top - 1;
    return num;
  }
}

void display(stack_t *head)
{
  if ((*head).top == -1)
  {
    printf("-------------\n");
    printf("stack empty\n");
    printf("-------------\n");
    return;
  }

  int i = 0;
  printf("-------------\n");

  for (i = (*head).top; i >= 0; i--)
  {
    printf("%d\n", (*head).stk[i]);
    printf("-------------\n");
  }
}

int main(void)
{
  int choice = -1;
  int userinput = 0;
  stack_t start;
  start.top = -1;

  printf("-------------------------\n");
  printf("    1   -->   PUSH      \n");
  printf("    2   -->   POP       \n");
  printf("    3   -->   EXIT      \n");
  printf("-------------------------\n");
  while (choice != 3)
  {
    printf("enter a choice: ");
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
      printf("enter a val: ");
      scanf(" %d", &userinput);
      push(&start, userinput);
      display(&start);
      break;
    case 2:
      pop(&start);
      display(&start);
      break;
    case 3:
      printf("exiting...\n");
      break;
    }
  }

  return 0;
}