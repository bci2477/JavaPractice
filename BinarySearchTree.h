#ifndef __BINARY_SEARCH_THREE_H__
#define __BINARY_SEARCH_THREE_H__

#include "BinaryTree2.h"

typedef BTData BSTData;

void BSTMakeAndInit(BTreeNode** pRoot);

BSTData BSTGetNodeData(BTreeNode* pBst);

void BSTInsert(BTreeNode** pRoot, BSTData data);

BTreeNode* BSTSearch(BTreeNode* pBst, BSTData target);

BTreeNode* BSTRemove(BTreeNode** pRoot, BSTData target);

void BSTShowAll(BTreeNode* bst);

#endif