#ifndef __BINARY_TREE_H__
#define __BINARY_TREE_H__

typedef int BTData;

typedef struct _bTreeNode
{
	BTData data;
	struct _bTreeNode* left;
	struct _bTreeNode* right;
}BTreeNode;

BTreeNode* MakeBTreeNode(void);
BTData GetData(BTreeNode* bt);
void SetData(BTreeNode* bt, BTData data);

BTreeNode* GetLeftSubTree(BTreeNode* bt);
BTreeNode* GetRightSubTree(BTreeNode* bt);

void MakeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void MakeRightSubTree(BTreeNode* main, BTreeNode* sub);

void DeleteTree(BTreeNode* bt);

typedef void VisitFuncPtr(BTData data);
void InorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PreorderTraverse(BTreeNode* bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode* bt, VisitFuncPtr action);


void ShowNodeData(int data);

BTreeNode* RemoveLeftSubTree(BTreeNode* bt);
BTreeNode* RemoveRightSubTree(BTreeNode* bt);

void ChangeLeftSubTree(BTreeNode* main, BTreeNode* sub);
void ChangeRightSubTree(BTreeNode* main, BTreeNode* sub);

#endif