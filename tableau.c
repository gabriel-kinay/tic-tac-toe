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

int main()
{
tab1();
exit(0);

}
