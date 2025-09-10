// Exercice 1: calcul de la factorielle d'un nombre N (avec N < 12 sinon erreur de dépassement de mémoire d'un entier)
#include <stdio.h>

// Fonction pour calculer la factorielle avec une boucle
int factorielleAvecBoucle(int n) {
    int resultat = 1;
    for (int i = 1; i <= n; i++) {
        resultat = resultat * i;
    }
    return resultat;
}

// Fonction pour calculer la factorielle sans boucle (récursion)
int factorielleSansBoucle(int n) {
    if (n <= 1) {
        return 1;
    } else {
        return n * factorielleSansBoucle(n - 1);
    }
}

int main() {
    int N;

    // Demande à l'utilisateur de saisir un entier positif
    printf("Entrez un entier positif N : ");
    scanf("%d", &N);

    if (N < 0) {
        printf("Erreur : l'entier doit être positif.\n");
        return 1;
    }

    // Calcul avec boucle
    int resultatBoucle = factorielleAvecBoucle(N);
    printf("Factorielle (avec boucle) : %d\n", resultatBoucle);

    // Calcul sans boucle
    int resultatSansBoucle = factorielleSansBoucle(N);
    printf("Factorielle (sans boucle) : %d\n", resultatSansBoucle);

    return 0;
}
