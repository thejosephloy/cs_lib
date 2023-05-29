#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node{
	void* val;
	struct Node *next;
} Node;

typedef struct LinkedList{
	Node* head;
	Node* tail;
	int numElems;
	int valSize;
} LinkedList;

void build(void* dst, void* src, int numElems, int elemSize);
void print(LinkedList l);
int len(LinkedList l);
void* get_at(LinkedList l, int i);
void set_at(LinkedList l, int i, void* x);
void insert_at(LinkedList* l, int i, void* x);
void delete_at(LinkedList* l, int i);
void insert_last(LinkedList* l, void* x);
void delete_last(LinkedList* l);
void insert_first(LinkedList* l, void* x);
void delete_first(LinkedList* l);

int main(int argc, char* argv[]) {

	return 0;
}
