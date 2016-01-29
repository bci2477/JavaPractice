#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"


xxxxxxxxxxxxxxxxxxxxxxx
BTreeNode* MakeBTreeNode(void)
{
	BTreeNode* newNode = (BTreeNode*)malloc(sizeof(BTreeNode));
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTData GetData(BTreeNode* bt)
{
	return bt->data;
}

void SetData(BTreeNode* bt, BTData data)
{
	bt->data = data;
}

BTreeNode* GetLeftSubTree(BTreeNode* bt)
{
	return bt->left;
}

BTreeNode* GetRightSubTree(BTreeNode* bt)
{
	return bt->right;
}

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub)
{
	if(main->left != NULL)
		free(main->left);

	main->left = sub;
}

void MakeRightSubTree(BTreeNode* main, BTreeNode* sub)
{
	if(main->right != NULL)
		free(main->right);

	main->right = sub;
}

void DeleteTree(BTreeNode* bt)
{
	if(bt == NULL)
		return;

	DeleteTree(bt->left);
	DeleteTree(bt->right);
	printf("del tree data : %d \n",bt->data);
	free(bt);
}

void InorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	action(bt->data);
	InorderTraverse(bt->right, action);
}

void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	action(bt->data);
	InorderTraverse(bt->left, action);
	InorderTraverse(bt->right, action);
}

void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action)
{
	if(bt == NULL)
		return;

	InorderTraverse(bt->left, action);
	InorderTraverse(bt->right, action);
	action(bt->data);
}

void ShowNodeData(int data)
{
	if(0<=data && data <=9)
		printf("%d", data);
	else
		printf("%c", data);
}
