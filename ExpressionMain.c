#include <stdio.h>
#include "ExpressionTree.h"

int main(void)
{
	char exp[] = "12+7*";
	BTreeNode* eTree = MakeExpTree(exp);

	printf("prefix : ");
	ShowPrefixTypeExp(eTree);
	printf("\n\n");

	printf("Infix : ");
	ShowInfixTypeExp(eTree);
	printf("\n\n");

	printf("Postfix : ");
	ShowPostfixTypeExp(eTree);
	printf("\n\n");

	printf("result : %d\n", EvaluateExpTree(eTree));

	return 0;
}