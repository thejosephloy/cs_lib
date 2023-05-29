#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct StaticArray {
	void* arr;
	int numElems;
	int elemSize;
} StaticArray;

void build(void* dst, void* src, int numElems, int elemSize);
void print(StaticArray s);
int len(StaticArray s);
void* get_at(StaticArray s, int i);
void set_at(StaticArray s, int i, void* x);

int main(int argc, char* argv[]) {
	int numElems = 5;
	int elemSizeInt = sizeof(int);
	StaticArray s1;
	int nums[5] = {1, 2, 3, 4, 5};
	s1.arr = malloc(numElems * elemSizeInt);
	s1.numElems = 5;
	s1.elemSize = sizeof(int);
	build(s1.arr, nums, numElems, elemSizeInt);
	print(s1);
	printf("%d\n", *(int*)get_at(s1, 1));
	int newVal = 67;
	set_at(s1, 1, &newVal);
	printf("%d\n", *(int*)get_at(s1, 1));
	print(s1);
	
	
	StaticArray s2;
	int elemSizeCh = sizeof(char);
	char chs[5] = {'a', 'b', 'c', 'd', 'e'};
	s2.arr = malloc(numElems * elemSizeCh);
	s2.numElems = numElems;
	s2.elemSize = elemSizeCh;
	build(s2.arr, chs, numElems, elemSizeCh);
	print(s2);
	printf("%c\n", *(char*)get_at(s2, 1));
	char newVal2 = 'z';
	set_at(s2, 1, &newVal2);
	print(s2);
	return 0;
}

void build(void* dst, void* src, int numElems, int elemSize) {
	
	for (int i = 0; i < numElems; i++) {
		printf("src[%d] is %d\n", i, *((char*)src + (i * elemSize)));
		memcpy((char*)dst + (i * elemSize), (char*)src + (i * elemSize), elemSize);	
	}
	
}

void print(StaticArray s) {
	for (int i = 0; i < s.numElems; i++) {
		printf("arr[%d] is : %d\n", i, *((char*)s.arr + (i * s.elemSize)));
	}
}

int len(StaticArray s) {
	return s.numElems;
}

void* get_at(StaticArray s, int i) {
	return ((char*)s.arr + (i * s.elemSize));
}

void set_at(StaticArray s, int i, void* x) {
	memcpy(((char*)s.arr + (i * s.elemSize)), x, s.elemSize);
}

