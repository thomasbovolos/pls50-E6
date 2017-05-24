#include <stdio.h>                  /* Logo printf(), fscanf(), fopen(), fclose() & strigs */
#include <stdlib.h>                 /* Logo exit(); */
#include <string.h>                 /* Logo Simboloseiron */
#define  MAXSEATS 53                /* Megistos Arithmos Thesewn Bus */


/*
Dilosi Tipou Kai Metavliton Domis
*/
struct EPIVATIS                     /* Onoma Domis Kai Stoixeia Domis */
{
	char fullname[40];              /* Pinakas 40 Xaraktiron -> 39+1 for \0 (null character) */
	unsigned short phone_number[10];/* Pinakas Mias Diastasis 10 Thesewn */
	unsigned int seat_number;
};

struct EPIVATIS bus_seats[MAXSEATS];/* Pinakas Domis -> bus_seats */

char pinakida[8];                   /* Pinakas 8 Xaraktiron -> 7+1 for \0 (null character) */
char arxeio[54];                    /* Pinakas 54 Xaraktiron -> 53+1 for \0 (null character) */
int i, j, seat, reserve;            /* Akeraies Voithikes Metavlites */


/*
Diabasma Arxeioy bus.txt
*/
void read_file()
{
    int seat_number2;    		    /* Akeraia Voithiki Metavliti */

    FILE *read;                     /* Metabliti-Deikti Se Arxeio */
    read = fopen("bus.txt", "r");   /* Anoigei To Arxeio Eisodou*/

	if (read == NULL)               /* Se Periptosi Problimatos Kata To Anoigma Ektiposi Minimatos Lathous & Eksodos */
	{
		printf("To Arxeio Bus.txt Den Mporese Na Anoixtei.....\n");
		exit(1);
	}

   if(fgets(arxeio, 54, read) != NULL)  /* Diavasma Arxeiou & Emfanisi Arithmou Pinakas Kai Arithmou Theseon */
   {
       strtok(arxeio, " ");
       while(arxeio[i] !='\0')
		{
			pinakida[i] = arxeio[i];                /* Arithmos Pinakidas */
			i++;
		}
		seat_number2 = atoi(strtok(NULL, " "));     /* Arithmos Theseon */
   }
	printf("Pinakida leoforiou: %s\n", pinakida);
	printf("Arithmos theseon: %d\n", seat_number2);

   fclose(read);
}


/*
Arxikopoiisi Pinaka Theseon
*/
void arxikopoiisi()
{
	for(i=0; i<MAXSEATS; i++)
   {
	   	bus_seats[i].fullname[0] = '\0';        /* Arxikopoiisi Onomateponimou */

	   	for (j=0; j<10; j++)
	   	{
			bus_seats[i].phone_number[j] = 0;   /* Arxikopoiisi Arithmou Tilefonou */
		}
	   	bus_seats[i].seat_number = 0;           /* Arxikopoiisi Arithmou Thesis */
   }
}



/*
Epilogi 1. Kenes Theseis - Taksinomisi
*/
void choice1()
{
int count = 0;                                          /* Arxikopoiisi Metavlitis -> Metritis */

for (i=0; i<MAXSEATS; i++)
{
    if ((bus_seats[i].fullname[0]) == '\0')             /* An Thesi Keni */
    {
        count++;                                        /* Auksisi Metriti Gia Oso Thesi Keni*/
        printf("[%d]\t", i+1);                          /* Ektiposi Kenon Theseon */

    }
}
    printf("\n \nKenes Theseis ->\t [%d]\n", count);        /* Ektiposi Kenon Theseon */
    printf("\nKatelimenes ->\t\t [%d]", MAXSEATS-count);    /* Ektiposi Kateleimenon Theseon */
}


/*
Epilogi 2. Kratisi Thesis
*/
void choice2()
{
    printf("Doste Arithmo Thesis:\t");
    scanf("%d", &seat);

    if(seat<1 || seat>MAXSEATS)                 /* Elegxos Oti O Arithmos Thesis Einai Entos Orion kai Ektiposi Analogou Minimatos */
        {
        printf("\nArithmos Thesis Ektos Orion.... Epilekste Knana\n\n");
        choice2();
        }

    if(bus_seats[seat-1].fullname[0] !='\0')    /* Elegxos Gia Diathesimotita Tis Thesis kai Ektiposi Analogou Minimatos */
        {
            printf("\n");
            printf("Kratimeni Thesi Eisagete Ksana....\n\n");
            choice2();
        }
        else
        {
            fflush(stdin);                                      /* Katharisma Mninmis */
            printf("\nEisagete Epitheto & Onoma Epivati:\t");
            gets(bus_seats[seat-1].fullname);                   /* Diavasma Epilogis Xristi kai Topothetisi Se Pinaka Domis */
            fflush(stdin);
            printf("Tilefono Epivati:\n");

            for (j=0; j<10; j++)
            {
                scanf("%d", &bus_seats[seat-1].phone_number[j]);/* Diavasma Epilogis Xristi kai Topothetisi se Pinaka Domis */
            }
        }
         bus_seats[seat-1].seat_number = seat;                  /* Topothetisi Aritmou Thesis Se Pinaka Domis */
    }


