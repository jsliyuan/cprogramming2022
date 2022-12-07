#include  <stdio.h>
#include  <stdlib.h>
#include <math.h>

#define EPSILON  1.0e-5

struct Node  {
  int power;
  double coef;
  Node *link;
};

//多项式相加函数
void add_polynomial(Node *l, Node *k) {
  Node *p, *lpt, *kpt, *q;
  p = l;
  lpt = l->link;
  kpt  = k->link;
  while (kpt)    {
    if (lpt==NULL || lpt->power < kpt->power) {
      q = (Node *)malloc(sizeof(Node));
      q->power = kpt->power;
      q->coef  = kpt->coef;
      q->link  = lpt;
      p->link  = q;
      p        = q;
      kpt      = kpt->link;
    } else if(lpt->power==kpt->power) {//等幂次项系数相加
      lpt->coef += kpt->coef;
      if (fabs(lpt->coef) <= EPSILON)  {
        p->link = lpt->link;  free(lpt);
      } else {
        p = p->link;
      }
      lpt = p->link;  
      kpt = kpt->link;
    } else { /*lpt->power > kpt->power,跳过(*lpt)*/
      p   = lpt;
      lpt = lpt->link;
    }
  }
}

/* 以下是输入多项式的幂次和系数，构建多项式的单链表函数：*/
Node* create_polynomial() {
  Node *u, *w, *p, *h;
  int  n;

  /* 建立空的带辅助表元的单链表 */
  h = (Node *) malloc(sizeof(Node));
  h->link = NULL;
  printf("Input a polynomial: power and coefficient (exit if the power is negative)\n");
  scanf("%d", &n);  /* 输入幂次 */

  while (n >= 0) {
    double  coef;
    p = (Node *)malloc(sizeof(Node));
    p->power = n;
    scanf("%lf", &coef); /* 输入系数 */
    p->coef = coef;
    w = h; /* 以下寻找当前项的插入位置*/
    u = h->link;
    while (u != NULL && n < u->power)  {
      w = u;
      u = u->link;
    }
    w->link = p;   p->link = u;
    scanf("%d", &n);  /* 输入下一项的幂次 */
  }

  return h;
}

//输出多项式函数
void print_polynomial(Node *q) {
  q = q->link;
  printf("%.2lfx^%d ", q->coef, q->power); /* 多项式的首项 */
  q = q->link;
  while (q)  { /* 输出和多项式的其余项 */
    printf("+%.2lfx^%d ", q->coef, q->power);
    q = q->link;
  }
  printf("\n");
}

void free_polynomial(Node* p) {
  Node* q;
  while (p)   {
    q = p->link;
    free(p);
    p = q;
  }
}

int main() {
  Node *h1, *h2, *p, *q;

  h1 = create_polynomial();
  print_polynomial(h1);

  h2 = create_polynomial();
  print_polynomial(h2);

  add_polynomial(h1, h2);
  printf("Their sum is:\n");
  print_polynomial(h1);

  free_polynomial(h1);
  free_polynomial(h2);
  return 0;
}
