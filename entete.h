#ifndef ENTETE_H
#define ENTETE_H

#define MAX_CONTACTS 150

typedef struct {
    char nom[256];
    char telephone[20];
    char nationalite[256];
} Contact;

/* Declaration seulement : la definition est dans fonction.c
   (definir une variable dans un .h provoque une erreur "multiple definition"). */
extern Contact carnet[MAX_CONTACTS];
extern int nb_contacts;

void ajouter_contact(void);
void afficher_contact(void);
void rechercher_contact(void);

#endif
