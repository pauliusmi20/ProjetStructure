#ifndef _BIBLIO_H_
#define _BIBLIO_H_

#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/***********************************************
 * Bonjour ! 
 * 
 * c'est le header principale qui est inclut dans tout les fichier.
 * 
 * 
 * **********************************************/

//les NODES
typedef struct CellMorceau{
    struct CellMorceau *suiv;
    int num;
    char *titre;
    char *artiste;
}CellMorceau;

// la collection
typedef struct Biblio {
    CellMorceau *L;
    int nE;
}Biblio;


/* Charge au plus n morceaux par lecture du fichier nom_fichier */
Biblio *charge_n_entrees(const char *nom_fichier, int n);

#endif
