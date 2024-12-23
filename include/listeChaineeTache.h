#ifndef __LCT__
#define __LCT__

#include <stdbool.h>
#include <stddef.h>
#include <malloc.h>
#include <assert.h>
#include <stdio.h>
#include "tache.h"

typedef struct LCT_Noeud* LCT_ListeChainee;

typedef struct LCT_Noeud {
    TA_Tache element;
    LCT_ListeChainee listeSuivante;
} LCT_Noeud;

LCT_ListeChainee LCT_listeVide();
bool LCT_estVide(LCT_ListeChainee liste);
void LCT_ajouter(LCT_ListeChainee* liste, TA_Tache element);
TA_Tache LCT_obtenirElement(LCT_ListeChainee liste);
LCT_ListeChainee LCT_obtenirListeSuivante(LCT_ListeChainee liste);
void LCT_fixerElement(LCT_ListeChainee* liste, TA_Tache element);
void LCT_fixerListeSuivante(LCT_ListeChainee* liste, LCT_ListeChainee listeSuivante);
void LCT_supprimerTete(LCT_ListeChainee* liste);
void LCT_supprimer(LCT_ListeChainee* liste);
void LCT_inserer(LCT_ListeChainee* liste, TA_Tache element, int position);
int LCT_longueur(LCT_ListeChainee liste);
void LCT_afficher(LCT_ListeChainee liste);
TA_Tache LCT_iemeElement(LCT_ListeChainee liste, int position);
void LCT_supprimerElement(LCT_ListeChainee* liste, TA_Tache element);
void LCT_supprimerIemeElement(LCT_ListeChainee* liste, int position);
void LCT_fixerIemeElement(LCT_ListeChainee* liste, TA_Tache element, int position);
bool LCT_membre(LCT_ListeChainee liste, TA_Tache element);

#endif