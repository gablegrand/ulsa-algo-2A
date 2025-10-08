// Exercice de TD sur les palindromes

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Définition de la structure d'un élément de pile
typedef struct el {
    char v;               // ici on stocke un caractère
    struct el *next;
} tel;

typedef struct el* pel;

// Création d'un élément
pel elemCreation(char val) {
    pel tmp = (pel) malloc(sizeof(tel));
    tmp->v = val; // stockage de la valeure envoyée
    tmp->next = NULL; // définition de l'adresse du suivant à NULL (car suivant n'existe pas encore)
    return tmp;
}

// Ajout (push)
pel push(pel s, char val) {
    pel tmp = elemCreation(val);
    tmp->next = s; // on met dans next de tmp le pointeur qui point vers le sommet de la pile actuellement
    s = tmp; // on met à jour le sommet de la pile avec le nouvel élément qu'on a ajouté
    return s;
}

// Retrait (pop)
pel pop(pel s, char *pval) {
    if (s == NULL) {
        printf("Pile vide, impossible de retirer.\n");
        exit(1);
    }
    pel tmp = s; // on met dans le pointeur tmp le sommet de la pile
    *pval = tmp->v; // on modifie la valeur de la variable à l'adresse donnée avec la valeur de ce que l'on dépile
    s = s->next; // on modifie le sommet de la pile avec l'élément suivant
    free(tmp); // on libère la mémoire
    return s;
}

// Programme principal : vérification de palindrome
int main() {
    pel pile = NULL; // on définit une variable pile qui est un pointeur vers le sommet de la pile (NULL car vide au départ)
    char mot[100];
    char c;
    int i;

    printf("Entrez un mot : ");
    scanf("%s", mot);

    // Empiler tous les caractères du mot
    for (i = 0; mot[i] != '\0'; i++) {
        pile = push(pile, mot[i]);
    }

    // Dépiler pour construire le mot inversé
    char inverse[100];
    i = 0;
    while (pile != NULL) { // tant que la pile n'est pas vide (par rappel le premier élément à pour next NULL)
        pile = pop(pile, &c);
        inverse[i++] = c;
    }
    inverse[i] = '\0'; // terminaison de chaîne

    printf("Mot original : %s\n", mot);
    printf("Mot inverse  : %s\n", inverse);

    // Comparaison a l'aide de la fonction strcmp (aussi possible manuellement avec une comparaison caractere pas caractere)
    if (strcmp(mot, inverse) == 0) {
        printf("=> '%s' est un palindrome.\n", mot);
    } else {
        printf("=> '%s' n'est pas un palindrome.\n", mot);
    }

    return 0;
}
