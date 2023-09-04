/* 1. write a program that performs operations on a link list
 * - should perform the following:
 *  - insert node at first
 *  - insert node at last
 *  - insert node at position
 *  - delete node from any position
 *  - update node value
 *  - search element in a link list
 *  - display list
 *  - exit
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
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
void PrintList(ListNodePtr head);
bool Empty(ListNodePtr *head);

// implementation
void Insert(ListNodePtr *head, char val)
{
  ListNodePtr new_node = malloc(sizeof(node_t));
  if (new_node == NULL)
  {
    perror("failed to allocate memory for new node");
    return;
  }

  new_node->data = val;
  new_node->next = NULL;

  ListNodePtr prev = NULL;
  ListNodePtr curr = *head;

  // printf("curr = %c\n", curr->data);

  while (curr != NULL && val < curr->data)
  {
    prev = curr;
    curr = curr->next;
  }

  new_node->next = curr;
  prev->next = new_node;
  // printf("value of prev = %c\n", prev->data);
}

void InsertAtBeginning(ListNodePtr *head, char val)
{
  ListNodePtr new_node = malloc(sizeof(node_t));
  if (new_node == NULL)
  {
    perror("failed to allocate memory for new node");
    return;
  }

  if (*head == NULL)
  {
    new_node->data = val;
    new_node->next = NULL;
    *head = new_node;
  }
  else
  {
    ListNodePtr curr = *head;
    new_node->data = val;
    new_node->next = curr;
    *head = new_node;
  }
}

void InsertAtEnd(ListNodePtr *head, char val)
{
  ListNodePtr new_node = malloc(sizeof(node_t));
  if (new_node == NULL)
  {
    perror("Failed to allocate memory");
    return;
  }
  new_node->data = val;
  new_node->next = NULL;
  if (*head == NULL)
  {
    *head = new_node;
  }

  ListNodePtr curr = *head;
  while (curr->next != NULL)
  {
    curr = curr->next;
  }

  curr->next = new_node;
}

void DeleteAtBeginning(ListNodePtr *head)
{
  ListNodePtr tmp = NULL;

  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  tmp = *head;
  ListNodePtr new_list = *head;
  new_list = new_list->next;
  free(tmp);
  *head = new_list;
}

void DeleteAtEnd(ListNodePtr *head)
{
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  if ((*head)->next == NULL)
  {
    // only 1 item
    free(*head);
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
  // *head = prev;
}

void Delete(ListNodePtr *head, char val)
{
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  ListNodePtr prev = NULL;
  ListNodePtr curr = *head;

  if (curr != NULL && curr->data == val)
  {
    *head = curr->next;
    free(curr);
  }

  while (curr != NULL && curr->data != val)
  {
    prev = curr;
    curr = curr->next;
  }

  prev->next = curr->next;
  free(curr);

  // printf("curr = %c\n", curr->data);
}

void Search(ListNodePtr *head, char val)
{
  // todo
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  ListNodePtr curr = *head;
  while (curr != NULL && val != curr->data)
  {
    curr = curr->next;
  }

  if (curr == NULL)
  {
    printf("%c not found\n", val);
  }
  else
  {
    printf("%c found\n", curr->data);
  }
}

void Update(ListNodePtr *head, char val, char newval)
{
  if (*head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  ListNodePtr prev = NULL;
  ListNodePtr curr = *head;

  while (curr != NULL && val != curr->data)
  {
    prev = curr;
    curr = curr->next;
  }

  if (curr->data != val)
  {
    printf("%c not found", val);
    return;
  }
  else
  {
    curr->data = newval;
  }
}

void PrintList(ListNodePtr head)
{
  if (head == NULL)
  {
    printf("list is empty\n");
    return;
  }

  ListNodePtr cpy = malloc(sizeof(node_t));
  if (cpy == NULL)
  {
    perror("failed to allocate memory");
    return;
  }

  cpy = head;
  while (cpy != NULL)
  {
    printf(" %c -->", cpy->data);
    cpy = cpy->next;
  }

  printf(" NULL\n");
}

bool Empty(ListNodePtr *head)
{
  return (*head == NULL);
}

int main(void)
{
  char input = '\0';
  int choice = 0;
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

  while (choice != 9)
  {
    printf("Enter choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      // printf("not implemented\n");
      printf("enter a char: ");
      scanf(" %c", &input);
      Insert(&startptr, input);
      PrintList(startptr);
      break;

    case 2:
      printf("enter a char: ");
      scanf(" %c", &input);
      printf("entered: %c\n", input);
      InsertAtBeginning(&startptr, input);
      PrintList(startptr);
      break;

    case 3:
      printf("enter a char: ");
      scanf(" %c", &input);
      InsertAtEnd(&startptr, input);
      PrintList(startptr);
      break;

    case 4:
      // printf("not implemented\n");
      printf("enter a char: ");
      scanf(" %c", &input);
      Delete(&startptr, input);
      PrintList(startptr);
      break;

    case 5:
      DeleteAtBeginning(&startptr);
      PrintList(startptr);
      break;

    case 6:
      DeleteAtEnd(&startptr);
      PrintList(startptr);
      break;

    case 7:
      printf("enter a char: ");
      scanf(" %c", &input);
      Search(&startptr, input);
      break;

    case 8:
      printf("char to update: ");
      scanf(" %c", &input);
      printf("new char: ");
      char newval;
      scanf(" %c", &newval);
      Update(&startptr, input, newval);
      PrintList(startptr);
      break;

    case 9:
      printf("exiting...\n");
      break;

    default:
      printf("unknown option...\n");
      printf("\nis empty: %d\n", Empty(&startptr));
      break;
    }
  }

  exit(EXIT_SUCCESS);
}