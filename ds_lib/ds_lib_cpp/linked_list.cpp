#include <iostream>

class Node {
public:
  int val;
  Node* next;
};

class LinkedList {
public:
  Node* head;
  Node* tail;
  int len;
};

void traverse(LinkedList* ll) {
  Node* ll_iter = (*ll).head;
  for (int i = 0; i < (*ll).len; i++) {
    std::cout << "ll[" << i << "] is " << (*ll_iter).val << std::endl;
    ll_iter = (*ll_iter).next;
  }
}

void get_at(LinkedList* ll, int i) {
  Node* ll_iter = (*ll).head;
  for (int idx = 0; idx < i; idx++) {
    ll_iter = (*ll_iter).next;
  }
  std::cout << "ll[" << i << "] is " << (*ll_iter).val << std::endl;
}

void insert_first(LinkedList* ll, Node* n) {
  Node* tmp = (*ll).head;
  (*ll).head = n;
  (*n).next = tmp;
  (*ll).len = (*ll).len + 1;
  
}

void delete_first(LinkedList* ll) {
  (*ll).head = (*ll).head->next;
  (*ll).len--;
}

void insert_last(LinkedList* ll, Node* n) {
  (*ll).tail->next = n;
  (*ll).tail = n;
  (*n).next = NULL;
  (*ll).len++;
}

void delete_last(LinkedList* ll) {
  Node* ll_iter = (*ll).head;
  for (int i = 0; i < (*ll).len - 1; i++) {
    ll_iter = (*ll_iter).next;
  }
  (*ll_iter).next = NULL;
  (*ll).len--;
}

void insert_at(LinkedList* ll, int i, Node* n) {

  if (i == 0) {
    insert_first(ll, n);
  }

  else if (i > 0 && i < (*ll).len) {
    Node* ll_iter = (*ll).head;
    for (int idx = 0; idx < i - 1; idx++) {
      ll_iter = (*ll_iter).next;
    }
    Node* tmp = (*ll_iter).next;
    (*ll_iter).next = n;
    (*n).next = tmp;
    (*ll).len++;
  }
  
  else if (i == (*ll).len) {
    insert_last(ll, n);
  }

  else {
    std::cout << "Please choose a valid index i" << std::endl;
  }
  
}

void delete_at(LinkedList* ll, int i) {

  if (i == 0) {
    delete_first(ll);
  }

  else if (i > 0 && i < (*ll).len - 1) {
    Node* ll_iter = (*ll).head;
    for (int idx = 0; idx < i - 1; idx++) {
      ll_iter = (*ll_iter).next;
    }
    (*ll_iter).next = (*ll_iter).next->next;
    (*ll).len--;
  }
  else if (i == (*ll).len - 1) {
    delete_last(ll);
  }
  else {
    std::cout << "Please choose valid index i" << std::endl;
  }
}

int main() {
  Node n1;
  Node n2;
  Node n3;
  Node n4;
  n1.val = 1;
  n2.val = 2;
  n3.val = 3;
  n4.val = 4;
  LinkedList ll1;
  ll1.head = &n3;
  ll1.tail = &n3;
  ll1.len = 1;
  insert_first(&ll1, &n2);
  insert_first(&ll1, &n1);
  insert_at(&ll1, 3, &n4);
  traverse(&ll1);
  delete_at(&ll1, 2);
  traverse(&ll1);
  return 0;
}

