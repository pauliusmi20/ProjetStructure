#ifndef _BIBLIO_LISTE_H_
#define _BIBLIO_LISTE_H_

typedef struct CellMorceau{
    struct CellMorceau *suiv;
    int num;
    char *titre;
    char *artiste;
}CellMorceau;


typedef struct Noeud {
    char car;
    CellMorceau *liste_morceaux;
    struct Noeud *car_suiv;
    struct Noeud *liste_car;
} Noeud;


typedef struct Biblio {
    int nE;
    Noeud *A;
}Biblio;

//fonction recusrive qui désaloue la la memoire allouer precedéament
void libere_arbre_rec(Noeud *L);
void libere_list_morceau_term(CellMorceau *L);
#endif
