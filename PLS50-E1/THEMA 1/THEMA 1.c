// ERGASIA 1 - MEROS 1 APLH ARI8MOMHXANH

#include <stdio.h>	/* SUNARTHSEIS ESODOU EKDOSOU DEDOMENVN */

int main (void)
{
	char praxi;			/* ARITHMITIKES PRAKSEIS */
	float num1, num2;	/* DEKADIKOI ARITHMOI */


	printf("Dwse Arithmo PRAXH [ +-*/ ] Arithmo : \n");
	scanf("%f %c %f", &num1, &praxi, &num2);

	if (praxi=='+')
	{
	printf("Apotelesma = %.2f \n", num1+num2);	        /* PROSTHESH ARITHMWN */
	}
	else if (praxi=='-')
	{
		printf("Apotelesma = %.2f \n", num1-num2);		/* AFAIRESH ARITHMWN */
	}
	else if (praxi=='*')
	{
		printf("Apotelesma = %.2f \n", num1*num2);		/*POLLAPLASIASMOS ARITHMWN */
	}
	else if (praxi=='/' && num2==0)
	{
		printf("Division by zero not allowed \n");		/* PARONOMASTHS MHDEN */
	}
	else if (praxi=='/'&& num2!=0)
	{
		printf("Apotelesma = %.2f \n", num1/num2);		/* DIAIRESH ARITHMWN */
	}
	else
		printf("Lathos Praxh \n");		                /* LATHOS PRAKSH */

return 0;
}
