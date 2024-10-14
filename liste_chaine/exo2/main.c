#include <stdio.h>
#include <stdlib.h>

typedef struct s_number number;
struct s_number {
    int value;
    number *next;
};

void ajouter_nombre(number **head, int valeur) {
    number *nouveau = (number *)malloc(sizeof(number));
    nouveau->value = valeur;
    nouveau->next = *head;
    *head = nouveau;
}

void afficher_nombres(number *head) {
    number *current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void effacer_ecran() {
    // Commande spécifique pour Mac
    system("clear");
}

void inserer_apres(number *prev, int valeur) {
    if (prev == NULL) {
        printf("Le maillon précédent ne peut pas être NULL\n");
        return;
    }

    number *nouveau = (number *)malloc(sizeof(number));
    nouveau->value = valeur;
    nouveau->next = prev->next;
    prev->next = nouveau;
}

int main() {
    number *head = NULL;
    int choix, valeur, position;

    do {
        printf("Menu : \n");
        printf("1. Ajouter un nombre\n");
        printf("2. Afficher les nombres\n");
        printf("3. Quitter\n");
        printf("4. Effacer l'écran\n");
        printf("5. Insérer un nombre\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                printf("Entrez un nombre : ");
                scanf("%d", &valeur);
                ajouter_nombre(&head, valeur);
                break;
            case 2:
                afficher_nombres(head);
                break;
            case 3:
                printf("Quitter le programme\n");
                break;
            case 4:
                effacer_ecran();
                break;
            case 5:
                printf("Entrez un nombre : ");
                scanf("%d", &valeur);
                printf("Entrez la position après laquelle insérer (0 pour début) : ");
                scanf("%d", &position);
                if (position == 0) {
                    ajouter_nombre(&head, valeur);
                } else {
                    number *current = head;
                    for (int i = 0; current != NULL && i < position - 1; i++) {
                        current = current->next;
                    }
                    if (current == NULL) {
                        printf("Position invalide\n");
                    } else {
                        inserer_apres(current, valeur);
                    }
                }
                break;
            default:
                printf("Choix invalide. Veuillez réessayer.\n");
        }
    } while (choix != 3);

    // Libérer la mémoire allouée
    number *current = head;
    number *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}