// Code de base pour la gestion de piles - fonction push, pop et affichePile (attention : seulement pour la gestion de piles d'entiers)
#include <stdio.h>
#include <stdlib.h>

// Définition de la structure d'un élément de pile
typedef struct el {
    int v;                // valeur stockée
    struct el *next;      // pointeur vers l’élément suivant
} tel;

typedef struct el* pel;   // pel = pointeur vers un élément

// Création d'un élément
pel elemCreation(int val) {
    pel tmp = (pel) malloc(sizeof(tel));
    tmp->v = val;
    tmp->next = NULL;
    return tmp;
}

// Ajout (push)
pel push(pel s, int val) {
    pel tmp = elemCreation(val);
    tmp->next = s;
    s = tmp;
    return s;
}

// Retrait (pop)
pel pop(pel s, int *pval) {
    if (s == NULL) {
        printf("Pile vide, impossible de retirer.\n");
        exit(1);
    }
    pel tmp = s;
    *pval = tmp->v;    // récupérer la valeur
    s = s->next;       // avancer la pile
    free(tmp);         // libérer mémoire
    return s;
}

// Afficher la pile
void afficherPile(pel s) {
    printf("Pile: ");
    while (s != NULL) {
        printf("%d ", s->v);
        s = s->next;
    }
    printf("\n");
}

int main() {
    pel pile = NULL;   // pile vide au départ

    // On empile 10, 20, 30
    pile = push(pile, 10);
    pile = push(pile, 20);
    pile = push(pile, 30);

    afficherPile(pile);   // Affiche: 30 20 10

    // On dépile un élément
    int val;
    pile = pop(pile, &val);
    printf("Élément retiré: %d\n", val);

    afficherPile(pile);   // Affiche: 20 10

    return 0;
}
