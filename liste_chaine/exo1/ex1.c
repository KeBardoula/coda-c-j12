#include <stdio.h>
#include <stdlib.h>

typedef struct s_number number;
struct s_number{
    int value;
    number *next;
};

void ajouter_nombre(number **head, int valeur){
    number *new_number = (number *)malloc(sizeof(number));
    new_number->value = valeur;
    new_number->next = *head;
    *head = new_number;
}

void afficher_nombres(number *head){
    number *current = head;
    while (current != NULL)
    {
        /* code */
        printf("%d\n", current->value);
        current = current->next;
    }
}

void effacer_ecran(){
    // Commande spécifique pour Mac
    system("clear");
}

int main() {
    number *head = NULL;
    int choix, valeur;

    do {
        printf("Menu :\n");
        printf("1. Ajouter un nombre\n");
        printf("2. Afficher les nombres\n");
        printf("3. Effacer l'écran\n");
        printf("4. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Entrez un nombre : ");
            scanf("%d", &valeur);
            ajouter_nombre(&head, valeur);
            break;
        case 2:
            afficher_nombres(head);
            break;
        case 3:
            effacer_ecran();
            break;
        default:
            break;
        }
    }while (choix != 3);

    // Libérer la mémoire allouée
    number *current = head;
    number *next;
    while(current != NULL){
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}