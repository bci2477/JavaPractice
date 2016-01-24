#include <stdio.h>
#include "InfixToPostfix.h"
#include "PostfixCal.h"

int main(void)
{
	char exp1[]="1+2*3";
	char exp2[]="(1+2)*3";
	char exp3[]="((1-2)+3)*(5-2)";

	char postExp1[] = "42*8+";
	char postExp2[] = "123+*4/";

	ConvToRPNExp(exp1);
	ConvToRPNExp(exp2);
	ConvToRPNExp(exp3);

	printf("%s = %d \n", exp1, EvalRPNExp(exp1));
	printf("%s = %d \n", exp2, EvalRPNExp(exp2));
	printf("%s = %d \n", exp3, EvalRPNExp(exp3));

	printf("%s = %d \n", postExp1, EvalRPNExp(postExp1));
	printf("%s = %d \n", postExp2, EvalRPNExp(postExp2));

	

	return 0;
}

