#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INIT_QUEUE {NULL, 0, 0, 0, 4};

typedef struct queue {
  void* base;
  int head;
  int tail;
  int elemSize;
  int allocSize; // allocSize is the max number of elements that can currently be stored in queue
} queue;

void enqueue(queue* q, void* x);
void dequeue(queue* q, void* elemAddr);
bool is_empty(queue* q);
void peek(queue* q);
static void resize(queue* q);

int main(int argc, char*argv[]) {
	queue q1 = INIT_QUEUE;
	q1.elemSize = sizeof(int);
	q1.base = malloc(4 * q1.elemSize);
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	enqueue(&q1, &a1);
	peek(&q1);
	
	enqueue(&q1, &a2);
	peek(&q1);
	
	enqueue(&q1, &a3);
	peek(&q1);
	
	void* r1 = malloc(q1.elemSize);
	dequeue(&q1, r1);
	peek(&q1);
	
	void* r2 = malloc(q1.elemSize);
	dequeue(&q1, r2);
	peek(&q1);
	
	void* r3 = malloc(q1.elemSize);
	dequeue(&q1, r3);
	peek(&q1);
	printf("r1 is %d, r2 is %d, r3 is %d\n", *(int*)r1, *(int*)r2, *(int*)r3); 
	return 0;
}

void resize(queue* q) {
	void* tmp = realloc((*q).base, (2 * (*q).allocSize));
	if (tmp == NULL) {
		exit(0); // if realloc fails for now we naively exit
	} else {
		(*q).allocSize = 2 * (*q).allocSize;
	}
}

void enqueue(queue* q, void* x) {
	if ((*q).head == (*q).tail) resize(q);
	memcpy((char*)(*q).base + ((*q).tail * (*q).elemSize), x, (*q).elemSize);
	if ((*q).tail == (*q).allocSize - 1) (*q).tail = 0;
	else (*q).tail += 1; 
}

void dequeue(queue* q, void* elemAddr) {
	if (is_empty(q)) return;
	void* head = (char*)(*q).base + ((*q).head * (*q).elemSize);
	memcpy(elemAddr, head, (*q).elemSize);
	if ((*q).head == (*q).allocSize - 1) (*q).head = 0;
	else (*q).head += 1;
}

bool is_empty(queue* q) {
	if ((*q).head == (*q).tail) return true;
	else return false;
}

void peek(queue* q) {
	if (is_empty(q)) printf("queue is currently empty\n");
	else printf("q[head] is : %d\n", *(int*)((char*)(*q).base + ((*q).head * (*q).elemSize)));
}
