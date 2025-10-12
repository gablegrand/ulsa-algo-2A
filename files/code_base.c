#include <stdio.h>
#include <stdlib.h>

typedef struct el *pel; // pel: pointeur vers une structure el

typedef struct el {
    int v;
    pel next; // permet l enchainement
} tel; // tel: type correspondant a struct el


// Files: creation d un element
pel elemCreation(int val) {
    pel tmp;
    tmp = (pel)malloc(sizeof(tel));
    tmp->v = val;
    tmp->next = NULL;
    return tmp;
}


// Files: ajout d un element
pel add(pel file, int val) {
    pel aux = elemCreation(val);
    pel tmp = file;

    if (file == NULL) { // file vide
        return aux;
    } else { // file non vide
        while (tmp->next != NULL) { // pour atteindre le dernier element de la file
            tmp = tmp->next;
        }
        tmp->next = aux; // ajouter le nouvel element apres le dernier
        return file;
    }
}


// Files: suppression d un element
pel delete(pel file) {
    pel tmp = file;

    if (file == NULL) { // si la file est vide
        printf("File vide\n");
    } else { // file non vide
        file = file->next;
        printf("on supprime %i\n", tmp->v);
        free(tmp); // liberer la memoire
    }

    return file;
}


// Files: affichage du contenu
void afficher(pel file) {
    if (file == NULL) {
        printf("File vide\n");
        return;
    }

    printf("Contenu de la file: ");
    pel tmp = file;
    while (tmp != NULL) {
        printf("%i ", tmp->v);
        tmp = tmp->next;
    }
    printf("\n");
}


// Programme principal
int main() {
    pel file = NULL; // file vide au debut

    // Ajout de 10, 20 et 30
    file = add(file, 10);
    file = add(file, 20);
    file = add(file, 30);

    printf("Elements ajoutes: 10, 20, 30\n");
    afficher(file);

    // Suppression des elements un par un
    file = delete(file);
    afficher(file);

    file = delete(file);
    afficher(file);

    file = delete(file);
    afficher(file);

    // Tentative de suppression sur une file vide
    file = delete(file);

    return 0;
}
