#include "biblio.h"
#include "biblio_arbrelex.h"

Biblio *charge_n_entrees(const char *nom_fichier, int n){
    FILE *fic=NULL;
    //ouverture fichier
    if (!(fic=fopen(nom_fichier, "r"))){
        fprintf(stderr, "erreur lors de l'ouverture du fichier.\n"); // on test si une erreur à lieu,si 
        return NULL;                                            // oui on l'écrit dans STDERR
    }
    //nouvelle instance de biblio
    Biblio *newBiblio=nouvelle_biblio();// 
    //iterateur
    int i=0;
    while (i<n && !end_of_file(fic) ){
    //les buffers utilisées 
        char *buf_artiste=NULL; 
        char* buf_titre=NULL; 
        int buf_num=0; 
        int taille;
        //On parse une ligne entière
        int parse_success= (parse_int(fic,&buf_num )&&
            parse_char     (fic,'\t')&&
            parse_string   (fic, &buf_titre, &taille, '\t' ) &&
            parse_char     (fic,'\t')&&
            parse_string   (fic, &buf_artiste, &taille, '\n' ) &&    
            parse_char     (fic,'\n'));
        if (!parse_success){
            fprintf( stderr, "Echec lors du parse de data.\n "); 
            break;      // on retourne pour ne plus enregister les buff..
        }else{
            //printf("%d\n%s\n%s\n---------\n",buf_num,(char*) buf_titre,(char*) buf_artiste);
            insere(&newBiblio,buf_num,buf_titre,buf_artiste); 
        } 
        i++;
    }
    fclose(fic);
    return newBiblio;
}
