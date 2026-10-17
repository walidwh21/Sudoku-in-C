#ifndef SUDOKU_H_INCLUDED
#define SUDOKU_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define bas 0.75
#define moyen 0.5
#define haut 0.25

typedef struct{

    int ligne;
    int colonne;

}cellule;

cellule cell;

extern void file(char , int );
extern void Sudoku_creation_affichage(int , int );
extern int ligne_verification( cellule , int );
extern int colonne_verification( cellule , int );
extern int grille_verification(cellule , int );
extern void cellule_a_cellule(cellule, int );
extern void Sudoku_solution(int );

#endif // SUDOKU_H_INCLUDED
