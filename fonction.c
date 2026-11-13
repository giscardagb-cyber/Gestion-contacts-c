#include <stdio.h>
#include <string.h>
#include "entete.h"

Contact carnet[MAX_CONTACTS];
int nb_contacts = 0;

/* Lit une ligne au clavier et supprime le retour a la ligne. */
static void lire_ligne(const char *invite, char *dest, size_t taille) {
    printf("%s", invite);
    if (fgets(dest, (int)taille, stdin) == NULL) {
        dest[0] = '\0';
        return;
    }
    dest[strcspn(dest, "\r\n")] = '\0';
}

void ajouter_contact(void) {
    if (nb_contacts >= MAX_CONTACTS) {
        printf("Le carnet est plein.\n");
        return;
    }

    Contact *c = &carnet[nb_contacts];
    lire_ligne("Nom du contact : ", c->nom, sizeof(c->nom));
    lire_ligne("Nationalite : ", c->nationalite, sizeof(c->nationalite));
    lire_ligne("Numero de telephone : ", c->telephone, sizeof(c->telephone));
    nb_contacts++;
    printf("Contact ajoute.\n");
}

void afficher_contact(void) {
    if (nb_contacts == 0) {
        printf("Le carnet est vide.\n");
        return;
    }
    for (int i = 0; i < nb_contacts; i++) {
        printf("\nContact %d\nNom  : %s\nPays : %s\nTel  : %s\n",
               i + 1, carnet[i].nom, carnet[i].nationalite, carnet[i].telephone);
    }
}

void rechercher_contact(void) {
    char recherche[256];
    int trouve = 0;

    lire_ligne("Nom a rechercher : ", recherche, sizeof(recherche));

    for (int i = 0; i < nb_contacts; i++) {
        if (strcmp(recherche, carnet[i].nom) == 0) {
            printf("\nContact trouve !\nNom  : %s\nPays : %s\nTel  : %s\n",
                   carnet[i].nom, carnet[i].nationalite, carnet[i].telephone);
            trouve = 1;
        }
    }

    if (!trouve) {
        printf("Aucun contact trouve avec ce nom.\n");
    }
}
