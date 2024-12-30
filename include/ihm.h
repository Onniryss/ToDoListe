#ifndef __IHM__
#define __IHM__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "todo.h"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

typedef enum {MENU, TACHES, AJOUT, SUPPRESSION} IHM_Menu;

void IHM_gererEntreesMenu(TO_TodoListe* liste, bool* exit, IHM_Menu* scene);
void IHM_gererEntreesAjout(TO_TodoListe* liste, bool* exit, IHM_Menu* scene, char* description, int* nbJours);
void IHM_gererEntreesSuppression(TO_TodoListe* liste, bool* exit, IHM_Menu* scene);
void IHM_gererEntreesTaches(TO_TodoListe* liste, bool* exit, IHM_Menu* scene);
void IHM_gererEntrees(TO_TodoListe* liste, bool* exit, IHM_Menu* scene, char* description, int* nbJours);
void IHM_afficherMenu();
void IHM_afficherAjout(TO_TodoListe liste);
void IHM_afficherSuppression(TO_TodoListe liste);
void IHM_afficherTaches(TO_TodoListe liste);
void IHM_afficher(TO_TodoListe liste, IHM_Menu scene);

#endif