#include <stdio.h>
#include <stdlib.h>
#include "UsefulHeap.h"

int GetParentIDX(int idx);
int GetLChildIDX(int idx);
int GetRChildIDX(int idx);
int GetHiPriChildIDX(Heap* ph, int idx);


void HeapInit(Heap* ph, PriorityComp* pc)
{
	ph->numOfData = 0;
	ph->comp = pc;
}

int HIsEmpty(Heap* ph)
{
	if(ph->numOfData == 0)
		return TRUE;
	else
		return FALSE;
}


void HInsert(Heap* ph, HData data)
{
	int idx = ph->numOfData+1;

	while(idx != 1)
	{
		//if( pr < ph->heapArr[GetParentIDX(idx)].pr )
		if(ph->comp(data, ph->heapArr[GetParentIDX(idx)]) > 0)
		{
			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
			idx = GetParentIDX(idx);
		}

		else
			break;
	}

	ph->heapArr[idx] = data;
	ph->numOfData += 1;

}

HData HDelete(Heap* ph)
{
	HData retData = ph->heapArr[1];
	HData lastElem = ph->heapArr[ph->numOfData];

	int idx = 1;
	int mIdx = 0;

	while(mIdx = GetHiPriChildIDX(ph, idx))
	{
		//if(lastElem.pr <= ph->heapArr[mIdx].pr)
		if(ph->comp(lastElem , ph->heapArr[mIdx]) >= 0)
			break;
		ph->heapArr[idx] = ph->heapArr[mIdx];
		idx = mIdx;
	}

	ph->heapArr[idx] = lastElem;
	ph->numOfData -= 1;

	return retData;
}

int GetParentIDX(int idx)
{
	return idx/2;
}

int GetLChildIDX(int idx)
{
	return idx*2;
}

int GetRChildIDX(int idx)
{
	return (idx*2)+1;
}

int GetHiPriChildIDX(Heap* ph, int idx)
{
	int LChildIdx = GetLChildIDX(idx);
	int RChildIdx = GetRChildIDX(idx);

	if(LChildIdx > ph->numOfData)
		return 0;

	else if(LChildIdx == ph->numOfData)
		return LChildIdx;

	else
	{
		if (ph->comp(ph->heapArr[LChildIdx], ph->heapArr[RChildIdx]) < 0)
			return RChildIdx;
		else
			return LChildIdx;
	}
}
