#include "BST.h"

// ** - ��� ��������, ��-�� ����, ��� �������������� ��������� ������
int AccessTree(TREE** T, int Key)
{
	if (*T == NULL)
	{
		// malloc() - �������, ���������� ������ (� ������) ��� ������-���� ���������.
		*T = malloc(sizeof(TREE));
		if (*T == NULL)
		{
			printf("Not enough memory\n");
			return 0;
		}

		// � ���� ��������� Key ������� ��������, ������� ��������� � ������
		(*T)->Key = Key;
		(*T)->Less = (*T)->More = NULL;
		printf("Add a new key\n");
		return 1;
	}
	if ((*T)->Key == Key)
	{
		printf("Node exists\n");
		return 1;
	}
	// ��� ����, ����� ���������� �� ����� ����� ����� ������
	// ���������� �������� � ������� ���� � �������� ���������� �������
	// ���� �� ������ ���������, ���� �� �������
	if ((*T)->Key > Key)
		return AccessTree(&(*T)->Less, Key);
	return AccessTree(&(*T)->More, Key);
}

int AccessTree1(TREE** T, int Key)
{
	while (*T)
	{
		if ((*T)->Key == Key)
		{
			printf("Node exists\n");
			return 1;
		}
		if ((*T)->Key > Key)
		{
			T = &(*T)->Less;
		}
		else
		{
			T = &(*T)->More;
		}
	}

	if ((*T = malloc(sizeof(TREE))) == NULL)
	{
		printf("Not enough memory\n");
		return 0;
	}

	(*T)->Key = Key;
	(*T)->Less = (*T)->More = NULL;
	printf("Add a new key\n");
	return 1;
}

int DelTreeNode(TREE** T, int Key)
{
	TREE** p;
	TREE* old;
	if (*T == NULL)
		return 0;
	while (*T != NULL && (*T)->Key != Key)
	{
		if ((*T)->Key > Key)
			// !!!!!!!!
			T = &(*T)->Less;
		else
			T = &(*T)->More;
	}

	if (*T == NULL)
		return 0;

	p = &(*T)->Less;
	old = *T;

	if (*p == NULL)
		// !!!!
		*T = (*T)->More;
	else
	{
		// !!!!!
		while (*p != NULL)
		{
			p = &(*p)->More;
		}
		*p = (*T)->More;
		*T = (*T)->Less;
	}

	free(old);
	return 1;
}