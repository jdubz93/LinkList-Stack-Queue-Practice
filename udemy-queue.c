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
  qnode_t *front;
  qnode_t *rear;
} queue_t;

qnode_t *NewNode(int key_)
{
  qnode_t *temp = (qnode_t *)malloc(sizeof(qnode_t));
  temp->key = key_;
  temp->next = NULL;
  return temp;
}

queue_t *CreateQueue(void)
{
  queue_t *que = malloc(sizeof(queue_t));
  que->rear = NULL;
  que->front = que->rear;
  return que;
}

void EnQueue(queue_t *que, int key_)
{
  qnode_t *new_node = NewNode(key_);

  if (que->rear == NULL)
  {
    que->rear = new_node;
    que->front = new_node;
    return;
  }

  que->rear->next = new_node;
  que->rear = new_node;
}

void PrintQueue(queue_t *que)
{
  // todo
  qnode_t *temp = que->front;
  if (temp == NULL)
  {
    printf("queue is empty\n");
    return;
  }

  printf("-------------------\n");
  while (temp != NULL)
  {
    printf("%d\n", temp->key);
    printf("-------------------\n");
    temp = temp->next;
  }
}

qnode_t *DeQueue(queue_t *que)
{
  // todo
  if (que->front == NULL)
  {
    return NULL;
  }

  qnode_t *temp = que->front;
  que->front = que->front->next;

  if (que->front == NULL)
  {
    que->rear = NULL;
  }

  return temp;
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
  queue_t *my_queue = CreateQueue();

  while (1)
  {
    PrintMenu();
    printf("enter a choice: ");
    scanf(" %d", &choice);
    switch (choice)
    {
    case 1:
      printf("enter a val: ");
      scanf(" %d", &userinput);
      qnode_t *qnode_test = NewNode(userinput);
      EnQueue(my_queue, qnode_test->key);
      PrintQueue(my_queue);
      break;
    case 2:
      printf("\n");
      qnode_t *ret_node = DeQueue(my_queue);
      if (ret_node == NULL)
        break;
      printf("value dequeued: %d\n", ret_node->key);
      PrintQueue(my_queue);
      break;
    case 3:
      printf("exiting...\n");
      return 0;
    }
  }

  // // todo
  // qnode_t *qnode_test = NewNode(6);
  // queue_t *my_queue = CreateQueue();
  // EnQueue(my_queue, qnode_test->key);
  // printf("added 6 to the queue\n");
  // EnQueue(my_queue, 5);
  // printf("added 5 to the queue\n");
  // EnQueue(my_queue, 3);
  // printf("added 3 to the queue\n");
  // PrintQueue(my_queue);
  // qnode_t *ret_node = DeQueue(my_queue);
  // if (ret_node != NULL)
  //   printf("dequeue = %d\n", ret_node->key);

  // ret_node = DeQueue(my_queue);
  // if (ret_node != NULL)
  //   printf("dequeue = %d\n", ret_node->key);

  // ret_node = DeQueue(my_queue);
  // if (ret_node != NULL)
  //   printf("dequeue = %d\n", ret_node->key);

  // ret_node = DeQueue(my_queue);
  // if (ret_node == NULL)
  //   printf("dequeue is null\n");

  return 0;
}