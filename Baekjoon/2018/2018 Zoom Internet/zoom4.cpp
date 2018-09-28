#include <iostream>
#include <cmath>

using namespace std;

int maxLevel = 0;

typedef struct tree {
	int x;
	tree* l;
	tree* r;
}tree;

int max(int a, int b) {
	return a > b ? a : b;
}

tree* traverse(tree * T) {
	tree* leftChild = T->l;
	tree* rightChild = T->r;
	T->x = 0;

	if (T->l != NULL) {
		leftChild = traverse(leftChild);
	}
	if (T->r != NULL) {
		rightChild = traverse(rightChild);
	}

	if (leftChild != NULL && rightChild != NULL) {
		if (leftChild->x == rightChild->x)
			T->x = T->x + leftChild->x + 1;
	}
	maxLevel = max(T->x, maxLevel);

	return T;
}

int solution(tree * T) {
	// write your code in C++14 (g++ 6.2.0)
	traverse(T);
	int nodes = pow(2, maxLevel);
	return maxLevel;
}

int main() {

}