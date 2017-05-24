#include <stdio.h>                  /* Logo printf(), fscanf(), fopen(), fclose() & strigs */
#include <stdlib.h>                 /* Logo exit(); */
#include <string.h>                 /* Logo Simboloseiron */
#include <time.h>

struct GAME_PLAYER      /* Onoma Domis Kai Stoixeia Domis */
{
	char name[17];      /* Pinakas 17 Xaraktiron -> 16+1 for \0 (null character) */
	int  score;         /* Akeraia Metavliti */
	char id;            /* Metavliti Xaraktira */
};

struct GAME_CARD        /* Onoma Domis Kai Stoixeia Domis Me Metavlites Xaraktiron */
{
    char colour;        /* Xroma */
    char symbol;        /* Sxima */
    char number;        /* Aritmos */
	char shading;       /* ifi */
};

struct GAME_CARD Card12[12];        /* Monodiastatos Pinakas Domon Gia 12 Tyxaies Kartes */
struct GAME_CARD Card3x4[3][4];     /* Disdiastatos Pinakas Domon 3 Grammon(0..2) kai 4 Stilon(0..3) */

/* Pinakas Domon Gia 3 Paixtes & Arxikopoiisi Entheton Domon Tous */
struct GAME_PLAYER Players[3] =  {{"Marina Andreou",0,'a'},{"Kostas Grammenos",0,'g'},{"Maria Perdika",0,'p'}};

/* 81 Pithanoi Sindismoi Karton */
struct GAME_CARD Card81[81] = {
/*  r =Kokkino      c =Kuklos (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'r','c','1','b'},      {'r','c','1','h'},      {'r','c','1','e'},
    {'r','c','2','b'},      {'r','c','2','h'},      {'r','c','2','e'},
    {'r','c','3','b'},      {'r','c','3','h'},      {'r','c','3','e'},

/*  r =Kokkino      T =Trigono (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'r','t','1','b'},      {'r','t','1','h'},      {'r','t','1','e'},
    {'r','t','2','b'},      {'r','t','2','h'},      {'r','t','2','e'},
    {'r','t','3','b'},      {'r','t','3','h'},      {'r','t','3','e'},

/*  r =Kokkino      r =Romvos  (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'r','r','1','b'},      {'r','r','1','h'},      {'r','r','1','e'},
    {'r','r','2','b'},      {'r','r','2','h'},      {'r','r','2','e'},
    {'r','r','3','b'},      {'r','r','3','h'},      {'r','r','3','e'},
/*-----------------------------------------------------------------------------------*/
/*  g =Prasino      c =Kuklos (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'g','c','1','b'},      {'g','c','1','h'},      {'g','c','1','e'},
    {'g','c','2','b'},      {'g','c','2','h'},      {'g','c','2','e'},
    {'g','c','3','b'},      {'g','c','3','h'},      {'g','c','3','e'},

/*  g =Prasino      t =Trigono (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'g','t','1','b'},      {'g','t','1','h'},      {'g','t','1','e'},
    {'g','t','2','b'},      {'g','t','2','h'},      {'g','t','2','e'},
    {'g','t','3','b'},      {'g','t','3','h'},      {'g','t','3','e'},

/*  g =Prasino      r=Romvos  (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'g','r','1','b'},      {'g','r','1','h'},      {'g','r','1','e'},
    {'g','r','2','b'},      {'g','r','2','h'},      {'g','r','2','e'},
    {'g','r','3','b'},      {'g','r','3','h'},      {'g','r','3','e'},
/*-----------------------------------------------------------------------------------*/
/*  b =Mple         c =Kuklos  (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'b','c','1','b'},      {'b','c','1','h'},      {'b','c','1','e'},
    {'b','c','2','b'},      {'b','c','2','h'},      {'b','c','2','e'},
    {'b','c','3','b'},      {'b','c','3','h'},      {'b','c','3','e'},

/*  b =Mple         t =Trigono (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'b','t','1','b'},      {'b','t','1','h'},      {'b','t','1','e'},
    {'b','t','2','b'},      {'b','t','2','h'},      {'b','t','2','e'},
    {'b','t','3','b'},      {'b','t','3','h'},      {'b','t','3','e'},

/*  b =Mple         r=Romvos  (3 Sindiasmoi) */
/*  b =Plires               h =Grammoskiasmeno      e =Keno-Mono Perigramma */
    {'b','r','1','b'},      {'b','r','1','h'},      {'b','r','1','e'},
    {'b','r','2','b'},      {'b','r','2','h'},      {'b','r','2','e'},
    {'b','r','3','b'},      {'b','r','3','h'},      {'b','r','3','e'},
};


