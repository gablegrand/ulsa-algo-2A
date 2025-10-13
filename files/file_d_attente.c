#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ---- Structures ----

// Structure représentant une personne
typedef struct {
    char nom[20];
    int h, m, s;     // heure d’arrivée
    int demande;     // nature de la demande
} Personne;

// Liste chaînée (file)
typedef struct el *pel;

typedef struct el {
    Personne p;   // ici on remplace int v par Personne
    pel next;     // pointeur vers l'élément suivant
} tel;


// ---- Fonctions de manipulation de la file ----

// Création d’un élément (une personne)
pel elemCreation(Personne per) {
    pel tmp = (pel)malloc(sizeof(tel));
    if (!tmp) {
        printf("Erreur d’allocation mémoire\n");
        exit(EXIT_FAILURE);
    }
    tmp->p = per;
    tmp->next = NULL;
    return tmp;
}


// Ajout d’une personne à la file
pel add(pel file, Personne per) {
    pel aux = elemCreation(per);
    if (file == NULL) { // file vide
        return aux;
    }

    pel tmp = file;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = aux;
    return file;
}


// Suppression de la première personne
pel delete(pel file) {
    if (file == NULL) {
        printf("File vide\n");
        return NULL;
    }

    pel tmp = file;
    file = file->next;

    printf("Suppression : %s (arrivée %02d:%02d:%02d, demande %d)\n",
           tmp->p.nom, tmp->p.h, tmp->p.m, tmp->p.s, tmp->p.demande);

    free(tmp);
    return file;
}


// Affichage du contenu de la file
void afficher(pel file) {
    if (file == NULL) {
        printf("File vide\n");
        return;
    }

    printf("\n--- Contenu de la file ---\n");
    pel tmp = file;
    while (tmp != NULL) {
        printf(" - %s | arrivée %02d:%02d:%02d | demande %d\n",
               tmp->p.nom, tmp->p.h, tmp->p.m, tmp->p.s, tmp->p.demande);
        tmp = tmp->next;
    }
}


// Vérifie si une personne est dans la file
int estDansFile(pel file, const char *nom) {
    pel tmp = file;
    while (tmp != NULL) {
        if (strcmp(tmp->p.nom, nom) == 0)
            return 1;
        tmp = tmp->next;
    }
    return 0;
}


// ---- Programme principal ----
int main() {
    pel file = NULL;
    int N;

    printf("Combien de personnes voulez-vous ajouter ? ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        Personne per;
        printf("\nPersonne %d:\n", i + 1);
        printf("Nom : ");
        scanf("%s", per.nom);
        printf("Heure d'arrivée (h m s) : ");
        scanf("%d %d %d", &per.h, &per.m, &per.s);
        printf("Nature de la demande (entier) : ");
        scanf("%d", &per.demande);

        file = add(file, per);
    }

    afficher(file);

    // Recherche d’une personne
    char nomRecherche[20];
    printf("\nEntrer le nom à rechercher : ");
    scanf("%s", nomRecherche);
    if (estDansFile(file, nomRecherche))
        printf("%s est dans la file.\n", nomRecherche);
    else
        printf("%s n'est pas dans la file.\n", nomRecherche);

    // Suppression de la première personne
    printf("\n--- Suppression du premier élément ---\n");
    file = delete(file);
    afficher(file);

    return 0;
}
