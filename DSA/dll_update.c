#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

struct dllnode
{
  int info;
  struct dllnode *next, *prev;
};

// global head pointing to list
struct dllnode *head = NULL;

// Creation of NODE:
struct dllnode *CreateNode()
{
  struct dllnode *newNode;
  int val;
  newNode = (struct dllnode *)malloc(sizeof(struct dllnode));
  printf("\nEnter the value to be inserted: ");
  scanf("%d", &val);

  newNode->info = val;
  newNode->next = NULL;
  newNode->prev = NULL;
  return (newNode);
}
// Creation of doublelink list:
struct dllnode *Createdll(struct dllnode *head_temp)
{
  int val, ch = 0;
  struct dllnode *ptr_newNode, *qtr_traverse;
  do
  {
    ptr_newNode = CreateNode();
    if (head_temp == NULL)
      head_temp = ptr_newNode;
    else
    {
      qtr_traverse = head_temp;
      while (qtr_traverse->next != NULL)
      {
        qtr_traverse = qtr_traverse->next;
      }
      qtr_traverse->next = ptr_newNode; // inside else, & after while loop
      ptr_newNode->prev = qtr_traverse;
    }
    printf("Do you want to add more values:(0/1)");
    scanf("%d", &ch);
  } while (ch != 0);
  return (head_temp);
}

// Display a doubly link list:
struct dllnode *Displaydll(struct dllnode *head_temp)
{
  struct dllnode *ptr;
  ptr = head_temp;
  if (ptr == NULL)
    printf("List is Empty\n");
  else
  {
    while (ptr != NULL)
    {
      printf("  %d  ", ptr->info);
      ptr = ptr->next;
      // ptr->prev=ptr; //for reverse print ,& for this head should be tail
    }
  }
  return (head_temp); // optional
}

// Insert at FIRST
struct dllnode *InsertatFirst(struct dllnode *head)
{
  struct dllnode *newNode;
  newNode = CreateNode();
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
  return (head);
}

// Insert at END:
struct dllnode *InsertatEnd(struct dllnode *head)
{
  struct dllnode *newNode, *ptr_traverse;
  newNode = CreateNode();
  ptr_traverse = head;
  while (ptr_traverse->next != NULL)
  {
    ptr_traverse = ptr_traverse->next;
  } // at last node
  ptr_traverse->next = newNode;
  newNode->prev = ptr_traverse;
  newNode->next = NULL;

  return (head);
}

// Insert At Between:
struct dllnode *InsertatBetween(struct dllnode *head, int pos)
{
  struct dllnode *newNode, *ptr_traverse, *qtr_tmp;
  ptr_traverse = head;
  int count = 1;
  newNode = CreateNode();
  while (count < (pos - 1)) // or (count <= pos-2)
  {
    ptr_traverse = ptr_traverse->next;
    count++;
  }
  /*  qtr_tmp = ptr_traverse->next; // storing pos node,,the while loop exits at pos-1 node
   ptr_traverse->next = newNode; // pos-1 now point to newnode
   newNode->prev = ptr_traverse;
   newNode->next = qtr_tmp;
   qtr_tmp->prev = newNode; */

  // Alternative way ,without temp qtr

  newNode->next = ptr_traverse->next;
  newNode->prev = ptr_traverse;
  ptr_traverse->next->prev = newNode;
  ptr_traverse->next = newNode;

  return (head);
}

// Update the NODE:
struct dllnode *UpdateNode(struct dllnode *head, int oldvalue, int newvalue)
{
  struct dllnode *ptr_traverse;
  ptr_traverse = head;
  while (ptr_traverse->next != NULL)
  {
    if (ptr_traverse->info == oldvalue)
      ptr_traverse->info = newvalue;
    ptr_traverse = ptr_traverse->next;
  }
  return (head);
}

// delete the first Node:
struct dllnode *DeleteatFirst(struct dllnode *head)
{
  struct dllnode *tmp = head;
  head = head->next;
  head->prev = NULL;
  free(tmp); // deallocate
  return (head);
}

// Delete the last Node:
struct dllnode *DeleteatEnd(struct dllnode *head)
{
  struct dllnode *ptr = head;
  struct dllnode *tmp;
  while (ptr->next->next != NULL)
  {
    ptr = ptr->next;
  }
  tmp = ptr->next;
  ptr->next = NULL;
  free(tmp);
  return (head);
}

// Delete in Between:
struct dllnode *DeleteinBetween(struct dllnode *head, int position)
{
  struct dllnode *ptr_trv, *qtr;
  ptr_trv = head;
  int count = 1;
  while (count < (position - 1))
  {
    ptr_trv = ptr_trv->next;
    count++;
  }
  qtr = ptr_trv->next;
  ptr_trv->next = qtr->next;
  ptr_trv->next->prev = ptr_trv;
  free(qtr);
  return (head);
}

int main()
{
  int ch1, pos, oldvalue, newvalue, position;
  printf("\n--------PROGRAM TO CREATE DOUBLE LINKED LIST-------\n");
  do
  {
    printf("\n1.......Create List");
    printf("\n2........Display List");
    printf("\n3........Insert at First");
    printf("\n4.........Insert at End");
    printf("\n5.........Insert in Between");
    printf("\n6.........Update the Node");
    printf("\n7.........Delete the first Node");
    printf("\n8.........Delete the last Node");
    printf("\n9.........Delete in between");
    printf("\n0.........Exit");
    printf("\nEnter your choice: ");

    scanf("%d", &ch1);

    switch (ch1)
    {
    case 1:
      head = Createdll(head);
      break;
    case 2:
      head = Displaydll(head);
      break;
    case 3:
      head = InsertatFirst(head);
      break;
    case 4:
      head = InsertatEnd(head);
      break;
    case 5:
      printf("\nEnter the position to insert a new node:");
      scanf("%d", &pos);
      head = InsertatBetween(head, pos);
      break;
    case 6:
      printf("\nEnter the node value to be updated:");
      scanf("%d", &oldvalue);
      printf("\nEnter the value to update:");
      scanf("%d", &newvalue);
      head = UpdateNode(head, oldvalue, newvalue);
      break;
    case 7:
      head = DeleteatFirst(head);
      break;
    case 8:
      head = DeleteatEnd(head);
      break;
    case 9:
      printf("\nEnter the position to delete");
      scanf("%d", &position);
      head = DeleteinBetween(head, position);
      break;
    case 0:
      printf("\n-------EXIT---------\n");
      exit(0);
    }
  } while (1);
}