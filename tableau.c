#include <stdio.h>
#include "tableau.h"

void tab1(char grille[3][3])
{
    //création des variables
    int l = 0;
    int c = 0;
    int compteur = 0;
    //cette boucle sert a creer les lignes
    while (l != 3)
    {
        //cette boucle sert a creer les colonnes
        while (c != 3)
        {
            printf("%c", grille[l][c]);
            // chaque tour on affiche | pour faire la case
            if (c < 2)
                printf("|");
            c++;
        }
        // on le remet a 0 car sinon il ne retourne plus dans la boucle
        c = 0;
        printf("\n");
        if (compteur < 2)
        {
            // chaque tour on affiche --- pour faire une ligne
            printf("%s\n", "-----");
            compteur++;
        }
        l++;
    }
}

int victoire(char grille[3][3], char symbole)
{
    int i = 0;
    //ce while sert a parourir les trois colonnes ou lignes en fonction du besoin
    while (i < 3)
    {
        // on parcourt ici les 3 lignes
        if (grille[i][0] == symbole && grille[i][1] == symbole && grille[i][2] == symbole)
            return 1;
        // et ici les 3 colonnes
        if (grille[0][i] == symbole && grille[1][i] == symbole && grille[2][i] == symbole)
            return 1;
        i++;
    }
    //ces deux conditions servent a verifier les deux diagonales
    if (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole)
        return 1;
    if (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole)
        return 1;
    // si aucune des conditions n'est verifié alors c'est que personne n'a encore gagné
    return 0;
}

