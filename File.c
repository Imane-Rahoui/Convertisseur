#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#define ENTRER 13
#define BACKSPACE 8
#define TAILLEMAX 9
void aff_nbr(long nbr);
void nbr_inf_70(char lettres[], long nbr);
void nbr_70_99(char lettres[], long nbr);
void nbr_100_999(char lettres[], long nbr);
void IMPORTANT(char lettres[], long nbr);
void nbr_inf_70(char lettres[], long nbr)
{
    char motssimple[25][30] = { {"zero"}, {"un"}, {"deux"}, {"trois"}, {"quatre"}, {"cinq"}, {"six"}, {"sept"}, {"huit"}, {"neuf"}, {"dix"}, {"onze"}, {"douze"}, {"treize"}, {"quatorze"}, {"quinze"}, {"seize"} };
    char dizaine[25][30] = { {"dix"},{"vingt"},{"trente"},{"quarante"},{"cinquante"},{"soixante"} };

    if (nbr <= 16)
        strcat(lettres, motssimple[nbr]);
    else if (nbr % 10 != 1 && nbr > 16)
    {
        if (nbr % 10 == 0)
            strcat(lettres, dizaine[(nbr / 10) - 1]);
        else
        {
            strcat(lettres, dizaine[(nbr / 10) - 1]);
            strcat(lettres, "-");
            strcat(lettres, motssimple[nbr % 10]);
        }
    }
    else
    {
        strcat(lettres, dizaine[(nbr / 10) - 1]);
        strcat(lettres, " et un");
    }

}
void nbr_70_99(char lettres[], long nbr)
{
    if (nbr < 80 && nbr>69)
    {
        if (nbr % 10 != 1)
        {

            strcat(lettres, "soixante-");
            nbr_inf_70(lettres, nbr - 60);

        }

        else
        {

            strcat(lettres, "soixante et onze");

        }
    }
    else if ((nbr % 10 != 0 || nbr == 90) && nbr % 10 != 1)
    {
        strcat(lettres, "quatre-vingt-");
        nbr_inf_70(lettres, nbr - 80);
    }
    else if (nbr % 10 == 1)
    {
        strcat(lettres, "quatre-vingt et ");
        nbr_inf_70(lettres, nbr - 80);

    }
    else
        strcat(lettres, "quatre-vingts");
}
void nbr_100_999(char lettres[], long nbr)
{
    if (nbr / 100 != 1)
    {
        nbr_inf_70(lettres, nbr / 100);
        strcat(lettres, " ");
    }
    strcat(lettres, "cent ");
    if (nbr / 100 != 1 && nbr % 100 == 0)
        strcat(lettres, "\bs");
    else if (nbr / 100 != 1 && nbr % 100 != 0)
    {
        nbr = nbr % 100;
        if ((nbr <= 16 || nbr > 16) && nbr < 70)
            nbr_inf_70(lettres, nbr);
        else
            nbr_70_99(lettres, nbr);
    }

}



void IMPORTANT(char lettres[], long nbr)
{
    if (nbr / 1000000 % 1000 != 0)
    {
        if (nbr / 1000000 < 70)
            nbr_inf_70(lettres, nbr / 1000000);
        else if (nbr / 1000000 < 100)
            nbr_70_99(lettres, nbr / 1000000);
        else if (nbr / 1000000 < 1000)
            nbr_100_999(lettres, nbr / 1000000);

        strcat(lettres, " millions");
        if (nbr / 1000000 > 100 && nbr % 1000000 != 0)
        {
            strcat(lettres, "\n");
            strcat(lettres, "\t\t");
        }
        if (nbr / 1000000 == 1)
            strcat(lettres, "\b ");
        nbr = nbr % 1000000;


    }

    if (nbr / 1000 % 1000 != 0)
    {
        if (nbr / 1000 != 1)
        {
            if (nbr / 1000 < 70)
                nbr_inf_70(lettres, nbr / 1000);
            else if (nbr / 1000 < 100)
                nbr_70_99(lettres, nbr / 1000);
            else if (nbr / 1000 < 1000)
                nbr_100_999(lettres, nbr / 1000);

        }
        strcat(lettres, " mille ");
        if (nbr / 1000 > 100 && nbr % 1000 != 0)
        {
            strcat(lettres, "\n");
            strcat(lettres, "\t\t");
        }
        nbr = nbr % 1000;

    }
    if (nbr / 100 % 1000 != 0)
    {
        nbr_100_999(lettres, nbr);

    }
    if (nbr < 70)
        nbr_inf_70(lettres, nbr);
    else if (nbr < 100)
        nbr_70_99(lettres, nbr);
}
void main()
{

    char c, cpt, saisir_nombre[TAILLEMAX], nombrefinal[TAILLEMAX], lettres[100];
    int i;

    long nbr;
    cpt = 0;
    printf("\t\tCONVERSION CHIFFRES EN LETTRES\n\n");
    printf("Chiffres:\t");
    do
    {

        c = _getch();
        if (c >= '0' && c <= '9' && cpt < TAILLEMAX)
        {
            printf("%c", c);
            saisir_nombre[cpt] = c;
            cpt++;
        }
        if ((c == BACKSPACE) && cpt > 0)
        {
            printf("\b \b");
            cpt--;
        }
    }     while (c != ENTRER);
    for (i = 0; i < cpt; i++)
        nombrefinal[i] = saisir_nombre[i];
    lettres[0] = '\0';
    strcat(lettres, "test");
    nbr = atoi(nombrefinal);
    lettres[0] = '\0';
    printf("\n");
    printf("Lettres:\t");
    IMPORTANT(lettres, nbr);
    printf("%s", lettres);
    _getch();
    clrscr();
}

