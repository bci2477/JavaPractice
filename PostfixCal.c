#include "PostfixCal.h"
#include "ListBaseStack.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int calculate(char op, int opr1, int opr2);

int EvalRPNExp(char exp[])
{
	Stack stack;
	int expLen = strlen(exp);
	int idx = 0; 
		char result;
	char tok, opr1, opr2;

	StackInit(&stack);

	for(idx = 0 ; idx < expLen ; idx++)
	{
		tok = exp[idx];

		if(!isdigit(exp[idx]))
		{
			opr2 = SPop(&stack);
			opr1 = SPop(&stack);
			result = calculate(tok, opr1 - '0', opr2 - '0');
			SPush(&stack,result + '0');
		}

		else
			SPush(&stack, tok);
	}

	return SPop(&stack) - '0';
}

int calculate(char op, int opr1, int opr2)
{
	switch(op)
	{
	case '+':
		return opr1+opr2;
	case '-':
		return opr1-opr2;
	case '*':
		return opr1*opr2;
	case '/':
		return opr1/opr2;
	}
}