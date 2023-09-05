#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE (50)

/**************************
 * Static variables
 **************************/
int queue_array[MAXSIZE];
int rear_idx = -1;
int front_idx = -1;

void enqueue()
{
  int key = 0;

  if (rear_idx == MAXSIZE - 1)
  {
    printf("queue is full\n");
    return;
  }
  else
  {
    if (front_idx == -1)
      front_idx = 0;

    printf("Insert key into queue: ");
    scanf(" %d", &key);
    rear_idx = rear_idx + 1;
    queue_array[rear_idx] = key;
  }
}

int dequeue()
{
  int pop = -1;
  if (front_idx == -1 || front_idx > rear_idx)
  {
    printf("queue is empty\n");
    return pop;
  }
  else
  {
    pop = queue_array[front_idx];
    front_idx = front_idx + 1;

    return pop;
  }
}

void display()
{
  int i;
  if (front_idx == -1)
  {
    printf("queue is empty\n");
  }
  else
  {
    printf("--------\n");
    for (i = front_idx; i <= rear_idx; i++)
      printf("%d\n", queue_array[i]);
    printf("--------\n");
  }
}

void PrintMenu()
{
  printf("===============================\n");
  printf("    1   -->   ENQUEUE      \n");
  printf("    2   -->   DEQUEUE      \n");
  printf("    3   -->   EXIT         \n");
  printf("===============================\n");
}

int main(void)
{
  int choice = -1;
  int userinput = 0;

  while (1)
  {
    PrintMenu();
    printf("enter a choice: ");
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
      enqueue();
      display();
      break;
    case 2:
      printf("\n");
      int deq = dequeue();
      printf("Key dequeue'd: %d\n", deq);
      printf("\n");
      display();
      break;
    case 3:
      printf("exiting...\n");
      exit(EXIT_SUCCESS);
    }
  }
  return 0;
}