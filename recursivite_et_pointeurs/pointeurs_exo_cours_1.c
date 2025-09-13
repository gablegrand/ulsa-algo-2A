#include <stdio.h>

int ajouter_10_x_parametre(int x){
    return x + 10;
}

void ajouter_10_y_pointeurs(int *ptr){
    *ptr = *ptr + 10;
}

int main(){

    int x, y;
    int *pointeur_y;

    x = 5;
    y = 5;
    pointeur_y = &y;

    printf("Valeurs initiales -> x: %i, y: %i\n\n", x, y);

    // Avec parametres
    x = ajouter_10_x_parametre(x);
    printf("Nouvelle valeur de x : %i\n", x);

    //Avec pointeurs
    ajouter_10_y_pointeurs(pointeur_y);
    printf("Nouvelle valeur de y : %i\n", y);

    return 0;
}
