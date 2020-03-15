#include "biblio.h"
#include "biblio_arbrelex.h"

Biblio *nouvelle_biblio(void) {
	//allocation de memoire d'une bibliothèque
    Biblio *bib =(Biblio*) malloc(sizeof(Biblio));
    bib->nE=0;
    bib->A=NULL;
    return bib;
}
//PAS SUR DU NOM
void libere_list_morceau_term(CellMorceau *L){
    CellMorceau *morceau=L;
    if (morceau){
        libere_liste_morceau_rec(morceau);
    }else{
        
        return;
    }
}
void libere_list_morceau_iter(CellMorceau *L){
    assert(L);
    CellMorceau *morceau=L;
    while (L){
        morceau=L;
        L=L->suiv;
        free(morceau);
    }    
}

void libere_liste_rec(Biblio **B){
    Noeud *node=(*B)->A;
    if(node->liste_car){
        libere_liste_rec(&(node->liste_car));
        free(&(node->liste_car));
    if(node->car_suiv){
        libere_liste_rec(&(node->car_suiv));
        free(&(node->car_suiv));
    }if(node->liste_morceaux){
        free(&(node->liste_morceaux));
    }
    if(!((node->liste_morceaux)&&node->car_suiv&&node->liste_car)){
        free(&(B));
    }
}
  
// Recherche si un artiste est present
void recherche_artiste(Biblio *B, char* artiste){ 
    // Indice lisant nom 
    int i=0;
    // Pointeur courant 
    Noeud *cour=B->A;
    // Pointeur sur la valeur precedant cour 
    Noeud *prec=cour;
    while (cour && artiste[i]!='\0'){
        prec=cour;
        if(cour->car==artiste[i]){// On a lu le bon caractere 
           cour=cour->car_suiv;
           i++;
        }else{ // On tente un caractere alternatif 
            cour=cour->liste_car;
        }
    }
    if(artiste[i]=='\0'){
        printf("%s n'est pas présent\n",artiste);
    }else{
        printf("la chaine % jusqu'au caratctère %d\n ",artiste ,i-1);
        if(artiste[i-1]==prec->car){ 
            printf("La suite de la chaine peut etre inserer à la suite de %c .\n,prec->car");
        }else{
            printf("La suite de la chaine peut être une alternative a la lettre %c.\n",prec ->car);
        }
    } 
}
// ON insere au début car cette méthode est beaucop plus rapide(d'ou l'utilisaton du poiinteur **, car on modifie l'adresse du pointeur *B).
// (complexité inferieur)
// insertion a la fin= parcours jusqu'a fin de liste a chaque insertion 
//simlement chainée.


//Retourne un pointeur vers le dernier noeud de l'arbre
//Retourne 1 si il existe artiste identique, 2 si peux etre inserer,0 cas aucun match?  
//l'adresse de la derniere valeur est stoker dans pt_resultat  
int recherche(Biblio *B, const char* artiste, CellMorceau *pt_resultat){ 
    // Indice lisant nom 
    int i=0;
    // pointeur qui contient la case selon la valeur res retourné
    int res=0;
    *pt_resultat=NULL;
    // Pointeur courant 
    Noeud *cour=B->A;
    // Pointeur sur la valeur precedant cour 
    Noeud *prec=cour;
    while (cour && artiste[i]!='\0'){
            prec=cour;
            if(cour->car==artiste[i]){// On a lu le bon caractere 
               cour=cour->car_suiv;
               i++;
            }else{ // On tente un caractere alternatif 
                cour=cour->liste_car;
            }
    }
    if(artiste[i]=='\0'){
        *pt_resultat= prec;
        res=2;
    } else if (artiste[i-1]==prec->car){ 
                printf("La suite de la chaine peut etre inserer à la suite de %c .\n", prec ->car);
                *pt_resultat= prec;
                res=1;
            } else {
                printf("La suite de la chaine peut être une alternative a la lettre %c.\n",prec ->car);
                res=0;
            }
    
    return res; 
}

/*
    if(artiste[i]=='\0'){
        printf("%s n'est pas présent\n",artiste);
    }else{
        printf("la chaine % jusqu'au caratctère %d\n ",artiste ,i-1);
        if(artiste[i-1]==prec->car){ 
            printf("La suite de la chaine peut etre inserer à la suite de %c .\n", prec ->car);
        }else {
            printf("La suite de la chaine peut être une alternative a la lettre %c.\n",prec ->car);
        }
    } 




*/


int insere(Biblio **B, int num,const char *titre,const char *artiste){ 
    //initialisons la nouvelle cellule
    CellMorceau *new =(CellMorceau*) malloc(sizeof(CellMorceau));
    new->num=num;
    new->titre=titre;
    new->artiste=artiste;
    //on sait si 
    Noeud *prev=NULL;
    int res=recherche(*B,titre,prev);
    switch (res){
    case 1:
        prev
        break;
    
    default:
        break;
    }
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

int affiche_list_morceau( CellMorceau *cell){
    //cas ou liste vide 
    if(!cell){
        return 0;
    }
    while (cell){
        afficheMorceau(cell);
        cell=cell->suiv;
    }
}

void affiche(Biblio *B){
    assert(B);
    // Indice lisant nom 
    int res=0;
    // Pointeur courant 
    Noeud *cour=B->A;
    // Pointeur sur la valeur precedant cour 
    Noeud *prec=cour, *prec_temp;
    
    while (cour->liste_car){
        prec=cour;
        while (cour){
            if(!cour->car_suiv && liste_morceau){
                if ((res=affiche_list_morceau(cour->liste_morceau)==0)){
                    return res;
s                }
            }
            prec_temp=cour;
            cour->car_suiv=cour->car_suiv->suiv;
        }
        cour=cour->car_suiv;
        else{ 
            cour=cour->liste_car;
        }
    }
    if(artiste[i]=='\0'){
        printf("%s n'est pas présent\n",artiste);
    }else{
        printf("la chaine % jusqu'au caratctère %d\n ",artiste ,i-1);
        if(artiste[i-1]==prec->car){ 
            printf("La suite de la chaine peut etre inserer à la suite de %c .\n", prec ->car);
        }else{
            printf("La suite de la chaine peut être une alternative a la lettre %c.\n",prec ->car);
        }
    } 
}

Biblio *uniques (Biblio *B){
    
}

CellMorceau *rechercheParNum(Biblio *B, int num){
    assert(B);
    CellMorceau *res=NULL, *list=B->L; 
	while(list){
       if (list->num==num) {
           res=list; break;
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
    CellMorceau *prev=NULL, *list=(*B)->A;
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

































