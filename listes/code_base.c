#include <stdio.h>
#include <stdlib.h>

typedef struct el *pel;

typedef struct el {
    int v;
    pel next;
} tel;

pel elemCreation(int val) {
    pel aux = (pel)malloc(sizeof(tel));
    aux->v = val;
    aux->next = NULL;
    return aux;
}

pel add(pel l, int val) {
    pel aux;
    if (l == NULL) {
        return elemCreation(val);
    } else {
        if (val < l->v) {
            aux = elemCreation(val);
            aux->next = l;
            return aux;
        } else {
            if (val == l->v) {
                printf("val is already in list\n");
                return l;
            } else {
                l->next = add(l->next, val);
                return l;
            }
        }
    }
}

pel delete(pel l, int val) {
    pel aux;
    if (l == NULL) {
        printf("empty list : val not in list\n");
        return l;
    } else {
        if (val < l->v) {
            printf("val not in list\n");
            return l;
        } else {
            if (l->v == val) {
                aux = l;
                l = l->next;
                printf("deleted element.\n");
                free(aux);
                return l;
            } else {
                l->next = delete(l->next, val);
                return l;
            }
        }
    }
}

// helper function to print the list
void printList(pel l) {
    printf("List: ");
    while (l != NULL) {
        printf("%d ", l->v);
        l = l->next;
    }
    printf("\n");
}

int main() {
    pel l = NULL;

    return 0;
}
