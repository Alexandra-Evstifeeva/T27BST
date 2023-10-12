#include "BST.h"

// ** - Две звёздочки, из-за того, что предполагается изменение дерева
int AccessTree(TREE** T, int Key)
{
	if (*T == NULL)
	{
		// malloc() - функция, выделяющая память (в байтах) для какого-либо указателя.
		*T = malloc(sizeof(TREE));
		if (*T == NULL)
		{
			printf("Not enough memory\n");
			return 0;
		}

		// В поле структуры Key заносим значение, которое добавляем в дерево
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
	// Для того, чтобы определить по какой ветке пойти дальше
	// сравниваем значение в текущем узле и вызываем рукурсивно функцию
	// либо от левого поддерева, либо от правого
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
			// Обращаемся по ссылке, чтобы в результате работа шла с указателем на дерево,
			// а не на его отдельный узел.
			T = &(*T)->Less;
		else
			T = &(*T)->More;
	}

	if (*T == NULL)
		return 0;

	p = &(*T)->Less;

	// Запоминаем изначальный адрес узла, т.к. в последсвтии он будет изменён.
	old = *T;

	if (*p == NULL)
		// Если левое поддерево пусто, или элемент это лист дерева, то
		// достаточно просто переприсвоить в этот узел адрес правого поддерева.
		*T = (*T)->More;
	else
	{
		// Циклом спускаемся в самое правое поддерево, там находится элемент с максимальным значением.
		while (*p != NULL)
		{
			p = &(*p)->More;
		}
		// p в результате хранит адрес самого элемента, и изменения по этому адресу влияют на дерево.
		// *p - обращение к узлу дерева для записи в него значения
		// Именно поэтому нет необходимости хранить предка узла!!
		*p = (*T)->More;
		// Вершина левого поддерева становится вршиной нового дерева
		*T = (*T)->Less;
	}

	free(old);
	return 1;
}

int Linearize(TREE** T)
{
	TREE** p, * tmp;
	int n = 0;

	while (*T != NULL)
	{
		// !!!!
		p = &(*T)->Less;
		while (*p != NULL)
		{
			// !!!!
			tmp = *p;
			// !!!
			while (*p != NULL)
			{
				p = &(*p)->More;
			}
			// !!
			*p = *T;
			(*T)->Less = NULL;
			// !!!
			*T = tmp;
			// !!!
			p = &(*T)->Less;
		}
		// !!!
		T = &(*T)->More;
		n++;
	}


	return n;
}