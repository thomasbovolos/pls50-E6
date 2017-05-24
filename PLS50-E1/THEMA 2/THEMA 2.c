// ERGASIA 1 - MEROS 2 - GEWMETRIKOI YPOLOGISMOI

#include <stdio.h>
#include <math.h>

/* MA8HMATIKOI TYPOI - PROTWTYPES SYNARTHSEIS */

float perimetros_tetragwnoy (float a)	/* 1. TYPOS PERIMETROY TETRAGWNOY */
{
    return 4*a;
}

float perimetros_parallhlogrammoy (float a, float b) /* 2. TYPOS PERIMETROY PARALLHLOGRAMMOY */
{
	return 2*a + 2*b;
}

float perimetros_orthogwnioy_trigwnoy (float a, float b) /* 3. TYPOS PERIMETROY OR8OGWNIOY TRIGWNOY */
{
	float c;
    c = sqrt(a*a + b*b);      /* YPOLOGISMOS YPOTEINOYSAS */
	return a+b+c;
}

float perimetros_kykloy(float a) /* 4. TYPOS PERIMETROY KYKLOY */
{
	const float p = 3.14;   /* DHLWSH STA8ERAS P */
	return 2*p*a;
}

int menu(void)	     /* SYNARTHSH MENU GIA EPILOGES XRHSTH*/
{
	char choice;

	do
	{
	printf("PARAKALW EPILEKSETE POIOY GEWMETRIKOY SXHMATOS THN PERIMETRO 8ELETE NA YPOLOGISETE: \n\n");
	printf("1. TETRAGWNO \n \n");
	printf("2. PARALLHLOGRAMMO \n \n");
	printf("3. ORTHOGWNIO TRIGWNO \n \n");
	printf("4. KYKLOS \n \n");
	printf("0. Eksodos \n \n \n");
	printf("Poia Einai H Epligh Sas : \t");
	scanf(" %c", &choice);
	}
	while (choice !='0' && choice !='1' && choice !='2' && choice !='3' && choice !='4');


return choice;
}


int main (void)
{
int epilogi;
float pleyra1, pleyra2, aktina;

while (epilogi !='0')
{
if (epilogi=='1')	            /* DEDOMENA TETRAGWNOY */
	{
	printf("\n DWSTE TO MHKOS THS PLEYRAS TOY TETRAGWNOY : \t");
	scanf("%f", &pleyra1);
	printf("\n\n H PERIMETROS TOU TETRAGWNOY EINAI : %.2f \n\n\n", perimetros_tetragwnoy(pleyra1));
	}

if (epilogi=='2')	            /* DEDOMENA PARALHLLOGRAMMOY */
	{
	printf("\n DWSTE THN PLEYRA A \t");
	scanf("%f", &pleyra1);
	printf("\n DWSTE THN PLEYRA   B \t");
	scanf(" %f", &pleyra2);
	printf("\n\n H PERIMETROS TOY PARALLHLOGRAMMOY EINAI : %.2f \n\n\n", perimetros_parallhlogrammoy(pleyra1, pleyra2));
	}

if (epilogi=='3')	            /* DEDOMENA OR8OGWNIOY TRIGWNOY */
	{
	printf("\n DWSTE TO MHKOS THS 1HS KATHETHS PLEYRAS TOY ORTHOGWNIOU : \t");
	scanf("%f", &pleyra1);
	printf("\n DWSTE TO MHKOS THS 2HS KATHETHS PLEYRAS TOY ORTHOGWNIOU : \t");
	scanf("%f", &pleyra2);
	printf("\n\n H PERIMETROS TOY ORTHOGWNIOY TRIGWNOY EINAI : %.2f \n\n\n", perimetros_orthogwnioy_trigwnoy(pleyra1, pleyra2));
	}

if (epilogi=='4')	            /* DEDOMENA KYKLOY */
	{
	printf("\n DWSTE THN AKTINA TOY KYKLOY : ");
	scanf("%f", &aktina);
	printf("\n\n H PERIMETROS TOY KYKLOY EINAI : %.2f \n\n\n", perimetros_kykloy(aktina));
	}

epilogi = menu();

}

return 0;

}