/*
SET
*/

/*  Akeraia Sinartisi Pou Epistefi Timi */
/*  Periptoseis Pou Exoume SET Otan Sigrinontai Ta Stoixeia Domis Ton Karton */
int SetOK(struct GAME_CARD A, struct GAME_CARD B, struct GAME_CARD C)
{
    if(!((A.colour == B.colour) && (B.colour == C.colour) ||
         (A.colour != B.colour) && (A.colour != C.colour ) && (B.colour != C.colour)))
	{
	return 0;
	}

    if(!((A.symbol == B.symbol) && (B.symbol == C.symbol) ||
         (A.symbol != B.symbol) && (A.symbol != C.symbol ) && (B.symbol != C.symbol)))
	{
	return 0;
	}

    if(!((A.number == B.number) && (B.number == C.number) ||
         (A.number != B.number) && (A.number != C.number ) && (B.number != C.number)))
	{
	return 0;
	}

    if(!((A.shading == B.shading) && (B.shading == C.shading) ||
         (A.shading != B.shading) && (A.shading != C.shading ) && (B.shading != C.shading)))
	{
	return 0;
	}
	return 1;
}


 /*
 Sinartisi Gia Epilogi 12 Tuxaion Karton
 */
void GetNextCard()
{
int x, y, z, Same_Card, Temp_Card;          /* Akeraies Topikes Voithikes Metavlites */

   for(x=0; x<12; x++)
   {
       do                                   /* Eisodos Se Brogxo 12 Epanalipseon & Ektelesis Entolon */
       {
        Same_Card  =0;                      /* Oso Den Yparxoun Omoies Kartes */
        Temp_Card = rand() % 81;            /* H Prosorini Karta Pairnei Enan Tixaio Arithmo Apo 0 Eos 80*/
        Card12[x] = Card81[Temp_Card];      /* p.x H Karta i=1 Isoutai Me Ton Arithmo Tis Tixaias Kartas Pou Tha Prokipsei Apo Tin Sinartisi rand()% 81 Omoios & Oi Ypoloipes 11 Kartes */

       for (y=0; y<x; y++)                  /* Sigkrisi Karton */
        {
        if( (Card12[x].colour   ==  Card12[y].colour) &&    /* An Sindiasmos Xromatos 2 Karton Idios */
            (Card12[x].symbol   ==  Card12[y].symbol) &&    /* An Sindiasmos Sximatos 2 Karton Idios */
            (Card12[x].number   ==  Card12[y].number) &&    /* An Sindiasmos Arithmou 2 Karton Idios */
            (Card12[x].shading  ==  Card12[y].shading)      /* An Sindiamos Ifis 2 Karton Idios */
            )
            {
            Same_Card = 1;                                  /* Tote Brethikan 2 Omoies Kartes */
            break;                                          /* Epomenos Stamata */
            }
        }
        }
        while (Same_Card == 1);                             /* Eos Otou Brethoun Omoies Kartes */
    }

    z = 0;                              /* Arkikopoisi Boithitikis Metavlitis */
    for(x=0; x<3; x++)
        {
            for(y=0; y<4; y++)
        {
            Card3x4[x][y] = Card12[z];  /* Antigrafi Karton Se Pinaka 2 Diastaseon */
            z++;                        /* Auksise Kata 1 Kathe Fora */
        }
        }

   for(x=0; x<3; x++)
   {
    for(y=0; y<4; y++)
    {
        printf("[%c,%c,%c,%c]\t", Card3x4[x][y].colour, Card3x4[x][y].symbol, Card3x4[x][y].number, Card3x4[x][y].shading); /* Ektiposi Tixaion Karton */
    }
   		printf("\n\n");
   }
}


