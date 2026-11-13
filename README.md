# Carnet de contacts en C

Petit carnet d'adresses en ligne de commande : ajout, affichage et recherche de contacts
(nom, nationalité, téléphone), stockés en mémoire (150 contacts maximum).

## Compiler et lancer

```bash
make
./contacts
```

Ou : `gcc -Wall -Wextra -o contacts main.c fonction.c`

## Structure

| Fichier | Rôle |
|---|---|
| `entete.h` | Structure `Contact`, constantes et prototypes |
| `fonction.c` | Ajout, affichage et recherche |
| `main.c` | Menu principal |

## Ce que j'ai travaillé

- Programmation modulaire (`.h` / `.c`) et variables globales partagées avec `extern`
- Saisie sécurisée avec `fgets` (pas de dépassement de tampon)
- Menu robuste : une saisie non numérique ne fait plus boucler le programme

## Pistes d'amélioration

- Sauvegarder les contacts dans un fichier pour les conserver entre deux lancements
- Supprimer et modifier un contact
- Recherche partielle et insensible à la casse
- Allocation dynamique à la place du tableau de taille fixe
