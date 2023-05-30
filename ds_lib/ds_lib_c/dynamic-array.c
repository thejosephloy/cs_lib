#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct DynamicArray {
	void* arr;
	int numElems;
	int elemSize;
	int size;
} DynamicArray;

void build(void* dst, void* src, int numElems, int elemSize);
void print(DynamicArray s);
int len(DynamicArray s);
void* get_at(DynamicArray s, int i);
void set_at(DynamicArray s, int i, void* x);
static void resize(DynamicArray *s);
void insert_at(DynamicArray* s, int i, void* x);
void delete_at(DynamicArray* s, int i);
void insert_last(DynamicArray* s, void* x);
void delete_last(DynamicArray* s);

int main(int argc, char*argv[]) {
	int numElems = 5;
	int elemSizeInt = sizeof(int);
	DynamicArray s1;
	int nums[5] = {1, 2, 3, 4, 5};
	s1.arr = malloc(numElems * elemSizeInt);
	s1.numElems = 5;
	s1.elemSize = sizeof(int);
	s1.size = 5;
	build(s1.arr, nums, s1.numElems, s1.elemSize);
	printf("%d\n", s1.size);
	print(s1);
	int val = 6;
	insert_last(&s1, &val);
	print(s1);
	printf("%d\n", len(s1));
	delete_at(&s1, 2);
	print(s1);
	printf("%d\n", len(s1));
	int val2 = 69;
	insert_at(&s1, 2, &val2);
	print(s1);
	return 0;
}

void build(void* dst, void* src, int numElems, int elemSize) {
	for (int i = 0; i < numElems; i++) {
		memcpy((char*)dst + (i * elemSize), (char*)src + (i * elemSize), elemSize);	
	}
	
}

void print(DynamicArray s) {
	for (int i = 0; i < s.numElems; i++) {
		printf("arr[%d] is : %d\n", i, *((char*)s.arr + (i * s.elemSize)));
	}
}

int len(DynamicArray s) {
	return s.numElems;
}

void* get_at(DynamicArray s, int i) {
	return ((char*)s.arr + (i * s.elemSize));
}

void set_at(DynamicArray s, int i, void* x) {
	memcpy(((char*)s.arr + (i * s.elemSize)), x, s.elemSize);
}

static void resize(DynamicArray* s) {
	
	void *tmp = realloc((*s).arr, (2 * (*s).size));
	if (tmp == NULL) {
		exit(0); // if realloc fails for now we naively exit
	} else {
		(*s).size = 2 * (*s).size;
	}
	
}

void insert_at(DynamicArray* s, int i, void* x) {
	if ((*s).numElems == (*s).size) resize(s);
	memmove((char*)(*s).arr + ((i+1) * (*s).elemSize),
			(char*)(*s).arr + ((i) * (*s).elemSize), 
			((*s).numElems - i) * (*s).elemSize);
	set_at(*s, i, x);
	(*s).numElems += 1;
}

void delete_at(DynamicArray* s, int i) {
	memmove((char*)(*s).arr + (i * (*s).elemSize), 
			(char*)(*s).arr + ((i+1) * (*s).elemSize),
			((*s).numElems - 1) * (*s).elemSize);
	(*s).numElems -= 1;
}

void insert_last(DynamicArray* s, void* x) {
	if ((*s).numElems == (*s).size) resize(s);
	set_at(*s, (*s).numElems, x);
	(*s).numElems += 1;
}

void delete_last(DynamicArray* s) {
	(*s).numElems -= 1;
}

