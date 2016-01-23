#ifndef __C_LINKED_LIST_H__
#define __C_LINKED_LIST_H__

#include "Employee.h"

#define TRUE	1
#define FALSE	0

//typedef int LData;
typedef Employee* LData;

typedef struct _node
{
	LData data;
	struct _node* next;
}Node;

typedef struct __CLinkedList
{
	Node* tail;
	Node* cur;
	Node* before;
	int numOfData;
}CLinkedList;

typedef CLinkedList List;

void ListInit(List* plist);
void LInsert(List* plist, LData data);
void LInsertFront(List* plist, LData data);

int LFirst(List* plist, LData* pdata);
int LNext(List* plist, LData* pdata);

LData LRemove(List* plist);
int LCount(List* plist);

#endif