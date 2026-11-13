#include <stdio.h>
#include <stdlib.h>
#include "entete.h"

int main(void) {
    char ligne[32];
    int choix = -1;

    do {
        printf("\n=== CARNET DE CONTACTS ===\n");
        printf("1- Ajouter un contact\n");
        printf("2- Afficher les contacts\n");
        printf("3- Rechercher un contact\n");
        printf("0- Quitter\n");
        printf("Votre choix : ");

        /* fgets + strtol : une saisie non numerique ne bloque plus le programme. */
        if (fgets(ligne, sizeof(ligne), stdin) == NULL) break;
        char *fin;
        choix = (int)strtol(ligne, &fin, 10);
        if (fin == ligne) choix = -1;

        switch (choix) {
            case 1: ajouter_contact();    break;
            case 2: afficher_contact();   break;
            case 3: rechercher_contact(); break;
            case 0: printf("Au revoir !\n"); break;
            default: printf("Choix invalide.\n"); break;
        }
    } while (choix != 0);

    return 0;
}
