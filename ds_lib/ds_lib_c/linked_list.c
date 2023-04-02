#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node* next;
};

struct LinkedList {
  struct Node* HEAD;
  struct Node* TAIL;
  int len;
};

void traverse(struct LinkedList*);
void get_at(struct LinkedList*, int i);
void insert_first(struct LinkedList*, struct Node*);
void delete_first(struct LinkedList*);
void insert_last(struct LinkedList*, struct Node*);
void delete_last(struct LinkedList*);
void insert_at(struct LinkedList*, int i, struct Node*);
void delete_at(struct LinkedList*, int i);


int main() {
  struct LinkedList ll1; 
  struct Node n1;
  struct Node n2; 
  struct Node n3;
  n1.val = 1;
  n2.val = 2;
  n3.val = 3;
  n1.next = &n2;
  n2.next = &n3;
  ll1.len = 0;
  insert_first(&ll1, &n1);
  insert_first(&ll1, &n2);
  traverse(&ll1);
  return 0;
}

void traverse(struct LinkedList* ll) {
  printf("traverse\n");
  struct Node* ll_iter = (*ll).HEAD;
  for (int i = 0; i < (*ll).len; i++) {
    printf("ll[%d] is %d\n", i, (*ll_iter).val);
    ll_iter = (*ll_iter).next;  
  }
}

void insert_first(struct LinkedList* ll, struct Node* x) {
  struct Node* tmp = (*ll).HEAD;
  printf("tmp is %p, val is %d\n", tmp, (*tmp).val);
  (*ll).HEAD->val = (*x).val;
  printf("Head is %p, val is %d\n", (*ll).HEAD, (*ll).HEAD->val);
  (*ll).HEAD->next = tmp;
  (*ll).len = (*ll).len + 1;
}

void get_at(struct LinkedList* ll, int i) {
  return;
}
