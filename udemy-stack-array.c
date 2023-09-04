/* array stacks are fixed in size, cannot grow dynamically */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
void PrintMenu();
// int empty(stack_t *head);

// void push(stack_t *head, int val)
// {
//   if ((*head).top == (MAX_SIZE - 1))
//   {
//     printf("stack is full\n");
//     return;
//   }
//   else
//   {
//     (*head).top = (*head).top + 1;
//     (*head).stk[(*head).top] = val;
//   }
//   return;
// }
void push(stack_t *head, int val)
{
  if (head->top == (MAX_SIZE - 1))
  {
    printf("stack is full\n");
    return;
  }
  else
  {
    head->top = head->top + 1;
    head->stk[head->top] = val;
    display(head);
  }

  return;
}

int pop(stack_t *head)
{
  if (head->top == -1)
  {
    // return head->top;
    printf("error: cannot pop from an empty stack!\n");
    return head->top;
  }
  else
  {
    int num = head->stk[head->top];
    head->top = head->top - 1;
    return num;
  }
}

void display(stack_t *head)
{
  if (head->top == -1)
  {
    printf("-------------\n");
    printf("stack empty\n");
    printf("-------------\n");
    return;
  }

  int i = 0;
  printf("-------------\n");

  for (i = head->top; i >= 0; i--)
  {
    printf("%d\n", head->stk[i]);
    printf("-------------\n");
  }
}

void PrintMenu()
{
  printf("===============================\n");
  printf("    1   -->   PUSH      \n");
  printf("    2   -->   POP       \n");
  printf("    3   -->   EXIT      \n");
  printf("===============================\n");
}

int main(void)
{
  int choice = -1;
  int userinput = 0;
  stack_t start;
  start.top = -1;

  while (true)
  {
    PrintMenu();
    printf("enter a choice: ");
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
      printf("enter a val: ");
      scanf(" %d", &userinput);
      push(&start, userinput);
      break;
    case 2:
      printf("\n");
      printf("value popped: %d\n\n", pop(&start));
      display(&start);
      break;
    case 3:
      printf("exiting...\n");
      return 0;
    }
  }

  return 0;
}