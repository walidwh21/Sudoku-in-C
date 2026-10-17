#include "sudoku.h"

void file(char c, int s)
{
     int i;
     // trace une ligne de m*char
     for( i=0; i<s; i++ ) printf("%c",c); printf("\n");

}

void Sudoku_creation_affichage(int dimension, int difficulte)
{
    int **Sudoku;
    Sudoku= (int**)malloc(sizeof(int*)*dimension);
    int i,j;
    srand((unsigned) time(0));
    int Matrice[dimension][dimension];

    for(i=0; i<dimension; i++)
    for(j=0; j<dimension; j++){

                Matrice[i][j]=(rand() %(dimension));
    }

    for( cell.ligne=0; cell.ligne<dimension; cell.ligne++){

        Sudoku[cell.ligne]=( int*)malloc(sizeof(int)*dimension);

        for(cell.colonne=0; cell.colonne<dimension; cell.colonne++){
           Sudoku[cell.ligne][cell.colonne]=Matrice[cell.ligne][cell.colonne];

               cell.ligne=0;
               cell.colonne=0;
               if( difficulte==1){
                   difficulte= dimension*bas; //la valeur de bas est dans le fichier sudoku.h
                   while(cell.ligne<=difficulte && cell.colonne<=difficulte){

                        Sudoku[cell.ligne][cell.colonne]=0;
                        cell.ligne++; cell.colonne++;
                   }

                   }else{
                       if( difficulte==2){
                            difficulte= dimension*moyen;
                            while(cell.ligne<=difficulte && cell.colonne<=difficulte){

                                    Sudoku[cell.ligne][cell.colonne]=0;
                                    cell.ligne++; cell.colonne++;
                            }

                            }else{
                                difficulte= dimension*haut;
                                while(cell.ligne<=difficulte && cell.colonne<=difficulte){

                                    Sudoku[cell.ligne][cell.colonne]=0;
                                    cell.ligne++; cell.colonne++;
                                }

                            }
                        }
        }

    }


    for(i=0; i<dimension; i++){ printf("-");}
    printf("\n");
    for(cell.ligne=0; cell.ligne<dimension; cell.ligne++){
        printf("|");

        for(cell.colonne=0; cell.colonne<dimension; cell.colonne++){
            printf("%d \t",Sudoku[cell.ligne][cell.colonne]);
            if((cell.colonne+1)%3==0 ){
            printf("|");
            }
        }
        printf("\n");
        if( (cell.ligne+1)%3==0 ){
              printf("-");
        }
        printf("\n");
    }
}

int ligne_verification( cellule cell , int dimension)
{
    //la verification de si la cellule de la grille est occupee ou non dans la ligne
    int **Sudoku;
    Sudoku= (int**)malloc(sizeof(int*)*dimension);
    for (cell.colonne = 0; cell.colonne < dimension; cell.colonne++)
    {
        if ( Sudoku[cell.ligne][cell.colonne] )
        {
            return 0;
        }
    }
    return 1;
}

int colonne_verification( cellule cell, int dimension)
{
    //la verification de si la cellule de la grille est occupee ou non dans la colonne
    int **Sudoku;
    Sudoku= (int**)malloc(sizeof(int*)*dimension);
    for (cell.ligne = 0; cell.ligne < dimension; cell.ligne++)
    {
        if ( Sudoku[cell.ligne][cell.colonne] )
        {
            return 0;
        }
    }
    return 1;
}

int grille_verification(cellule cell, int dimension)
{
    //la verification de si la cellule de la grille dans un carre de n*n est occupee ou non
    //la fonction est benifique dans la fonction Sudoku_solution pour respecter les regles du jeu
    int **Sudoku;
    Sudoku= (int**)malloc(sizeof(int*)*dimension);
    int l, c;
    if( dimension==4){
        cell.ligne = (cell.ligne / 2) * 2;
        cell.colonne = (cell.colonne / 2) * 2;

        for (l = 0; l < 2; l++)
        {
            for (c = 0; c < 2; c++)
            {
                if ( Sudoku[cell.ligne + l][cell.colonne + c] )
                {
                return 0;
                }
            }
         }
    }else{
        if( dimension==6){
                cell.ligne = (cell.ligne / 3) * 3;
                cell.colonne = (cell.colonne / 2) * 2;

                for (l = 0; l < 3; l++)
                {
                    for (c = 0; c < 2; c++)
                    {
                        if ( Sudoku[cell.ligne + l][cell.colonne + c] )
                        {
                        return 0;
                        }
                    }
                }
        }else{
            if( dimension==9){
                cell.ligne = (cell.ligne / 3) * 3;
                cell.colonne = (cell.colonne / 3) * 3;

                for (l = 0; l < 3; l++)
                {
                    for (c = 0; c < 3; c++)
                    {
                        if ( Sudoku[cell.ligne + l][cell.colonne + c] )
                        {
                        return 0;
                        }
                    }
                }
            }
        }
    }
    return 1;
}

//void cellule_a_cellule(cellule cell, int dimension)
//{
    //le transfert d'une cellule occupee a l'autre
    //if (cell.colonne < dimension)
        //Sudoku_solution(cell.ligne, cell.colonne + 1);
    //else
        //Sudoku_solution(cell.ligne + 1, 0);
//}

void Sudoku_solution( int dimension)
{
    int **Sudoku;
    Sudoku= (int**)malloc(sizeof(int*)*dimension);
    for(cell.ligne=0; cell.ligne<dimension; cell.ligne++)
    for(cell.colonne=0; cell.colonne<dimension; cell.colonne++){
        if (Sudoku[cell.ligne][cell.colonne] != 0)
        {
            //cellule_a_cellule(cell, dimension);
        }else{
            //un compteur pour vérifier les nombres de 1 à 9 si le nombre peut être rempli dans la cellule ou non
            int cpt;
            for (cpt=1; cpt<=9; cpt++)
            {
                if ((ligne_verification(cell, dimension)==1) && (colonne_verification(cell, dimension)==1) && (grille_verification(cell, dimension)==1))
                {
                    Sudoku[cell.ligne][cell.colonne] = cpt;
                    //cellule_a_cellule(cell , dimension);
                }
            }
        }
    }
}
