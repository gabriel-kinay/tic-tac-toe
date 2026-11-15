#include <stdio.h>
#include <stdlib.h>

void tab1()
{
    char grille[3][3] = {{' ',' ',' '}, {' ',' ',' '},{' ',' ',' '}};
    int l = 0;
    int c = 0;
    int compteur = 0;
    while (l != 3)
    {
        while (c != 3)
        {
        printf("%c", grille[l][c]);
        printf("%c", '|' );
        c++;
        }
    c = 0;
    if (compteur <2)
    {
    printf("\n");
    printf("%s\n", "-------");
    compteur++;
    }
    l++;
    }
    
}

int victoire(char grille[3][3], char symbole)
{
    char *res;
    int i = 0;
    while (i < 3)
    {
        if (grille[i][0] == symbole && grille[i][1] == symbole && grille[i][2] == symbole)
            return 1;
        if (grille[0][i] == symbole && grille[1][i] == symbole && grille[2][i] == symbole)
            res = "vic";
        i++;
    }

    if (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole)
        return 1;
    if (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole)
        res = "vic";

    res = "def";
}

