#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "BinaryTree.h"
#include "Stack.h"

BTreeNode* MakeExpTree(char exp[])
{
	int expLen = strlen(exp);
	int i = 0;

	Stack stack;

	BTreeNode* pnode;

	StackInit(&stack);

	for(i=0; i < expLen; i++)
	{
		pnode  = MakeBTreeNode();

		if(isdigit(exp[i]))
			SetData(pnode, exp[i] - '0');

		else
		{
			MakeRightSubTree(pnode, SPop(&stack));
			MakeLeftSubTree(pnode, SPop(&stack));
			SetData(pnode, exp[i]);
		}

		SPush(&stack, pnode);

	}

	return SPop(&stack);
}


int EvaluateExpTree(BTreeNode* bt)
{
	int op1, op2;

	if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
		return GetData(bt);
	

	op1 = EvaluateExpTree(GetLeftSubTree(bt));
	op2 = EvaluateExpTree(GetRightSubTree(bt));

	switch(GetData(bt))
	{
		case '+':
			return op1+op2;
		case '-':
			return op1-op2;
		case '*':
			return op1*op2;
		case '/':
			return op1/op2;
	}

	return 0;
}

void ShowPrefixTypeExp(BTreeNode* bt)
{
	PreorderTraverse(bt, ShowNodeData);
}

void ShowInfixTypeExp(BTreeNode* bt)
{
	InorderTraverse(bt, ShowNodeData);
}

void ShowPostfixTypeExp(BTreeNode* bt)
{
	PostorderTraverse(bt, ShowNodeData);
}
