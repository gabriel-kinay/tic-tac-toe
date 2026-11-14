#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
#include <time.h>

int main()
{
    char grille[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    char joueur = 'X';
    char ordi = 'O';
    int choix;
    int l;
    int c;
    int tour = 0;

    while (tour != 9)
    {
    tab1(grille);
        while (choix < 1 || choix > 9 || grille[l][c] != ' ')
        {
            if (tour % 2 == 0)
            {
                printf("\n");
                printf("choisissez une case (1-9) : ");
                scanf("%d", &choix);
                l = (choix - 1) / 3;
                c = (choix - 1) % 3;
                grille[l][c] = joueur;
            } 
            else
            {
                srand(time(NULL));
                choix = rand() % 9 + 1;
                l = (choix - 1) / 3;
                c = (choix - 1) % 3;
                grille[l][c] = ordi;
            }
        }
        tour++;
    }
    tab1(grille);
    return 0;
}