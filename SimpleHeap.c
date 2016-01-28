//#include <stdio.h>
//#include <stdlib.h>
//#include "SimpleHeap.h"
//
//int GetParentIDX(int idx);
//int GetLChildIDX(int idx);
//int GetRChildIDX(int idx);
//int GetHiPriChildIDX(Heap* ph, int idx);
//
//
//void HeapInit(Heap* ph)
//{
//	ph->numOfData = 0;
//}
//
//int HIsEmpty(Heap* ph)
//{
//	if(ph->numOfData == 0)
//		return TRUE;
//	else
//		return FALSE;
//}
//
///*
//void HInsert(Heap* ph, HData data, Priority pr)
//{
//int idx = ph->numOfData;
//HeapElem temp;
//
//ph->heapArr[idx++].data = data;
//
//while( (ph->heapArr[idx/2].pr < ph->heapArr[idx].pr) || idx <= 0)
//{
//if( ph->heapArr[idx].pr < ph->heapArr[idx/2].pr )
//{
//temp = ph->heapArr[idx/2] ;
//ph->heapArr[idx/2] = ph->heapArr[idx] ;
//ph->heapArr[idx] = temp;
//}
//idx = idx/2;
//}
//
//}
//*/
//
//void HInsert(Heap* ph, HData data, Priority pr)
//{
//	int idx = ph->numOfData+1;
//	//printf("ph->numOfData : %d\n", ph->numOfData);
//	
//	//printf("after ph->numOfData +1 : %d\n", idx);
//
//	HeapElem newElem = {pr, data};
//
//	while(idx != 1)
//	{
//		if( pr < ph->heapArr[GetParentIDX(idx)].pr )
//		{
//			ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
//			idx = GetParentIDX(idx);
//		}
//
//		else
//			break;
//	}
//
//	ph->heapArr[idx] = newElem;
//	ph->numOfData += 1;
//
//}
//
///*
//HData HDelete(Heap* ph)
//{
//	int idx = 1;
//	int mIdx = 0;
//
//	if(HIsEmpty(ph))
//	{
//		printf("Heap is empty!\n");
//		exit(-1);
//	}
//
//	ph->heapArr[idx] = ph->heapArr[ph->numOfData] ;
//	ph->numOfData -= 1;
//	
//	while(idx > ph->numOfData)
//	{
//		mIdx = GetHiPriChildIDX(ph, idx);
//		
//		if(ph->heapArr[idx].pr < ph->heapArr[mIdx].pr)
//		{
//			ph->heapArr[idx] = ph->heapArr[mIdx];
//			idx = mIdx;
//		}
//
//		else
//			break;
//	}
//}
//*/
//
//HData HDelete(Heap* ph)
//{
//	HData retData = (ph->heapArr[1].data);
//	HeapElem lastElem = ph->heapArr[ph->numOfData];
//
//	int idx = 1;
//	int mIdx = 0;
//
//	while(mIdx = GetHiPriChildIDX(ph, idx))
//	{
//		if(lastElem.pr <= ph->heapArr[mIdx].pr)
//			break;
//		ph->heapArr[idx] = ph->heapArr[mIdx];
//		idx = mIdx;
//	}
//
//	ph->heapArr[idx] = lastElem;
//	ph->numOfData -= 1;
//
//	return retData;
//}
//
//int GetParentIDX(int idx)
//{
//	return idx/2;
//}
//
//int GetLChildIDX(int idx)
//{
//	return idx*2;
//}
//
//int GetRChildIDX(int idx)
//{
//	return (idx*2)+1;
//}
//
//int GetHiPriChildIDX(Heap* ph, int idx)
//{
//	int LChildIdx = GetLChildIDX(idx);
//	int RChildIdx = GetRChildIDX(idx);
//
//	if(LChildIdx > ph->numOfData)
//		return 0;
//
//	else if(LChildIdx == ph->numOfData)
//		return LChildIdx;
//
//	else
//	{
//		if (ph->heapArr[LChildIdx].pr < ph->heapArr[RChildIdx].pr )
//			return LChildIdx;
//		else
//			return RChildIdx;
//	}
//}
