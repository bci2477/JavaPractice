#include <stdlib.h>
#include <stdio.h>
#include "BinarySearchTree.h"
#include "BinaryTree2.h"

void BSTMakeAndInit(BTreeNode** pRoot)
{
	*pRoot = NULL;
}

BSTData BSTGetNodeData(BTreeNode* pBst)
{
	return pBst->data;
}


void BSTInsert(BTreeNode** pRoot, BSTData data)
{
	BTreeNode* newNode = MakeBTreeNode();
	BTreeNode* cpNode = *pRoot;
	BTreeNode* pNode = NULL;

	while(cpNode != NULL)
	{
		if(data == cpNode->data)
			return ;

		pNode = cpNode;

		if (data < cpNode->data)
			cpNode = cpNode->left;
		else
			cpNode = cpNode->right;
	}

	SetData(newNode, data);

	if(pNode == NULL)
		*pRoot = newNode;

	else
	{
		if( data < pNode->data)
			pNode->left = newNode;
		else
			pNode->right = newNode;
	}
}

BTreeNode* BSTSearch(BTreeNode* pBst, BSTData target)
{
	BTreeNode* cpNode = pBst;
	BSTData cd;

	while(cpNode != NULL)
	{
		cd = cpNode->data;

		if(target == cd)
			return cpNode;
		else if (target < cd)
			cpNode = cpNode->left;
		else
			cpNode = cpNode->right;
	}

	return NULL;
}

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target)
{
	BTreeNode* pVRoot = MakeBTreeNode();
	BTreeNode* pNode = pVRoot;
	BTreeNode* cpNode = *pRoot;
	BTreeNode* dNode;

	ChangeRightSubTree(pVRoot, *pRoot);

	while(cpNode != NULL && cpNode->data != target)
	{
		pNode = cpNode;

		if(target < cpNode->data)
			cpNode = cpNode->left;
		else
			cpNode = cpNode->right;
	}

	if(cpNode == NULL)
		return NULL;

	dNode = cpNode;

	// first case : The deleted target is terminal case.
	if(dNode->left == NULL && dNode->right == NULL)
	{
		dNode = NULL;

		/*if(pNode->left == dNode)
			RemoveLeftSubTree(pNode);
		else
			RemoveRightSubTree(pNode);*/
	}

	// second case : The deleted target has a child node.
	else if((dNode->left == NULL) || (dNode->right==NULL))
	{
		BTreeNode* dcNode;

		if(dNode->left != NULL)
			dcNode = dNode->left;
		else
			dcNode = dNode->right;

		if(pNode->left == dNode)
			ChangeLeftSubTree(pNode, dcNode);
		else
			ChangeRightSubTree(pNode, dcNode);
	}

	// third case : The deleted target has two child nodes
	else
	{
		BTreeNode* mNode = dNode->right;
		BTreeNode* mpNode = dNode;
		int delData;

		while(mNode->left != NULL)
		{
			mpNode = mNode;
			mNode = mNode->left;
		}

		delData = dNode->data;
		SetData(dNode, mNode->data);

		if(mpNode->left == mNode)
			ChangeLeftSubTree(mpNode, mNode->right);
		else
			ChangeRightSubTree(mpNode, mNode->right);

		dNode = mNode;
		SetData(dNode, delData);
	}

	if(pVRoot->right != *pRoot)
		*pRoot = pVRoot->right;

	free(pVRoot);
	return dNode;
}

void ShowIntData(int data)
{
	printf("%d ", data);
}

void BSTShowAll(BTreeNode* bst)
{
	InorderTraverse(bst, ShowIntData);
}