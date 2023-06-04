#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


#define INIT_QUEUE {NULL, NULL, 0, 0, 4};

typedef struct queue {
  void* base;
  void* head;
  void* tail;
  int numElems;
  int elemSize;
  int allocSize;
} queue;

void enqueue(queue* q, void* x);
void dequeue(queue* q, void* elemAddr);
bool is_empty(queue* q);
void peek(queue* q);
static void resize(queue* q);

int main(int argc, char*argv[]) {

}

void resize(queue* q) {

}

void enqueue(queue* q, void* x) {

}

void dequeue(queue* q, void* elemAddr) {

}

bool is_empty(queue* q) {

}

void peek(queue* q) {

}
