#include "sudoku.h"


int main()
{
    int choix1,choix2;
    char reponse ;

    printf("*****************************Bonjour*****************************\n");
    file('_',65);
    printf("\n Ce programme peut suggerer une grille de Sudoku aleatoirement,");
    printf("\n et donne la solution exacte de elle selon les regles avec une");
    printf("\n precision du genre et de la difficulte de la grille.\n");
    printf("\n ------------------realise par Walid Hattaoui------------------- \n");
    file('_',65);
    printf("\nChoisir la forme de la grille de Sudoku: \n");

    do
    {

    printf("1 - La grille de Sudoku de la forme 4*4: \n");
    printf("2 - La grille de Sudoku de la forme 6*6: \n");
    printf("3 - La grille de Sudoku de la forme 9*9: \n");
    printf("Veuillez entrer la valeur de votre choix: \t ");
    scanf("%d",&choix1);
    file('_',65);
    printf("Choisir le niveau de la difficule: \n");
    printf("1 - pourcentage de 75 pour le rempilissage de la grille de 1 a 9: \n");
    printf("2 - pourcentage de 50 pour le rempilissage de la grille de 1 a 9: \n");
    printf("3 - pourcentage de 25 pour le rempilissage de la grille de 1 a 9: \n");
    printf("Veuillez entrer la valeur de votre choix: \t ");
    scanf("%d",&choix2);
    printf("\n");

    printf("\n ************La grille de Sudoku initiale suggeree: ************\n");
    switch (choix1)
    {
    case 1:
        while (choix1 == 1)
        {
            choix1=4;
            Sudoku_creation_affichage(choix1, choix2);
            printf("********La solution de la grille de Sudoku de type 4*4: ********");
            Sudoku_solution(choix1);
        }
        break;

    case 2:
         while (choix1 == 2)
        {
            choix1=6;
            Sudoku_creation_affichage(choix1, choix2);
            printf("********La solution de la grille de Sudoku de type 6*6: ********");
            Sudoku_solution(choix1);
        }
        break;
    case 3:
         while (choix1 == 3)
        {
            choix1=9;
            Sudoku_creation_affichage(choix1, choix2);
            printf("********La solution de la grille de Sudoku de type 9*9: ********");
            Sudoku_solution(choix1);
        }
        break;

    default: printf(" Votre choix n'etait pas bien choisi. \n");
        break;
    }


    printf("Voulez-vous faire une autre operation (O/N) ? :");
    scanf(" %c",&reponse);

    } while (reponse != 'N');

    return 0;
}
