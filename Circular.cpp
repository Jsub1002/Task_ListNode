#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void print_list(ListNode* head)
{
    ListNode* p;

    if (head == NULL) return;
    p = head->link;
    do {
        printf("%d->", p->data);
        p = p->link;
    } while (p != head);
    printf("%d->", p->data);
}

ListNode* insert_first(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
    }
    return head;
}

ListNode* insert_last(ListNode* head, element data)
{
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->data = data;
    if (head == NULL) {
        head = node;
        node->link = head;
    }
    else {
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

ListNode* search(ListNode* L, element data) {
   ListNode* p;
   for (p = L->link; p != L; p = p->link) {
      if (p->data == data)
         return p;
   }
   return NULL;
}

int main(void)
{
   int *arr;
   int n;
   int i,j,k;

   printf("배열의 크기 : ");
   scanf("%d", &n);

   arr = (int*)malloc(sizeof(int) * n);

   printf("입력값 :");
   for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    ListNode *a = NULL;

    a = insert_first(a, arr[0]);

    for (j = 1; j < n; j++) {
    a = insert_last(a, arr[j]);
    }

    printf("찾고싶은 수 :");
    scanf("%d", &k);
    if(search(a, k)!=NULL) 
        printf("찾으시는 수 %d가 리스트 내에 존재합니다.", k);
    else 
        printf("찾으시는 수 %d가 리스트 내에 없습니다.", k);
    
    return 0;
}