/*
Ypoepilogi 3.1 Anazitisi Me Onomateponimo
*/
void sub_choice1()
{
    char fullname2[40];     /* Pinakas 40 Xaraktiron -> 39+1 for \0 (null character) */

    printf("\nOnomateponimo Tou Epivati Pou Anazitate...?\n");  /* Ektiposi Minimatos Anazitisis */
    fflush(stdin);                                              /* Katharisma Mninmis */
    gets(fullname2);                                            /* Diavasma Epilogis Xristi*/
    reserve =0;                                                 /* Arxipoisi Metavlitis -> Thesi Keni */
				for(i=0; i <MAXSEATS; i++)
				{
				    if(strcmp(bus_seats[i].fullname, fullname2) == 0)    /* Sygkrisi Stoixeion */
					{
					    reserve =1;        /* Brethike Eggrafi -> Thesi Kratimeni -> Ektiposi Minimatos */
					    printf("\nBrethike THESI KRATIMENI Me Auto To Onomateponimo...\n");
					}
				}
					if(reserve == 0)       /* An Den Brethei Eggrafi -> Ektiposi Sxetikou Minimatos */
					{
						printf("\nDEN Brethike THESI KRATHIMENI Me Auto To Onomateponimo...\n");
					}
}


/*
Ypoepilogi 3.2 Anazitisi Me Aritmo Tilefonou
*/
void sub_choice2()
{
    unsigned short phone_number2[10];                   /* Voithitikos Pinakas Mias Diastasis 10 Thesewn */

    printf("\nTilefono Epivati Pou Anazitate...?\n");   /* Ektiposi Minimatos Anazitisis */

				for(j=0; j<10; j++)
				{
					scanf("%d", &phone_number2[j]);     /* Diavasma Tis Epilogis Xristi Se Voithitiko Pinaka */
				}

				for(i=0; i<MAXSEATS; i++)
				{
					reserve = 0;                        /* Arxikopoiisi Metavlitis */
					for(j=0; j<10; j++)
					{
						if (bus_seats[i].phone_number[j] == phone_number2[j])   /* Sygkrisi Stoixeiou Pinaka Domis Me Voithitiko Pinaka */
						{
							reserve++;                  /* Afksisi Metavlitis Kata 1*/
						}
					}
					if (reserve == 10)                  /* Sta 10 Stoixeia Stamata */
					{
                    break;
					}
				}

				if (reserve == 10)                      /* Brethike Eggrafi -> Ektiposi minimatos*/
                    {
					    printf("Brethike THESI KRATHIMENI Me Auto To Tilefono...\n");
                    }
				else                                    /* Den Brethike -> Ektiposi minimatos*/
					{
					    printf("DEN Brethike THESI KRATHIMENI Me Auto To Tilefono...\n");
                    }
}

/*
Epilogi 3. Lista Kratimenon Theseon
*/
void choice3()
{
 int sub_choice;                /* Akeraia Metavliti Gia Ypoepiloges Tis Epilogis 3 */

    sub_choice = 1;
    while(sub_choice !=0)       /* Brogxos Gia Emfanisi Menou Ypoepilogon */
        {
        printf("\n\n-----------------");
        printf("\nMenou YpoEpilogon\n");
        printf("-----------------\n");
        printf("Anazitisi Kratimenis Thesis Me Kritirio Epilogis:\n\n");
        printf("1. Me Onomateponimo Epivati :\n");
        printf("2. Me Tilefono Epivati :\n");
        printf("----------------------------\n");
        printf("0. Epistrofi Se Arxiko Menou");
        printf("\n----------------------------\n");
        printf("Parakalo Epilekste:\t");
        scanf("%d", &sub_choice);
        printf("\n \n");
        printf("\nEpileksate: [% d]\n\n", sub_choice);

        switch(sub_choice)
        {
            case 1:
                if(sub_choice == 1) {sub_choice1();}    /* Ypoepilogh 1.*/
                break;

            case 2:
                if(sub_choice == 2) {sub_choice2();}    /* Ypopilogh 2.*/
                break;

            case 0:                                     /* Min Kaneis Tipota */
                break;

            default:                                    /* Gia Epilogi Ektos 0-2*/
            printf("Akatallili Epilogi\n");
    }
    }
}

/*
Epilogi 4. Akirosi Kratisis
*/
void choice4()
 {
    printf("Doste Arithmo Thesis:\t");
    scanf("%d", &seat);

    if(seat<1 || seat>MAXSEATS)         /* Elegxos Arithmou Thesis An Einai Entos Orion Kai Ektiposi Analogou Ìinimatos */
    {
        printf("\nArithmos Thesis Ektos Orion.... Epilekste Knana\n\n");
    }

    if(i>0 || seat<MAXSEATS)
        {
            if(bus_seats[seat-1].fullname[0] != '\0')
            {
                bus_seats[seat-1].fullname[0] = '\0';               /* Arxikopoiisi Onomateponimou */

                for (j=0; j<10; j++)
                    {
                        bus_seats[seat-1].phone_number[j] = 0;      /* Arxikopoiisi Arithmou Tilefonou */
                    }

                    bus_seats[seat-1].seat_number = 0;              /* Arxikopoiisi Arithmou Thesis */

                    printf("\nThesi Pou Akirosate [%d]\n", seat);   /* Ektiposi Miinimatos Akirosis */
            }
    else
        {
	    printf("\nKeni Thesi....... \n");
        }
        }
 }


