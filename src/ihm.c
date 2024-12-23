#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "todo.h"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

void IHM_gererEntrees(TO_TodoListe* liste, bool* exit){
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
                break;
            case 'b' : 
                break;
            case 'c' : 
                clear();
                *exit = true;
                break;
            default:
                break;
        }
    }
}

void IHM_afficherTerminal(TO_TodoListe liste){
    clear();
    gotoxy(1, 1);
    printf("To-do liste de Jules");
    gotoxy(5, 23);
    printf("A) SUPPRIMER TACHE");
    gotoxy(35, 23);
    printf("B) AJOUTER TACHE");
    gotoxy(65, 23);
    printf("C) QUITTER");
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