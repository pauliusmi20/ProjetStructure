#include "biblio.h"
#include "biblio_liste.h"

Biblio *nouvelle_biblio(void) {
	Biblio *bib = malloc(sizeof(Biblio));
    bib->nE=0;
    bib->L=NULL;
    return bib;
}

void libere_biblio(Biblio *B){
	CellMorceau *prev=NULL, *list=B->L;
    while(list){
        prev=list;
        list=list->suiv;
        free(prev);    
	}
    free(B);
}


// ON insere au début car cette méthode est beaucop plus rapide(d'ou l'utilisaton du poiinteur **, car on modifie l'adresse du pointeur *B).
// (complexité inferieur)
// insertion a la fin= parcours jusqu'a fin de liste a chaque insertion 
//simlement chainée.

void insere(Biblio **B, int num, char *titre, char *artiste){ 
    //initialisons la nouvelle cellule
    CellMorceau *new =(CellMorceau*) malloc(sizeof(CellMorceau));
    new->num=num;
    new->titre=titre;
    new->artiste=artiste;
    //...puis ajout au debut de liste
    new->suiv= (*B)->L;
    (*B)->L=(new);
    (*B)->nE++;
    //printf("------------------\n%d \t %s \t %s\n", new->num, new->titre, new->artiste);
    
}

void afficheMorceau(CellMorceau *cell){
	assert(cell); // test si null
    //printf("$L$ %8d $ %-32.32s $ %-32.32s $L$\n", cell->num, cell->titre, cell->artiste);
    printf("%8d \t %-32.32s \t %-32.32s\n", cell->num, cell->titre, cell->artiste);
    //printf("%d \t %s \t %s\n", cell->num, cell->titre, cell->artiste);
 }


void affiche(Biblio *B){
    assert(B);
    CellMorceau *list = B->L; 
    printf("%-8s \t %-32.32s \t %-32.32s\n--------------------------------------------------------------------------------\n","Numero", "Morceau", "Artiste");
    while((list)){
        afficheMorceau((list));
        list= list->suiv;
   }
}

Biblio *uniques (Biblio *B){
    
}

CellMorceau *rechercheParNum(Biblio *B, int num){
    assert(B);
    CellMorceau *res=NULL, *list=B->L; 
	while(list){
       if (list->num==num) {
           res=list; 
           break;
       }
       list=list->suiv;
   }
   return res;
}

CellMorceau *rechercheParTitre(Biblio *B, char *titre){
    assert(B); // on regarde si B n'est pas null -> si oui, cela provoque une erreur segmentation car B->L n'est pas définie.
    CellMorceau *res = NULL, *list= B->L; 
	printf("\n\nEn cours de recherche.\n");
    while(list){
       if (strcmp(list->titre, titre)==0) {
           res=list; break;
       }
       list=list->suiv;
       printf(".");  //un petit affichage pour observer l'avancement
    }
          printf("Fin de recherche.\n");  //un petit affichage pour observer l'avancement
   return res;	
}

Biblio *extraireMorceauxDe(Biblio *dB,const char *artiste){
	if(!dB)return NULL;// si videon retourne null 
    Biblio *res= nouvelle_biblio(); //nouvelle biblio
    CellMorceau *list= dB->L;// On décalre cette variable pour ne pas perdre le pointeur sur le début de la liste.
	while(list){
       if (strcmp(list->artiste,artiste)==0) {
           insere(&res,list->num,list->titre,list->artiste); 
       }
       list=list->suiv;
   }
   return res;
}


void insereSansNum(Biblio **B, char *titre, char *artiste){
	insere(B, (*B)->nE++, titre, artiste);
}

int supprimeMorceau(Biblio **B, int num){
	assert(*B);
    CellMorceau *prev=NULL, *list=(*B)->L;
    int res=0;
    while (list && !res){ 
        if (list->num==num){// Les cas si on trouve num dans le catalogue :
            if (!prev){        // -premier element correspond à num
                prev=(*B)->L;          
                (*B)->L = list->suiv;
                free(prev);
            }
            else if (!list->suiv){ // -dernier element correspond à num
                free(list);
                prev->suiv=NULL;
            }else{
                prev->suiv=list->suiv;   // -tout les autres elements
                free(list);     
            }
            (*B)->nE--;           
            res=1;  //succes:
            break; // on sort de la boucle.
        }
        prev=list;
        list=list->suiv; // sinon on iter.
    }
    return res;
    }

































