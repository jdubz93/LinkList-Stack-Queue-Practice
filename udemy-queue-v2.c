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

qnode_t *CreateQNode(int key_)
{
  qnode_t *temp = malloc(sizeof(qnode_t));
  temp->key = key_;
  temp->next = NULL;
  return temp;
}

queue_t *CreateQueue(qnode_t *node)
{
  queue_t *new_queue = malloc(sizeof(queue_t));
  new_queue->front = node;
  new_queue->rear = node;

  return new_queue;
}

// FIFO
/*
 when I add (enqueue) a new node, it gets placed at the rear.
 When I remove (dequeue) a node, it gets removed from the front.
*/
void EnQueue(queue_t *myqueue_, qnode_t *newnode)
{
  if (myqueue_ == NULL)
  {
    printf("queue not initialized\n");
    return;
  }

  if (myqueue_->rear == NULL)
  {
    myqueue_->front = newnode;
    myqueue_->rear = newnode;
    return;
  }

  myqueue_->rear->next = newnode;
  /*
   * Once I add the new node
   * to the end of the queue (as shown above),
   * I need to update the rear pointer to now
   * point to the new node.
   */
  myqueue_->rear = newnode;
}

/*
 When I remove (dequeue) a node, it gets removed from the front.
*/
qnode_t *DeQueue(queue_t *myqueue_)
{
  if (myqueue_->front == NULL)
  {
    // printf("queue is empty\n");
    return NULL;
  }
  qnode_t *dequeue_node = myqueue_->front;
  myqueue_->front = myqueue_->front->next;

  if (myqueue_->front == NULL)
    myqueue_->rear = NULL;

  return dequeue_node;
}

void PrintQueue(queue_t *myqueue_)
{
  if (myqueue_->front == NULL)
  {
    printf("queue is empty\n");
    return;
  }

  qnode_t *tmp = myqueue_->front;
  printf("---------------------\n");
  while (tmp != NULL)
  {
    printf("%d\n", tmp->key);
    tmp = tmp->next;
    printf("---------------------\n");
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
  qnode_t *my_node = CreateQNode(1);
  queue_t *my_queue = CreateQueue(my_node);

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
      qnode_t *qnode_test = CreateQNode(userinput);
      EnQueue(my_queue, qnode_test);
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
      exit(EXIT_SUCCESS);
    }
  }

  exit(EXIT_SUCCESS);
}