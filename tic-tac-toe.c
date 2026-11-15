//toutes les librairies que je dois utilisées
#include <stdio.h>
#include <stdlib.h>
#include "tableau.h"
//celle ci pour avoir un chiffre aléatoire 
#include <time.h>

//debut de la fonction 
int main()
{
    //initialistaion de toutes les variables
    //création du tableau
    char grille[3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    //creation des deux joueur different avec chacun leur signe
    char joueur = 'X';
    char ordi = 'O';
    int tour = 0;
    //ceci sert a avoir un nobre different à chaque tour
    srand(time(NULL));
    // on execute la boucle tantque l'on a pas remplit toutes les cases (plus tard j'ajouterais le ou tant que l'on a pas gagne)
    while (tour != 9)
    {
    int choix = 0;
    int l = 0;
    int c = 0;
    //sert a afficher la grille
    tab1(grille);
        //securite qui sert a voir si la personne choisit un nobre utilisable
        //il ne peut pas choisir des chiffres qui pourrait ne pas correspondre a une case
        //et il faut que la case choisit soit vide
        while (choix < 1 || choix > 9 || grille[l][c] != ' ' )
        {
            //condition pour voir quelle joueur dois jouer c'est toujours le vrai joueur qui commence
            if (tour % 2 == 0)
            {
                printf("\n");
                //demande une case et l'assimile ensuite a choix
                printf("choisissez une case (1-9) : ");
                scanf("%d", &choix);
                // on verifie bien que le joueur choisit un case qui est dans la grille
                if (choix != 1 && choix != 2 && choix != 3 && choix != 4 && choix != 5 && choix != 6 && choix != 7 && choix != 8 && choix != 9 )
                {
                    //si ce n'est pas le cas on arrete la partie
                    printf("Vous n'avez pas respecté la consigne la partie est finit ");
                    exit(0);
                }
                //petit message qui aide le joueur a se rendre compte que la case est deja prise
                if (choix != ' ')
                {
                    printf("cette case est déjà choisie");
                }
            } 
            else
            {
                //si c'est au bot de jouer alors le chiffre est pris au hasard
                choix = rand() % 9 + 1;
            }
            //cette condition sert juste a ne pas calculer les coordonnees des chiffres qui ne sont pas dans l'intervalles
            if (choix >= 1 && choix <= 9)   
            {
                //le calcul fait en sorte d'avoir le resultat entre 0 et 2
                l = (choix - 1) / 3;
                c = (choix - 1) % 3;
            }
        //enfin on finit par afficher le signe du joueur a la case correspondante
        }
        //verifie que si c'est au tour du joueur ou non pour savoir quel signe ajouté
        if (tour % 2 == 0)
            grille[l][c] = joueur;
        else
            grille[l][c] = ordi;
        // utilisation de la fonction victoire pour savoir si un des joueur a gagné
        if (victoire(grille, joueur))
        {
            tab1(grille);
            printf("\n");
            printf("vous avez gagné\n");
            return 0;
        }
        if (victoire(grille, ordi))
        {
            tab1(grille);
            printf("\n");
            printf("vous avez perdu\n");
            return 0;
        }
        //sert juste a rendre le jeu plus lisible
        printf("\n");
        //on passe au tour suivant
        tour++;
    }
    //s'il n'y a pas de victoire d'un camp ou de l'autre avant la fin de tous les tours alors c'est qu'il y a egalité
    //je l'ai mis hors de la boucle car sinon il y aurait egalité toujours au premier tour
    tab1(grille);
    printf("\n");
    printf("il y a égalité");
    return 0;
}