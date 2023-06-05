#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INIT_stack {NULL, 0, 0, 4}

typedef struct stack {
	void* base;
	int numElems;
	int elemSize;
	int allocSize;
} stack;

bool is_empty(stack* s);
void push(stack* s, void* x);
void pop(stack* s, void* elemAddr);
void peek(stack* s);
static void resize(stack* s);

int main(int argc, char*argv[]) {
	stack s1 = INIT_stack;
	s1.elemSize = sizeof(int);
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	s1.base = malloc(s1.elemSize);
	push(&s1, &a1);
	peek(&s1);
	
	push(&s1, &a2);
	peek(&s1);
	push(&s1, &a3);
	peek(&s1);
	void* returnVal = malloc(s1.elemSize);
	pop(&s1, returnVal);
	peek(&s1);
	printf("return val is %d\n", *(int*)returnVal);
	return 0;
}

static void resize(stack* s) {
	void* tmp = realloc((*s).base, (2 * (*s).allocSize));
	if (tmp == NULL) {
		exit(0); // if realloc fails for now we naively exit
	} else {
		(*s).allocSize = 2 * (*s).allocSize;
	}
}

bool is_empty(stack* s) {
	if ((*s).numElems == 0) return true;
	else return false;
}

void push(stack* s, void* x) {
	if ((*s).numElems == (*s).allocSize) resize(s);
	memcpy((char*)(*s).base + ((*s).numElems * (*s).elemSize), x, (*s).elemSize);
	(*s).numElems += 1;
}

void pop(stack* s, void* elemAddr) {
	if ((*s).numElems == 0) return;
	void* top = (char*)(*s).base + (((*s).numElems - 1) * (*s).elemSize);
	memcpy(elemAddr, top, (*s).elemSize);
	(*s).numElems -= 1;
}

void peek(stack* s) {
  if (is_empty(s)) printf("stack is currently empty\n");
  else printf("s[top] is : %d\n", *(int*)((char*)(*s).base + ((*s).numElems - 1 ) * (*s).elemSize));
}

