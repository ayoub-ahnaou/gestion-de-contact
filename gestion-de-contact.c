#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

typedef struct {
    char nom[25], email[50];
    char phone[10]; // +212-654-504500
} Contact;

Contact contact[99];
int nbreContact = 0;

// fonction qui retourne la position d'element si ella trouver, et -1 sinon.
int rechercher(){
    char nom[25];
    
    printf(COLOR_YELLOW "donner le nom de contact: " COLOR_RESET);
    scanf(" %[^\n]s", nom);
    for(int i=0; i<nbreContact; i++){
        if(strcmp(nom, contact[i].nom) == 0){
            return i;
        }
    }
    return -1;
}

void ajouterContact(){
    system("cls");
    printf("remplir les informations suivants\n");
    printf("votre nom complete: "); scanf(" %[^\n]s", contact[nbreContact].nom);
    printf("votre adresse email: "); scanf(" %[^\n]s", contact[nbreContact].email);
    printf("votre numero de telephone (+xxx-xxx-xxxxxx): "); scanf(" %[^\n]s", contact[nbreContact].phone);

    printf(COLOR_YELLOW "un contact a ete ajoute avec success..\n" COLOR_RESET);
    nbreContact = nbreContact + 1;
}

void modifierContact(){
    system("cls");
    int pos = rechercher();
    if(pos == -1){
        printf(COLOR_RED "contact ne pas trouvee..\n" COLOR_RESET);
        return;
    }
    else{
        printf("entrer le nouveau email: "); scanf(" %[^\n]s", contact[pos].email);
        printf("entrer le nouveau telephone: "); scanf(" %[^\n]s", contact[pos].phone);

        printf("contact modifie avec success..\n");
    }

}

void supprimerContact(){
    system("cls");
    int pos = rechercher();

    if(pos == -1){
        printf(COLOR_RED "contact ne pas trouvee..\n" COLOR_RESET);
        return;
    }
    else{
        for(int i=pos; i<nbreContact; i++){
            contact[i] = contact[i+1];
        }
        nbreContact = nbreContact - 1;
        printf("contact supprimée avec success..\n");
    }    
}

void rechercherContact(){
    system("cls");
    if(nbreContact == 0){
        printf(COLOR_RED "aucun contact availaible actuellement, essayez d'ajoutez un\n" COLOR_RESET);
        return;
    }
    int pos = rechercher();
    if(pos != -1){
        printf("information de contact.\n");
        printf("%s | %s | %s \n", contact[pos].nom, contact[pos].email, contact[pos].phone);
    }else{
        printf(COLOR_RED "contact ne pas trouvee..\n" COLOR_RESET);
    }
}

void afficherContact(){
    system("cls");
    printf(COLOR_RED "------------------------------------------------------------------\n" COLOR_RESET);
    printf("nombre total de contacts %d\n", nbreContact);
    printf(COLOR_RED "------------------------------------------------------------------\n" COLOR_RESET);

    for(int i=0; i<nbreContact; i++){
        printf("%d- %s, %s, %s\n", i+1, contact[i].nom, contact[i].email, contact[i].phone);
    }

}

void menu(){
    int choix;
    do{
        printf(COLOR_GREEN "------------------------------------------------------------------\n" COLOR_RESET);
        printf(COLOR_GREEN "-                       gestion de contact                       -\n" COLOR_RESET);
        printf(COLOR_GREEN "------------------------------------------------------------------\n" COLOR_RESET);

        printf(COLOR_MAGENTA "1- ajouter un contact\n");
        printf("2- modifier un contact\n");
        printf("3- supprimer un contact\n");
        printf("4- rechercher un contact\n");
        printf("5- afficher un contact\n");
        printf("0- quittez\n" COLOR_RESET);

        printf(COLOR_GREEN "------------------------------------------------------------------\n" COLOR_RESET);
        printf(COLOR_YELLOW "entrez votre choix: " COLOR_RESET); scanf("%d", &choix);

        switch(choix){
            case 1: ajouterContact(); break;
            case 2: modifierContact(); break;
            case 3: supprimerContact(); break;
            case 4: rechercherContact(); break;
            case 5: afficherContact(); break;
            case 0: exit(0); break;
            default: printf("choix non valid..\n"); break;
        }

    }
    while(choix != 6);

    
}

int main(){
    menu();

    return 0;
}