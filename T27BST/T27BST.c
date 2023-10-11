#include "BST.h"

void main(void)
{
	TREE* Root = NULL;
	AccessTree1(&Root, 10);
	AccessTree1(&Root, 7);
	AccessTree1(&Root, 15);
	AccessTree1(&Root, 3);
	AccessTree1(&Root, 8);
	AccessTree1(&Root, 13);
	AccessTree1(&Root, 9);
	DelTreeNode(&Root, 15);

	printf("");
}