// ERGASIA 1 - MEROS 3 - DYADIKH ANAPARASTASH ARI8MOY

#include <stdio.h>

int main(void)
{
    int const diaireths = 2;  /* DHLWNOUME STA8ERA EFOSON DIAIROYME PANTA ME TO 2 */
    int diaireteos, ypoloipo;


    printf("DYADIKH ANAPARASTASH AKERAIOY ARI8MOY \n");

    do
    {
    printf("\n[ PROSOXH MPOREITE NA DWSETE MONO 8ETIKOYS AKERAIOYS ARI8MOYS ] \n\n");
    printf("DWSTE ENAN AKERAIO 8ETIKO ARI8MO : \t");
    scanf("%d", &diaireteos);
    }
    while (diaireteos < 0);

    printf("\n\nANAPARASTASH TOY AKERAIOY  %d  SE DYADIKO : \t", diaireteos);

   while(diaireteos > 0)
   {
    ypoloipo = diaireteos % diaireths;              /* % TELESTHS AKERAIOY YPOLOIPOY */
    putchar(ypoloipo ? '1' : '0');
    diaireteos = (diaireteos - ypoloipo) / diaireths;
   }

return 0;

}
