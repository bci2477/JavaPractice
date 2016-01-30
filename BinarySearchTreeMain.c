#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main(void)
{
	BTreeNode* bstRoot;
	BTreeNode* sNode;

	BSTMakeAndInit(&bstRoot);

	BSTInsert(&bstRoot, 5); BSTInsert(&bstRoot, 8); BSTInsert(&bstRoot, 1); BSTInsert(&bstRoot, 6);
	BSTInsert(&bstRoot, 4); BSTInsert(&bstRoot, 9); BSTInsert(&bstRoot, 3); BSTInsert(&bstRoot, 2);
	BSTInsert(&bstRoot, 7);

	BSTShowAll(bstRoot); printf("\n");

	sNode = BSTSearch(bstRoot, 1);

	if(sNode == NULL)
		printf("search fail!\n");
	else
		printf("key : %d\n", BSTGetNodeData(sNode));

	printf("-------------------------------------------\n");


	sNode = BSTSearch(bstRoot, 4);

	if(sNode == NULL)
		printf("search fail!\n");
	else
		printf("key : %d\n", BSTGetNodeData(sNode));

	printf("-------------------------------------------\n");

	sNode = BSTSearch(bstRoot, 6);

	if(sNode == NULL)
		printf("search fail!\n");
	else
		printf("key : %d\n", BSTGetNodeData(sNode));

	printf("-------------------------------------------\n");

	sNode = BSTSearch(bstRoot, 7);

	if(sNode == NULL)
		printf("search fail!\n");
	else
		printf("key : %d\n", BSTGetNodeData(sNode));

	printf("-------------------------------------------\n");

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 3);
	free(sNode);
	printf("Remove 3-------------------------------------------\n");

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 8);
	free(sNode);
	printf("Remove 8-------------------------------------------\n");

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 1);
	free(sNode);
	printf("Remove 1-------------------------------------------\n");

	BSTShowAll(bstRoot); printf("\n");
	sNode = BSTRemove(&bstRoot, 6);
	free(sNode);
	printf("Remove 6-------------------------------------------\n");

	BSTShowAll(bstRoot); printf("\n");

	return 0;
}