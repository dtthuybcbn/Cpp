/****
* Question interviewed by Google:
* Implement a XOR linked list
* It has add(element) which adds the element to the end
* and get (index) which returns the node in index
*****/
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

struct Node {
   int value;
   struct Node *addr;
};
struct Node *XOR (struct Node *a, struct Node *b)
{
  return (struct Node*) ((uintptr_t) a ^ (uintptr_t) b); 
}
void printList(struct Node *head);
void add(struct Node **head, int val);
int get(struct Node* head, int index);
int main()
{
   struct Node *head = NULL;
   int value = 0;
   //1. Make a XOR linked list
   add(&head, 100);
   add(&head, 10);
   add(&head, 13);
   add(&head, 25);
   //2. Debug
   printList(head);
   
   //3. Test the get(index)
   printf("Test the get(index) function:\n"); 
   value = get(head,0);
   printf("Value [0]: %d\n", value);
   value = get(head,3);
   printf("Value [3]: %d\n", value);
   return 0;
}

void printList(struct Node *head)
{
   struct Node *curr = head;
   struct Node *prev = NULL;
   struct Node *next = XOR(NULL,head->addr);

   while (curr != NULL)
   {
      printf("%d\t", curr->value);
      next = XOR (prev, curr->addr);
      prev = curr;
      curr = next;
      
   }
   printf("\n");
}
void add(struct Node **head, int val)
{
   struct Node *node = (struct Node *)malloc(sizeof (struct Node));
   if (node == NULL)
   {  
      printf("Cannot allocate memory\n");
      return;
   }
   node->value = val;
   node->addr = XOR(NULL,*head);
   if (*head != NULL)
   {
      struct Node *next = XOR (NULL, (*head)->addr); // next of head
      (*head)->addr = XOR(node, next);
   }
   *head = node;
   
   return;
}

int get(struct Node *head, int index)
{
   if (head == NULL) 
   {
      return -1;
   }
   struct Node *curr = head;
   struct Node *prev = NULL;
   struct Node *next = XOR(NULL,head->addr);
   int i = -1;
   while (curr != NULL)
   {
      i++;
      if (i == index)
      {
         return curr->value;
      }
      next = XOR(prev, curr->addr);
      prev = curr;
      curr = next;
   }
   return -1;
}
