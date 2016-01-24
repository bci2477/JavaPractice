#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "InfixToPostfix.h"

int WhoPrecOp(char op1, char op2);
int GetOpPrec(char op);

void ConvToRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int i, convIdx=0;
	char tok, popOp;

	char* convExp = (char*)malloc(expLen+1);

	memset(convExp,0,sizeof(char)*(expLen+1));
	StackInit(&stack);

	for(i=0; i < expLen; i++)
	{
		tok = exp[i];

		if(isdigit(tok))
			convExp[convIdx++] = tok;
		else
		{
			switch(tok)
			{
			case '(' :
				SPush(&stack, tok);
				break;
			case ')' :
				while(1)
				{
					popOp = SPop(&stack);
					if(popOp == '(')
						break;
					convExp[convIdx++] = popOp;
				}
				break;

			case '+': case '-':
			case '*': case '/':
				while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >=0)
					convExp[convIdx++] = SPop(&stack);
				SPush(&stack, tok);
				break;
			}
		}
	}

	while(!SIsEmpty(&stack))
		convExp[convIdx++] = SPop(&stack);

	strcpy(exp, convExp);
	free(convExp);
}

int WhoPrecOp(char op1, char op2)
{
	int op1Prec = GetOpPrec(op1);
	int op2Prec = GetOpPrec(op2);

	if(op1Prec > op2Prec)
		return 1;
	else if(op1Prec < op2Prec)
		return -1;
	else
		return 0;
}

int GetOpPrec(char op)
{
	switch(op)
	{
	case '*':
	case '/':
		return 5;
	case '+':
	case '-':
		return 3;
	case '(':
		return 1;
	}
}