/*
Sinartisi Enarxis Paixnidiou
*/
void START_GAME(char id)
{

int x1, x2, x3, y1, y2, y3, Apotelesma; /* Akeraies Topikes Voithikes Metavlites */

struct GAME_CARD A;     /* 1h Karta */
struct GAME_CARD B;     /* 2h Karta */
struct GAME_CARD C;     /* 3h Karta */

do
    {
    GetNextCard();      /*Klisi Sinartisis Gia Epilogi Tuxaion Karton */

/*
CARD A
*/
    do      /* Eisagogi Se Brogxo Gia Epilogi Grammis 1hs Kartas & Ektiposi Sxetikon Epilogon */
    {
        printf("\nKarta No1..Epilogi GRAMMIS & STILIS\n");
        printf("-------------------------------------\n");
        printf("Grammi 1-> Press [0]\t");
        printf("Grammi 2-> Press [1]\t");
        printf("Grammi 3-> Press [2]\t\t\t\t");
        scanf("%d", &x1);   /* Eisagogi Epilogis Xristi Se Voithitiki Metavliti */
    }
    while(x1<0 || x1>2);    /* Epanalipsi Brogxou do An Epilexthei Diaforetiki Timi Apo Tis Epithimites */

    do      /* Eisagogi Se Brogxo Gia Epilogi Stilis 1hs Kartas & Ektiposi Sxetikon Epilogon */
    {
        printf("Stili  1-> Press [0]\t");
        printf("Stili  2-> Press [1]\t");
        printf("Stili  3-> Press [2]\t");
        printf("Stili  4-> Press [3]\t");
        scanf("%d", &y1);   /* Eisagogi Epilogis Xristi Se Voithitiki Metavliti */
    }
    while(y1<0 || y1>3);    /* Epanalipsi Brogxou do An Epilexthei Diaforetiki Timi Apo Tis Epithimites */

    A = Card3x4[x1][y1];    /* Stoixeia Sintetagmenon 1hs Kartas */


/*
CARD B
*/
    do  /* Eisagogi Se Brogxo Gia Epilogi Grammis 2hs Kartas & Ektiposi Sxetikon Epilogon */
    {
        printf("\nKarta No2..Epilogi GRAMMIS & STILIS\n");
        printf("-------------------------------------\n");
        printf("Grammi 1-> Press [0]\t");
        printf("Grammi 2-> Press [1]\t");
        printf("Grammi 3-> Press [2]\t\t\t\t");
        scanf("%d", &x2);   /* Eisagogi Epilogis Xristi Se Voithitiki Metavliti */
    }
    while(x2<0 || x2>2);    /* Epanalipsi Brogxou do An Epilexthei Diaforetiki Timi Apo Tis Epithimites */

    do  /* Eisagogi Se Brogxo Gia Epilogi Stilis 2hs Kartas & Ektiposi Sxetikon Epilogon*/
    {
        printf("Stili  1-> Press [0]\t");
        printf("Stili  2-> Press [1]\t");
        printf("Stili  3-> Press [2]\t");
        printf("Stili  4-> Press [3]\t");
        scanf("%d", &y2);   /* Eisagogi Epilogis Xristi Se Voithitiki Metavliti */
    }
    while(y2<0 || y2>3);    /* Epanalipsi Brogxou do An Epilexthei Diaforetiki Timi Apo Tis Epithimites */

    B = Card3x4[x2][y2];    /* Stoixeia Sintetagmenon 2hs Kartas */


/*
CARD C
*/
    do  /* Eisagogi Se Brogxo Gia Epilogi Grammis 3hs Kartas & Ektiposi Sxetikon Epilogon */
    {
        printf("\nKarta No3..Epilogi GRAMMIS & STILIS\n");
        printf("-------------------------------------\n");
        printf("Grammi 1-> Press [0]\t");
        printf("Grammi 2-> Press [1]\t");
        printf("Grammi 3-> Press [2]\t\t\t\t");
        scanf("%d", &x3);   /* Eisagogi Epilogis Xristi Se Voithitiki Metavliti */
    }
    while(x3<0 || x3>2);   /* Epanalipsi Brogxou do An Epilexthei Diaforetiki Timi Apo Tis Epithimites */

    do  /* Eisagogi Se Brogxo Gia Epilogi Stilis 3hs Kartas & Ektiposi Sxetikon Epilogon */
    {
        printf("Stili  1-> Press [0]\t");
        printf("Stili  2-> Press [1]\t");
        printf("Stili  3-> Press [2]\t");
        printf("Stili  4-> Press [3]\t");
        scanf("%d", &y3);   /* Eisagogi Epilogis Xristi Se Voithitiki Metavliti */
    }
    while(y3<0 || y3>3);    /* Epanalipsi Brogxou do An Epilexthei Diaforetiki Timi Apo Tis Epithimites */

    C = Card3x4[x3][y3];    /* Stoixeia Sintetagmenon 3hs Kartas */


/*
Bathmologia Vasei Apotelesmatos
*/
    Apotelesma = SetOK(A, B, C);

    if(Apotelesma == 1)    /* An Yparxei SET Ektiposi Sxetikou Minimatos & Thetiki Batmologisi Paixti */
    {
        printf("\nYou Have a SET...Continue\n\n");

        if(id == 'a')
        {
            Players[0].score += 2;  /* +2 Bathmous Ston 1o Paikti */
        }

        else if(id == 'g')
        {
            Players[1].score += 2;  /* +2 Bathmous Ston 2o Paikti */
        }

        else if(id == 'p')
        {
            Players[2].score += 2;  /* +2 Bathmous Ston 3o Paikti */
        }
    }

    else    /* An Den Yparxei SET Ektiposi Sxetikou Minimatos & Arnitiki Batmologisi Paixti*/
    {
        printf("\nNOT SET...!!! Try Again\n\n");

    if(id == 'a' && Players[0].score > 0)       /* An Bathmologia Tou 1ou Paikti Einai Pano Apo to 0 */
    {
        Players[0].score -= 1;                  /* Afairesi Enos Bathmou Apo Ton 1o Paikti */
    }

    else if(id == 'g' && Players[1].score > 0) /* An Bathmologia Tou 2ou Paikti Einai Pano Apo to 0 */
    {
        Players[1].score -= 1;                  /* Afairesi Enos Bathmou Apo Ton 2o Paikti */
    }

   else if(id == 'p' && Players[2].score > 0)  /* An Bathmologia Tou 3ou Paikti Einai Pano Apo to 0 */
    {
        Players[2].score -= 1;                  /* Afairesi Enos Bathmou Apo Ton 2o Paikti */
    }
    }

/*
Telos Paixnidiou An Enas Apo Tous 3 Paixtes Exei Score 10
*/
    if(Players[0].score == 10 || Players[1].score == 10 || Players[2].score == 10 )
    {
        printf("Telos Paixnidiou Ftasate Tous 10 Bathmous......\n");
        break;
    }
    }
    while(Apotelesma == 1);
}


