#include <stdio.h>
#include <malloc.h>

struct intNode {
  int value;
  intNode *next; //采用C++句法，定义结构成员
};

/* 建立正整数链表的函数可以放在这里 */
intNode *createList(int n) {
  intNode *head, *tail, *p;
  int k;
  head = tail = NULL;   
  printf("Input data.\n");
  for(k = 0; k < n; k++) {
    p = (intNode *) malloc(sizeof(intNode));
    scanf("%d", &p->value);
    if (head == NULL) {
      head = tail = p;
    } else {
      tail = tail->next = p;
    }
  }
  if (tail) {
    tail->next  = NULL;/*末表元之后为空*/
  }
  return head;
}

/* 主函数 */
int main() {
  intNode *p, *q; //采用C++句法，定义结构指针
  int n;
  printf("Input the number of elements: \n");
  scanf("%d", &n);
  q = createList (n); /* 当函数返回时，q为头指针 */
  while (q) {
   printf("%d\n",q->value); //依次显示链表中的表元值
   p = q->next;  /*保存后继表元指针*/
   free(q); /*删除当前表元*/
   q = p;  /*后继表元成为当前表元*/
  }

  return 0;
}

