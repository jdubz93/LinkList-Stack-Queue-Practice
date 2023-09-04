#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct QNode
{
  int key;
  struct QNode *next;
} qnode_t;

typedef struct Queue
{
  struct qnode_t *front;
  struct qnode_t *rear;
} queue_t;

qnode_t *NewNode(int key_)
{
  qnode_t *temp = (qnode_t *)malloc(sizeof(qnode_t));
  temp->key = key_;
  temp->next = NULL;
  return temp;
}

int main(void)
{
  // todo
  qnode_t *qnode_test = NewNode(6);
  printf("%d\n", qnode_test->key);
  return 0;
}