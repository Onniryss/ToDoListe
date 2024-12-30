#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "todo.h"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

typedef enum {MENU, TACHES, AJOUT, SUPPRESSION} IHM_Menu;

void IHM_gererEntreesMenu(TO_TodoListe* liste, bool* exit, IHM_Menu* scene){
    char key;
    scanf("%c", &key);
    switch (key){
        case '1': // afficher les taches
            *scene = TACHES;
            break;
        case '2': // ajouter une tache
            *scene = AJOUT;
            break;
        case '3': // supprimer une tache
            *scene = SUPPRESSION;
            break;
        case '4': // quitter
            clear();
            gotoxy(1, 1);
            *exit = true;
            break;
        default:
            break;
    }
}

void IHM_gererEntreesAjout(TO_TodoListe* liste, bool* exit, IHM_Menu* scene, char* description, int* nbJours){
    char key;
    scanf("%c", &key);
    switch (key){
        case '1':
            gotoxy(16, 6);
            scanf("%s", description);
            break;
        case '2':
            gotoxy(56, 15);
            scanf("%d", nbJours);
            break;
        case '3':
            TO_ajouterTache(liste, description, *nbJours);
            *scene = MENU;
            break;
        case '4': // annuler
            *scene = MENU;
            break;
        default:
            break;
    }
}

void IHM_gererEntreesSuppression(TO_TodoListe* liste, bool* exit, IHM_Menu* scene){
    char key;
    scanf("%c", &key);
    switch (key){
        case '1': // afficher les taches
            *scene = TACHES;
            break;
        case '2': // ajouter une tache
            *scene = AJOUT;
            break;
        case '3': // supprimer une tache
            *scene = SUPPRESSION;
            break;
        case '4': // quitter
            *exit = true;
            break;
        default:
            break;
    }
}

void IHM_gererEntreesTaches(TO_TodoListe* liste, bool* exit, IHM_Menu* scene){
    char key;
    scanf("%c", &key);
    if (key > '0' && key < '9'){
        int key_num = key-'0';
        if (TO_nombreTaches(*liste) >= key_num){
            TO_changerEtat(liste, TO_nombreTaches(*liste)-key_num);
        }
    } else {
        switch (key) {
            case 'a' : 
                *scene = MENU;
                break;
            case 'b' : 
                clear();
                *exit = true;
                break;
            default:
                break;
        }
    }
}

void IHM_gererEntrees(TO_TodoListe* liste, bool* exit, IHM_Menu* scene, char* description, int* nbJours){
    switch (*scene){
        case MENU:
            IHM_gererEntreesMenu(liste, exit, scene);
            break;
        case TACHES:
            IHM_gererEntreesTaches(liste, exit, scene);
            break;
        case AJOUT:
            IHM_gererEntreesAjout(liste, exit, scene, description, nbJours);
            break;
        case SUPPRESSION:
            IHM_gererEntreesSuppression(liste, exit, scene);
            break;
        default:
            break;
    }
}

void IHM_afficherMenu(){
    clear();
    gotoxy(41, 4);
    printf("MENU");
    gotoxy(33, 7);
    printf("1) AFFICHER LES TACHES");
    gotoxy(33, 9);
    printf("2) AJOUTER UNE TACHE");
    gotoxy(33, 11);
    printf("3) SUPPRIMER UNE TACHE");
    gotoxy(33, 13);
    printf("4) QUITTER");
    gotoxy(1, 24);

}

void IHM_afficherAjout(TO_TodoListe liste){
    clear();
    gotoxy(9, 3);
    printf("1) DESCRIPTION (16 CHARACTER MAX)");
    gotoxy(9, 16);
    printf("2) NOMBRE DE JOURS RESTANTS");
    gotoxy(5, 22);
    printf("3) VALIDER");
    gotoxy(65, 22);
    printf("4) ANNULER");
    gotoxy(9, 5);
    printf("o-------------------------------------------------------o");
    gotoxy(9, 6);
    printf("|                                                       |");
    gotoxy(9, 7);
    printf("|                                                       |");
    gotoxy(9, 8);
    printf("|                                                       |");
    gotoxy(9, 9);
    printf("o-------------------------------------------------------o");
    gotoxy(49, 14);
    printf("o-----------------------o");
    gotoxy(49, 15);
    printf("|                       |");
    gotoxy(49, 16);
    printf("|                       |");
    gotoxy(49, 17);
    printf("|                       |");
    gotoxy(49, 18);
    printf("o-----------------------o");
    gotoxy(1, 24);
}

void IHM_afficherSuppression(TO_TodoListe liste){
    clear();
    gotoxy(9, 3);
    printf("1) DESCRIPTION");
    gotoxy(9, 16);
    printf("2) NOMBRE DE JOURS RESTANTS");
    gotoxy(65, 22);
    printf("3) VALIDER");
    gotoxy(9, 5);
    printf("o-------------------------------------------------------o");
    gotoxy(9, 6);
    printf("|                                                       |");
    gotoxy(9, 7);
    printf("|                                                       |");
    gotoxy(9, 8);
    printf("|                                                       |");
    gotoxy(9, 9);
    printf("o-------------------------------------------------------o");
    gotoxy(49, 14);
    printf("o-----------------------o");
    gotoxy(49, 15);
    printf("|                       |");
    gotoxy(49, 16);
    printf("|                       |");
    gotoxy(49, 17);
    printf("|                       |");
    gotoxy(49, 18);
    printf("o-----------------------o");
    gotoxy(1, 24);
}

void IHM_afficherTaches(TO_TodoListe liste){
    clear();
    gotoxy(1, 1);
    printf("To-do liste de Jules");
    gotoxy(5, 23);
    printf("A) RETOUR AU MENU");
    gotoxy(65, 23);
    printf("B) QUITTER");
    gotoxy(9, 3);
    printf("Tâches----------------------------------------------------------o");
    gotoxy(10, 20);
    printf("o--------------------------------------------------------------o");
    for (int i = 0; i < TO_nombreTaches(liste); i++){
        gotoxy(16, 5+i);
        printf("%d) ", i+1);
        TA_afficherTache(TO_obtenirTache(liste, TO_nombreTaches(liste)-i-1));
    }
    for (int i = 0; i < 16; i++){
        gotoxy(10, 4+i);
        printf("|");
        gotoxy(73, 4+i);
        printf("|");
    }
    gotoxy(1, 24);
}

void IHM_afficher(TO_TodoListe liste, IHM_Menu scene){
    switch (scene){
        case MENU:
            IHM_afficherMenu();
            break;
        case TACHES:
            IHM_afficherTaches(liste);
            break;
        case AJOUT:
            IHM_afficherAjout(liste);
            break;
        case SUPPRESSION:
            IHM_afficherSuppression(liste);
            break;
        default:
            break;
    }
}