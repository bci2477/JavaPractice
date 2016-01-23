#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "CLinkedList.h"
#include "Employee.h"

LData WhoIsNext(List* plist,char* name, int num);
void ShowEmpInfo(List* plist);

int main(void)
{
	List list;
	Employee* pemp;
	Employee* result;
	int i =0 ;

	ListInit(&list);
	
	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name,"ci");
	pemp->num=1;
	LInsert(&list,pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name,"sk");
	pemp->num=2;
	LInsert(&list,pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name,"sb");
	pemp->num=3;
	LInsert(&list,pemp);

	pemp = (Employee*)malloc(sizeof(Employee));
	strcpy(pemp->name,"js");
	pemp->num=4;
	LInsert(&list,pemp);
	
	printf("ShowEmp\n");
	ShowEmpInfo(&list);
	printf("\n\n");

	result = WhoIsNext(&list, "ci", 5);
	printf("Next person is %s\n", result->name);

	if(LFirst(&list, &pemp))
	{
		free(pemp);
		for(i=0; i<LCount(&list)-1; i++)
			if(LNext(&list, &pemp))
				free(pemp);
	}

	return 0;
}

LData WhoIsNext(List* plist, char* name, int num)
{
	Employee* person;
	int i = 0;

	if(LFirst(plist, &person))
	{
		if(strcmp(person->name,name)==0)
		{
			for(i = 0; i < num; i++)
				LNext(plist,&person);
		}
	}

	return person;
}

void ShowEmpInfo(List* plist)
{
	int i = 0;
	Employee* data;

	if(LFirst(plist,&data))
		printf("%s \t %d\n",data->name,data->num);

	for (i=0; i<LCount(plist)-1; i++)
	{
		LNext(plist,&data);
		printf("%s \t %d\n",data->name,data->num);
	}
}