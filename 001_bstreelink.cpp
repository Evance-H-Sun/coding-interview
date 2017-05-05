#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* 
   This file should be compiled by g++, NOT gcc.
   Because C++ feature [reference] is used.
*/
typedef struct bstree {
	int value;
	struct bstree * left;
	struct bstree * right;
}Bstree, *pBstree;

pBstree startWalk(pBstree root);
void walkTree(pBstree &head, pBstree &tail, pBstree root);
void walkLink(pBstree);

int main(void)
{
	Bstree e4 = { 4,NULL,NULL };
	Bstree e8 = { 8,NULL,NULL };
	Bstree e12 = { 12,NULL,NULL };
	Bstree e16 = { 16,NULL,NULL };

	Bstree e6 = { 6, &e4, &e8 };
	Bstree e14 = { 14, &e12, &e16 };

	Bstree e10 = { 10, &e6, &e14 };
	pBstree head = startWalk(&e10);
	walkLink(head);

	getchar();
	return 0;
}

pBstree startWalk(pBstree root) {
	pBstree head = NULL;
	pBstree tail = NULL;
	if (root == NULL) {
		return NULL;
	}
	walkTree(head, tail, root);

	return head;
}

void walkTree(pBstree &head, pBstree &tail, pBstree root) {
	if (root->left == NULL) {
		head = root;
	}
	else {
		walkTree(head, tail, root->left);		
		root->left = tail;
		tail->right = root;
	}
	if (root->right == NULL) {
		tail = root;
	}
	else {
		walkTree(root->right,tail, root->right);
	}
}

void walkLink(pBstree root) {
	int i = 1;
	while (root) {
		printf("%d----%d\n",i,root->value);
		i++;
		root = root->right;
	}
}
