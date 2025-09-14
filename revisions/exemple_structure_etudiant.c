#include <stdio.h>

// Definition d'une structure pour un etudiant
typedef struct etudiant {
    char nom[50];
    char prenom[50];
    int age;
    char promotion[10];
} t_etudiant;


t_etudiant saisie() {
    t_etudiant e;

    // fgets remplace gets qui est une fonctio depreciee
    // fgets necessite plus d'arguments et garde le \n cree lorsque l'utilisateur clique sur entree
    // il est possible de supprimer cet \n mais ce n'est pas le cas dans cet exemple

    printf("Entrez le nom de l'etudiant :\n");
    fgets(e.nom, sizeof(e.nom), stdin);  // Lecture du nom

    printf("Entrez le prenom :\n");
    fgets(e.prenom, sizeof(e.prenom), stdin);  // Lecture du prenom

    printf("Age de l'etudiant ?\n");
    scanf("%i", &e.age);  // Lecture de l'age
    getchar(); // Probleme du \n

    printf("Promotion ?\n");
    fgets(e.promotion,sizeof(e.promotion), stdin);  // Lecture de la promotion

    return e;
}

// Fonction pour afficher les informations d'un etudiant
void afficheEtudiant(t_etudiant e) {
    printf("Nom de l'etudiant : %s\n", e.nom);
    printf("Prenom : %s\n", e.prenom);
    printf("Age : %i\n", e.age);
    printf("Promotion : %s\n", e.promotion);
}

int main() {
    t_etudiant etud1;

    etud1 = saisie(); // Saisie des donnees
    afficheEtudiant(etud1); // Affichage des donnees

    return 0;
}
