#include <stdio.h>
#include <stdlib.h>

typedef struct s_number number;
struct s_number {
    int value;
    number *next;
};

void addNumber(number **head, int value) {
    number *new = (number *)malloc(sizeof(number));
    new->value = value;
    new->next = *head;
    *head = new;
}

void showNumbers(number *head) {
    number *current = head;
    while (current != NULL) {
        printf("%d\n", current->value);
        current = current->next;
    }
}

void clearScreen() {
    // Specific command for Mac
    system("clear");
}

void insertAfter(number *prev, int value) {
    if (prev == NULL) {
        printf("The previous link cannot be NULL\n");
        return;
    }

    number *new = (number *)malloc(sizeof(number));
    new->value = value;
    new->next = prev->next;
    prev->next = new;
}

void insertTrie(number **head, int value){
    number *new = (number *)malloc(sizeof(number));
    new->value = value;
    new->next = NULL;

    if (*head == NULL || (*head)->value >= value){
        new->next = *head;
        *head = new;
    } else {
        number *current = *head;
        while (current->next != NULL && current->next->value < value){
            current = current->next;
        }
        insertAfter(current, value);
    }
}

int main() {
    number *head = NULL;
    int choice, value, position;

    do {
        printf("Menu : \n");
        printf("1. Ajouter un nombre\n");
        printf("2. Afficher les nombres\n");
        printf("3. Quitter\n");
        printf("4. Effacer l'écran\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choice);

        switch (choice){
            case 1:
                printf("Entrez un nombre : ");
                scanf("%d", &value);
                insertTrie(&head, value);
                break;
            case 2:
                showNumbers(head);
                break;
            case 3:
                printf("Quitter le programme\n");
                break;
            case 4:
                clearScreen();
                break;
            default:
            printf("Choix invalide. Veuillez réessayer.\n");
        }
    }while (choice != 3);

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