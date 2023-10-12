#include <stdlib.h>
#include <stdio.h>

typedef struct tagTREE TREE;
struct tagTREE
{
	int Key;
	TREE* Less, * More;
};

int AccessTree(TREE** T, int Key);
int AccessTree1(TREE** T, int Key);
int DelTreeNode(TREE** T, int Key);
int Linearize(TREE** T);