/*
Sinartisi Menu
*/
int menu()	        /* Menou Epilogon Xristi */
{
    char choice;    /* Topiki Metavliti Xaraktiron */

	do
	{
	    printf("-----------------------------\n");
	    printf("Welcome To Card Game SET !!! \n");
	    printf("-----------------------------\n");
	    printf("Please Select Player id !!!\n");
	    printf("\nMarina Andreou ->[a] ");
        printf("Kostas Grammenos ->[g] ");
        printf("Maria Perdika ->[p]\n");
        printf("\n-----------------------------\n");
        printf("For Exit Game       ->[0]\n");
        fflush(stdin);
        scanf("%c", &choice);
	}
	while (choice !='0' && choice !='a' && choice !='g' && choice !='p');
}

/*
Sinartisi Main
*/
int main()
{
    int x, Maximum_Score;   /* Akeraies Boithitikes Metavlites */
    char Epilogi;           /* Metavliti Xaraktiron */
    char Nikitis[17];       /* Kostast Grammenos -> max lenght */

    struct GAME_CARD A;     /* 1h Karta */
    struct GAME_CARD B;     /* 2h Karta */
    struct GAME_CARD C;     /* 3h Karta */

    time_t t;                   /* Dimourgia Tuxaion Arithon */
    srand((unsigned) time(&t)); /* Random Number Generator Algorithm */


while (Epilogi !='0')
{
    Epilogi = menu();           /* Klisi Tis Sinartisis Menu() */

	if(Epilogi == 'a')          /* Epilogi Paixtrias Marinas Andreou */
    {
        START_GAME(Epilogi);
    }
    if(Epilogi == 'g')          /* Epilogi Paixti Kosta Grammenos */
    {
        START_GAME(Epilogi);
    }
    if(Epilogi == 'p')          /* Epilogi Paixtrias Maria Perdika */
    {
        START_GAME(Epilogi);
    }
}

/*
Evresi Megistou Score Kai Nikiti Paixnidiou
*/
for (x=0; x<3; x++)
	{
    printf("id [%c] Name:[%s]\t Score:[%d] \n", Players[x].id, Players[x].name, Players[x].score);
	}

    Players[0].score> Maximum_Score;
    Maximum_Score = Players[0].score;       /* Arxikopoisi Megistou Score Apo Ton 1o Paixti */
   {
       strcpy(Nikitis, Players[0].name);    /* Antigrafi Onomatos 1ou Paixti stin Metavliti Nikitis */
   }

   if (Players[1].score > Maximum_Score)    /* Sigkrisi Megistou Score Me 2o Paixti Gia To An Einai Megalitero */
   {
   		Maximum_Score = Players[1].score;   /* To Megisto Score Einai Pleon Tou 2ou Paixti */
   		strcpy(Nikitis, Players[1].name);   /* Antigrafi Onomatos 2ou Paixti stin Metavliti Nikitis */
   }

   if (Players[2].score > Maximum_Score)     /* Sigkrisi Megistou Score Me 3o Paixti Gia To An Einai Megalitero */
   {
   		Maximum_Score = Players[2].score;    /* To Megisto Score Einai Pleon Tou 3ou Paixti */
   		strcpy(Nikitis, Players[2].name);    /* Antigrafi Onomatos 3ou Paixti stin Metavliti Nikitis */
   }

   if(Maximum_Score > 0)                    /* Ektiposi Nikiti */
   {
       printf("\nNikitis [%s]\t Score:[%d]\n", Nikitis, Maximum_Score);
   }

    else
    {
        printf("\nISOPALIA \n");
    }

   return(0);
}



/*
http://cgi.di.uoa.gr/~ip/Cfunctionsref.html
http://www.cplusplus.com/reference/cstdlib/rand/
https://www.tutorialspoint.com/c_standard_library/c_function_srand.htm
https://github.com/henrikw/SetGame/blob/master/src/SetGame.java
https://www.youtube.com/watch?v=QCe2ks9b8YI
*/
