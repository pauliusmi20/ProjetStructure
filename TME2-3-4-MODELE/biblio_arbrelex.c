#include "biblio_arbrelex.h"
#include "biblio_liste.h"

Biblio *nouvelle_biblio(void) 
{
   
}

void libere_biblio(Biblio *B)
{
    
}


void insere(Biblio *B, int num, char *titre, char *artiste)
{
    
}

void afficheMorceau(CellMorceau *cell)
{
	printf("|A| %8d | %-32.32s | %-32.32s |A|\n", cell->num, cell->titre, cell->artiste);
}


void affiche(Biblio *B)
{
    
}


Biblio *uniques (Biblio *B)
{
   
}


CellMorceau * rechercheParNum(Biblio *B, int num)
{
	
}


CellMorceau *rechercheParTitre(Biblio *B, char * titre)
{
	
}


Biblio *extraireMorceauxDe(Biblio *B, char * artiste)
{
	
}


void insereSansNum(Biblio *B, char *titre, char *artiste)
{
	
}


int supprimeMorceau(Biblio *B, int num)
{

}































