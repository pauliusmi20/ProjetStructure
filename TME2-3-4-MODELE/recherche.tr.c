// Recherche si un artiste est present
void recherche_artiste(Biblio *B, char*artiste){ 
    // Indice lisant nom 
    int i=0;
    // Pointeur courant 
    Noeud *cour=B->A;
    // Pointeur sur la valeur precedant cour 
    Noeud *prec=cour;
    while( (cour!=NULL) && (artiste[i]!=’\0’)){
        prec=cour;
        if(cour ->car== artiste[i]){// On a lu le bon caractere 
            cour=cour ->car_suiv;
        i++;
        }else{ // On tente un caractere alternatif 
            cour=cour->liste_car;
        }
    }
    if(artiste[i]==’\0’){
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