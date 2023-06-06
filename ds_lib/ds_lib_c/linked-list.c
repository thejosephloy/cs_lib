#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
	void* val;
	struct Node *next;
} Node;

typedef struct linkedlist{
  	Node* head;
	Node* tail;
	int numElems;
	int elemSize;
} linkedlist;

void build(linkedlist* l, void* src, int numElems);
void print(linkedlist* l);
int len(linkedlist l);
void* get_at(linkedlist l, int i);
void set_at(linkedlist l, int i, void* x);
void insert_at(linkedlist* l, int i, void* x);
void delete_at(linkedlist* l, int i);
void insert_last(linkedlist* l, void* x);
void delete_last(linkedlist* l);
void insert_first(linkedlist* l, void* x);
void delete_first(linkedlist* l);

int main(int argc, char* argv[]) {
	int arr[5] = {1, 2, 3, 4, 5};
	linkedlist l1;
	l1.elemSize = sizeof(int);
	build(&l1, &arr, 5);
	//printf("%d\n", *(int*)(*(l1.head)).val);
	//print(&l1);
	return 0;
}

void build(linkedlist* l, void* src, int numElems) {
	Node* head = malloc(sizeof(Node));
	memcpy((*head).val, src, (*l).elemSize);
	for (int i = 0; i < numElems; i++) {
		printf("%d\n", *(int*)((char*)src + (i * (*l).elemSize)));
	}
}

void print(linkedlist* l) {
	Node* curNode = (*l).head;
	while(1) {
		printf("curNode is %d\n", (int)((*curNode).val));
		curNode = (*curNode).next;
		if ((*curNode).next == NULL) break;
	}
}
