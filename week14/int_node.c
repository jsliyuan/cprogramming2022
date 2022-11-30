#include <stdio.h>
#include <stdlib.h>

/* 整数链表表元类型 */
struct intNode {
  int value ;  /* 存放整数 */
  struct intNode *next ; /* 存放后继表元的指针 */
};

void traverse(struct intNode* p) {
  while (p != NULL) {
    printf("%d\n", p->value);
    p = p->next;
  }
}

/*
// Insert a new node at the beginning.
void insert_beginning(struct intNode* head, struct intNode* new_node) {
}

// Insert a new node at the end of the linked list.
void insert_beginning(struct intNode* head, struct intNode* new_node) {
}
*/

int main() {
  struct intNode *p;
  p=(struct intNode*) malloc(sizeof(struct intNode));
  p->value = 0;
  p->next = NULL;

  struct intNode *q;
  q=(struct intNode*) malloc(sizeof(struct intNode));
  q->value = 1;
  q->next = NULL;
  p->next = q;

  traverse(p);
  return 0;
}