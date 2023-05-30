#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INIT_STACK {NULL, 0, 0, 4}

typedef struct Stack {
	void* s_ptr;
	int numElems;
	int elemSize;
	int stackSize;
} Stack;

bool is_empty(Stack* s);
void push(Stack* s, void* x);
void pop(Stack* s, void* elemAddr);
void peek(Stack* s);
static void resize(Stack* s);

int main(int argc, char*argv[]) {
	Stack s1 = INIT_STACK;
	s1.elemSize = sizeof(int);
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	s1.s_ptr = malloc(s1.elemSize);
	push(&s1, &a1);
	peek(&s1);
	
	push(&s1, &a2);
	peek(&s1);
	push(&s1, &a3);
	peek(&s1);
	void* returnVal = malloc(s1.elemSize);
	pop(&s1, returnVal);
	peek(&s1);
	printf("%d", *(int*)returnVal);
	return 0;
}

static void resize(Stack* s) {
	void* tmp = realloc((*s).s_ptr, (2 * (*s).stackSize));
	if (tmp == NULL) {
		exit(0); // if realloc fails for now we naively exit
	} else {
		(*s).stackSize = 2 * (*s).stackSize;
	}
}

bool is_empty(Stack* s) {
	if ((*s).numElems == 0) return true;
	else return false;
}

void push(Stack* s, void* x) {
	memcpy((char*)(*s).s_ptr + ((*s).numElems * (*s).elemSize), x, (*s).elemSize);
	(*s).numElems += 1;
}

void pop(Stack* s, void* elemAddr) {
	if ((*s).numElems == 0) return;
	void* top = (char*)(*s).s_ptr + (((*s).numElems - 1) * (*s).elemSize);
	memcpy(elemAddr, top, (*s).elemSize);
	(*s).numElems -= 1;
}

void peek(Stack* s) {
  printf("s[top] is : %d\n", *(int*)((char*)(*s).s_ptr + ((*s).numElems - 1 ) * (*s).elemSize));
}