/*
Epilogi 5. Lista Kratimenon Theseon
*/
void choice5()
{
    for(i=0; i<MAXSEATS; i++)
    {
        if ((bus_seats[i].fullname[0]) != '\0')     /* Ean Yparxoun Eggrafes */
        {
            reserve = 1;                            /* Thesei Kratimeni Kai Ektiposi Tis Thesis*/
            printf("Kathisma:[%d] Onomatepwnymo:[%s] ", bus_seats[i].seat_number, bus_seats[i].fullname);
            printf("Telephone Number:[" );
            for (j= 0; j<10; j++)
                {
                    printf("%d", bus_seats[i].phone_number[j]);
                }
					printf("]\n");
        }
        }
		   		if(reserve == 0)                    /* Ean Den Brethoun Eggrafes Ektiposi Minimatos Lathous*/
				{
				 printf("Den Yparxoun Kratimenes Theseis\n");
				}
 }


/*
Apothikeusi Arxeiou bus.txt
*/
void save_file()
{
    FILE *write;                        /* Metabliti-Deikti Se Arxeio */
    printf("Saving File bus.txt\n");
    write = fopen("bus.txt", "w");      /* Anoigei To Arxeio Ejodou*/

    if (write == NULL)                  /* Se Periptosi Problimatos Kata To Anoigma Ektiposi Minimatos Lathous & Eksodos*/
    {
        printf("To Arxeio Bus.txt Den Mporese Na Anoixtei.......\n");
        exit(1);
    }

	fprintf (write,"%s ", pinakida);
	fprintf (write,"%d\n", seat);

    for (i=0; i<MAXSEATS; i++)
    {
        if((bus_seats[i].fullname[0]) !='\0')
        {
            fprintf(write, "%s ", bus_seats[i].fullname);               /* Apothikeusi Se Arxeio Tou Onomateponimou */
            fprintf(write, "%d ", bus_seats[i].seat_number);            /* Apothikeusi Se Arxeio Tou Aritmou Thesis */

            for (j=0; j<10; j++)
            {
                fprintf(write, "%d", bus_seats[i].phone_number[j]);     /* Apothikeusi Se Arxeio Tou Arithmou Tilefonou */
            }
            fprintf(write,"\n");                                        /* Sosimo Epomenis Kenis Grammis -> Enter */
        }
            fclose(write);                                              /* Kleisimo Arxeiou */
    }
}


int main()
{

int choice;             /* Akeraia Metavliti */

read_file();            /* Klisi Sinartisis Gia Anoigma Arxeiou */
arxikopoiisi();         /* Klisi Sinartisis Gia Arxikopoisii Kenon Theseon */


choice =1;              /* Arxiki Timi Gia Eisodo Sto Loop */
while (choice !=0)      /* Gia Oso Den Epilegetai To 0 -> Termatismos Na Ektelountai Oi Entoles -> Menou Epilogon */
    {
    printf("\n\n-------------");
    printf("\nMenou Epilogon\n");
    printf("-------------\n");
    printf("1. Emfanisi Sinolikou Plithous Kenon Theseon & Taksinomisi Me Ton Arithmon Tous\n");
    printf("2. Kratisi Thesis Me Sigkekrimeno Arithmo & Stoxeia Epivati\n");
    printf("3. Anazitisi Kratimenis Thesis (Me Onomateponimo H' Arithmo Tilefonou\n");
    printf("4. Akirosi Kratisis Thesis Me Sigkekrimeno Arithmo\n");
    printf("5. Lista Krathmenon Theseon (Onomateponino - Tilefono - Arithmos Epivati)\n");
    printf("------------------------------------------------------------------------------\n");
    printf("0. Termatismos Programmatos\n");
	printf("------------------------------------------------------------------------------\n");
    printf("Parakalo Epilekste:\t");
	scanf("%d", &choice);
    printf("\n \n");
    printf("\nEpileksate: [%d]\n\n", choice);


    switch(choice)
    {
    case 1:     /* Epilogh 1.*/
        if(choice == 1) {choice1();}
        break;

    case 2:     /* Epilogh 2.*/
        if(choice == 2) {choice2();}
        break;

    case 3:     /* Epilogh 3.*/
        if(choice == 3) {choice3();}


    case 4:     /* Epilogh 4.*/
        if(choice == 4) {choice4();}
        break;

    case 5:     /* Epilogh 5.*/
        if(choice == 5) {choice5();}
        break;

    case 0:     /* Termatismos */
        break;

    default:    /* Epilogi Ektos Oriion 0-5 */
        printf("Akatallili Epilogi.....\n");
    }
    }

save_file();   /* Klisi Sinartisis Gia Apothikeusi Arxeiou */
}


/*
http://cgi.di.uoa.gr/~ip/Cfunctionsref.html
*/
