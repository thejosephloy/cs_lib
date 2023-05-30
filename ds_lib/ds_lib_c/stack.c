#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define INIT_STACK {NULL, 0, 0, 1}

typedef struct Stack {
	void* s_ptr;
	int numElems;
	int elemSize;
	int stackSize;
} Stack;

bool is_empty(Stack* s);
void push(Stack* s, void* x);
void* pop(Stack* s);
void peek(Stack* s);
void resize(Stack* s);

int main(int argc, char*argv[]) {
	Stack s1 = INIT_STACK;
	s1.elemSize = sizeof(int);
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	s1.s_ptr = malloc(s1.elemSize);
	push(&s1, &a1);
	peek(&s1);
	/*
	push(&s1, &a2);
	peek(&s1);
	push(&s1, &a3);
	*/
	return 0;
}

void resize(Stack* s) {
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

void* pop(Stack* s) {
	if ((*s).numElems = 0) return NULL;
	void* top = (char*)(*s).s_ptr + (((*s).numElems * (*s).elemSize) - 1);
	(*s).numElems -= 1;
	return top;
}

void peek(Stack* s) {
	printf("s[top] is : %d\n", *(int*)((char*)(*s).s_ptr + ((*s).numElems * (*s).elemSize) - 1));
}

