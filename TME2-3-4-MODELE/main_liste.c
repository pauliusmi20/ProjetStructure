#include <stdlib.h>
#include <stdio.h>

/*************************************************************************************

 *           A MODIFIER LE FICHIER BIBLIO.H POUR UTILISER UN autre schema de données 

/*************************************************************************************/
#include "biblio.h" // à modifier "biblio.h" 
#include "biblio_liste.h"

void menu(){
	printf("Menu:\n");
	printf("0-Sortie\n");
	printf("1-Affichage\n");
	printf("2-Test Unique\n");
	printf("3-Recherche morceau par numero\n");
	printf("4-Recherche morceau par titre\n");
	printf("5-Recherche morceau par artiste\n");
	printf("6-Inserer nouveau morceau\n");
	printf("7-Effacer morceau par numero\n");
	printf("Votre choix : \n");
}

int main(int argc, const char *argv[]){
	if (argc != 3) {
		fprintf(stderr,"Erreur, usage: %s <NomFichierBiblio.txt> <NbLigneALire> \n\n", argv[0]);
		return (EXIT_FAILURE);
	}
	//les parametre de la fonction main: nom fic et nlignes 
	const char *nomfic = argv[1];
	int nlignes = atoi(argv[2]);
	
	//...celles qui vont stocker les paramètres de l'utilisateur
	char titre[259]={};
	char titre2[259]={};

	printf("Lecture :\n " );
	Biblio *biblio = charge_n_entrees(nomfic, nlignes);
	int ch;
	do {
		menu();
		int lus = scanf("%d", &ch);
		if (lus == 0)
			ch = 0;
		
		switch(ch) {
			case 1 :
				printf("Affichage\n");
				affiche(biblio);
				break;
			case 2:
				{
					Biblio *Bunique = uniques(biblio);
					affiche(Bunique);
					libere_biblio(Bunique);
					break;
				}
			case 3 :
				{
					printf("Saisir le numero du morceau :\n");
					scanf(" %248[^\n]", titre);
					printf("%d\n", atoi(titre) );
					CellMorceau * r = rechercheParNum(biblio, atoi(titre));
					if (r == NULL) printf("Aucun morceau de numero : %s!!!\n", titre);
					else afficheMorceau(r);
					break;
				}
			case 4 :
				{
					printf("Saisir le titre du morceau :\n");
					scanf(" %248[^\n]", titre);
					CellMorceau * r = rechercheParTitre(biblio, titre);
					if (r == NULL) printf("Aucun morceau de titre : %s!!!\n", titre);
					else afficheMorceau(r);
					break;
				}
			case 5 :
				{
					printf("Saisir l'artiste :\n");
					scanf(" %248[^\n]", titre);
					Biblio *r=extraireMorceauxDe(biblio, titre);
					if (r == NULL) printf("Aucun morceau composé par : %s!!!\n", titre);
					else affiche(r);
					break;
				}
			case 6 : // inser nouvelle case
				{
					printf("Saisir le titre \n");
					scanf(" %248[^\n]", titre);
					printf("Saisir l'artiste \n");
					scanf(" %248[^\n]", titre2);
					insereSansNum(&biblio,titre,titre2);
					printf("Voici le nouveau morceau:\n");
					afficheMorceau(biblio->L);
					break;
				}
			case 7 : //surpresssion abec ID
				{
					printf("Saisir le numero :\n");
					scanf(" %248[^\n]", titre);
					int r = supprimeMorceau(&biblio, atoi(titre));
					if (r == 0) printf("Echec : aucun morceau de nr %s!!!\n", titre);
					else ("le morceau avec le numero %s supprimé.\n", titre);
					break;
				}			
			default :
				ch = 0;
				break;
		
		}
		
	} while (ch != 0);

	libere_biblio(biblio);
	printf("Au revoir\n");
	
	return (EXIT_SUCCESS);
}
