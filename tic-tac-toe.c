#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
#include <time.h>

int main()
{
    char grille[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    char joueur = 'X';
    char ordi = 'O';
    int tour = 0;
    tab1(grille);
    srand(time(NULL));
    while (tour != 9)
    {
    int choix = 0;
    int l = 0;
    int c = 0;
    tab1(grille);
        while (choix < 1 || choix > 9 || grille[l][c] != ' ' )
        {
            if (tour % 2 == 0)
            {
                printf("\n");
                printf("choisissez une case (1-9) : ");
                scanf("%d", &choix);
            } 
            else
            {
                choix = rand() % 9 + 1;
            }
            if (choix >= 1 && choix <= 9)   
            {
                l = (choix - 1) / 3;
                c = (choix - 1) % 3;
            }
        }
        if (tour % 2 == 0)
            grille[l][c] = joueur;
        else
            grille[l][c] = ordi;
        tour++;
    }
    tab1(grille);
    return 0;
}