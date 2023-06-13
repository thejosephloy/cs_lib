#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
	void* data;
	Node* left;
	Node* right;
	Node* parent;
} Node;

typedef struct BTree {
  void* root;
  int numElems;
  int elemSize;
} BTree;

typedef struct RBNode {
	void* data;
	Node* left;
	Node* right;
	Node* parent;
	char* color;
} RBNode;

typedef struct RBTree {
	void* root;
	int numElems;
	int elemSize;
} RBTree;

typedef struct AVLNode {
	void* data;
	Node* left;
	Node* right;
	Node* parent;
	int size;
} AVLNode;

typedef struct AVLTree {
	void* root;
	int numElems;
	int elemSize;
} AVLTree; 

int main(int argc, char* argv[]) {

  return 0;
}
