#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct Node
{
  char data;
  struct Node *next;
} node_t;

typedef node_t *ListNodePtr;

// function prototypes
void Insert(ListNodePtr *head, char val);
void InsertAtBeginning(ListNodePtr *head, char val);
void InsertAtEnd(ListNodePtr *head, char val);
void DeleteAtBeginning(ListNodePtr *head);
void DeleteAtEnd(ListNodePtr *head);
void Delete(ListNodePtr *head, char val);
void Search(ListNodePtr *head, char val);
void Update(ListNodePtr *head, char val, char newval);
void PrintList(ListNodePtr *head);
bool Empty(ListNodePtr *head);

void Insert(ListNodePtr *head, char val)
{
  ListNodePtr new_node = malloc(sizeof(node_t));
  if (new_node == NULL)
  {
    perror("failed to allocate memory");
    return;
  }

  new_node->data = val;
  new_node->next = NULL;

  if (*head == NULL)
  {
    *head = new_node;
    return;
  }

  if (val < (*head)->data)
  {
    new_node->next = *head;
    *head = new_node;
  }

  ListNodePtr prev = *head;
  ListNodePtr curr = (*head)->next;
  while (curr != NULL && val > curr->data)
  {
    prev = curr;
    curr = curr->next;
  }

  // new_node->next = curr;
  prev->next = new_node;
  new_node->next = curr;
}

void InsertAtEnd(ListNodePtr *head, char val)
{
  ListNodePtr new_node = malloc(sizeof(node_t));

  if (new_node == NULL)
  {
    perror("failed to allocate memory");
    return;
  }

  new_node->data = val;
  new_node->next = NULL;

  ListNodePtr curr = *head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }

  curr->next = new_node;
}

void InsertAtBeginning(ListNodePtr *head, char val)
{
  ListNodePtr new_node = malloc(sizeof(node_t));

  if (new_node == NULL)
  {
    perror("failed to allocate memory");
    return;
  }

  new_node->data = val;
  new_node->next = *head;

  *head = new_node;
}

void DeleteAtBeginning(ListNodePtr *head)
{
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  ListNodePtr curr = *head;

  curr = curr->next;
  *head = curr;
}

void DeleteAtEnd(ListNodePtr *head)
{
  if (*head == NULL)
  {
    printf("lsit is empty\n");
    return;
  }

  if ((*head)->next == NULL)
  {
    *head = NULL;
    return;
  }

  ListNodePtr curr = *head;
  ListNodePtr prev = NULL;

  while (curr->next != NULL)
  {
    prev = curr;
    curr = curr->next;
  }
  prev->next = NULL;
  free(curr);
}

void Delete(ListNodePtr *head, char val)
{
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  if ((*head)->next == NULL)
  {
    *head = NULL;
    return;
  }

  ListNodePtr curr = *head;
  ListNodePtr prev = NULL;

  while (curr->next != NULL && val != curr->data)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr->data != val)
  {
    printf("%c not found.\n", val);
    return;
  }
  else
  {
    prev->next = curr->next;
    free(curr);
    return;
  }
}

void Search(ListNodePtr *head, char val)
{
  if (*head == NULL)
  {
    printf("list empty\n");
    return;
  }

  if ((*head)->data == val)
  {
    printf("%c found!\n", val);
    return;
  }

  ListNodePtr curr = *head;
  while (curr->next != NULL && curr->data != val)
  {
    curr = curr->next;
  }

  if (curr->data != val)
  {
    printf("%c not found!\n", val);
    return;
  }
  else
  {
    printf("%c found!\n", curr->data);
    return;
  }
}

void Update(ListNodePtr *head, char key, char val)
{
  // todo
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  if ((*head)->data == key)
  {
    (*head)->data = val;
    return;
  }

  ListNodePtr curr = *head;
  ListNodePtr prev = NULL;

  while (curr->next != NULL && key != curr->data)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr->data != key)
  {
    printf("did not find %c, could not update", key);
    return;
  }
  else
  {
    curr->data = val;
  }
}

void PrintList(ListNodePtr *head)
{
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  ListNodePtr temp = *head;

  while (temp != NULL)
  {
    printf("%c --> ", temp->data);
    temp = temp->next;
  }

  printf("NULL\n");
}

int main(void)
{
  int user_input = 0;
  char value = '\0';
  char key = '\0';
  ListNodePtr startptr = NULL;
  printf("\nMenu: \n"
         "1) to insert an element in sorted order.\n"
         "2) to insert an element at beginning.\n"
         "3) to insert an element at end.\n"
         "4) to delete an element at value index.\n"
         "5) to delete an element at beginning.\n"
         "6) to delete an element at end.\n"
         "7) to search for an element in list\n"
         "8) to update an element value in list\n"
         "9) to exit\n");

  while (user_input != 9)
  {
    printf("Enter a choice: ");
    scanf("%d", &user_input);

    switch (user_input)
    {
    case 1:
      printf("enter a char: ");
      scanf(" %c", &value);
      Insert(&startptr, value);
      PrintList(&startptr);
      break;

    case 2:
      printf("enter a char: ");
      scanf(" %c", &value);
      InsertAtBeginning(&startptr, value);
      PrintList(&startptr);
      break;

    case 3:
      printf("enter a char: ");
      scanf(" %c", &value);
      InsertAtEnd(&startptr, value);
      PrintList(&startptr);
      break;

    case 4:
      printf("enter a char: ");
      scanf(" %c", &value);
      Delete(&startptr, value);
      PrintList(&startptr);
      break;

    case 5:
      DeleteAtBeginning(&startptr);
      PrintList(&startptr);
      break;

    case 6:
      DeleteAtEnd(&startptr);
      PrintList(&startptr);
      break;

    case 7:
      printf("enter a char: ");
      scanf(" %c", &value);
      Search(&startptr, value);
      break;

    case 8:
      printf("enter a char to search for: ");
      scanf(" %c", &key);
      printf("enter a char to update to: ");
      scanf(" %c", &value);
      Update(&startptr, key, value);
      PrintList(&startptr);
      break;

    case 9:
      printf("exiting...\n");
      break;
    }
  }

  return 0;
}