#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct ListNode {
   int data;
   struct ListNode* link;
} ListNode;

ListNode* insert_last(ListNode* head, int data)
{
   ListNode* node = (ListNode*)malloc(sizeof(ListNode));
   node->data = data;
   ListNode* p = head;
   if (head == NULL) {
      node->link = head;
      head = node;
   }
   else {
      while (p->link != NULL) {
         p = p->link;
      }
      p->link = node;
      node->link = NULL;
   }
   return head;
}

void split(ListNode* ahead, ListNode **bhead, ListNode **chead, ListNode **dhead)
{
   ListNode *p = ahead;
   if (ahead == NULL) return;
   while (p != NULL) {
      *bhead = insert_last(*bhead, p->data);
      p = p->link;
      if (p == NULL)  break;
      *chead = insert_last(*chead, p->data);
      p = p->link;
      if (p == NULL)  break;
      *dhead = insert_last(*dhead, p->data);
      p = p->link;
   }
}

void print_list(ListNode* head)
{
   if (head == NULL) return;
   for (ListNode* p = head; p != NULL; p = p->link)
      printf("%d->", p->data);
   printf("NULL\n");
}

int main(void)
{
   int *arr;
   int n;
   int i;

   printf("배열의 크기 : ");
   scanf("%d", &n);

   arr = (int*)malloc(sizeof(int) * n);

   printf("입력값 :");
   for (i = 0; i < n; i++) scanf("%d", &arr[i]);

   ListNode* a = NULL;
   ListNode* b = NULL;
   ListNode* c = NULL;
   ListNode* d = NULL;

   for (int i = 0; i <= n-1; i++) a = insert_last(a, arr[i]);
   printf("리스트 A = ");
   print_list(a);
   split(a, &b, &c, &d);
   printf("리스트 B = ");
   print_list(b);
   printf("리스트 C = ");
   print_list(c);
   printf("리스트 D = ");
   print_list(d);

   free(arr);

   return 0;
}
