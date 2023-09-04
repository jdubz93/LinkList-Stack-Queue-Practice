#include <stdio.h>
#include <stdlib.h>

typedef struct QNode
{
  int key;
  struct QNode *next;
} qnode_t;

typedef struct Queue
{
  qnode_t *front;
  qnode_t *rear;
} queue_t;

int main(void)
{

  return 0;
}