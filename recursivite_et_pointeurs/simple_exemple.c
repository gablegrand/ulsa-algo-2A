// Exemple 1: première fonction récursive
#include <stdio.h>

void afficher(int n) {
    if (n > 10) {
        return; // condition d'arrêt
    }
    printf("%d ", n);
    afficher(n + 1); // appel récursif avec n+1
}

int main() {
    afficher(1); // lancer à partir de 1
    return 0;
}
