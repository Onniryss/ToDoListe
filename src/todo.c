#include <malloc.h>
#include "tache.h"
#include "listeChaineeTache.h"
#include <stdio.h>
#include <string.h>

#define TAILLE_DESCRIPTION 16

typedef LCT_ListeChainee TO_TodoListe;

TO_TodoListe TO_listeVide(){
    return LCT_listeVide();
}

TA_Tache TO_obtenirTache(TO_TodoListe liste, int indice){
    return LCT_iemeElement(liste, indice);
}

int TO_nombreTaches(TO_TodoListe liste){
    return LCT_longueur(liste);
}

void TO_ajouterTache(TO_TodoListe* liste, char* description, long int tempsRestant){
    char* descriptionTache = (char*)malloc(TAILLE_DESCRIPTION*sizeof(char));
    memcpy(descriptionTache, description, strlen(description));
    TA_Tache* tache = (TA_Tache*)malloc(sizeof(TA_Tache));
    TA_fixerEtat(tache, 0);
    TA_fixerDateDebut(tache, time(NULL));
    TA_fixerDateFin(tache, time(NULL)+tempsRestant*JOURS);
    TA_fixerDescription(tache, descriptionTache);
    TA_fixerNumero(tache, TO_nombreTaches(*liste));
    LCT_ajouter(liste, *tache);
}

void TO_supprimerTache(TO_TodoListe* liste, int indice){
    LCT_supprimerIemeElement(liste, indice);
}

void TO_validerTache(TO_TodoListe* liste, int indice){
    TA_Tache tache = LCT_iemeElement(*liste, indice);
    TA_fixerEtat(&tache, 1);
    LCT_fixerIemeElement(liste, tache, indice);
}

void TO_invaliderTache(TO_TodoListe* liste, int indice){
    TA_Tache tache = LCT_iemeElement(*liste, indice);
    TA_fixerEtat(&tache, 0);
    LCT_fixerIemeElement(liste, tache, indice);
}

void TO_supprimerListe(TO_TodoListe* liste){
    LCT_supprimer(liste);
}

void TO_changerEtat(TO_TodoListe* liste, int indice){
    if (TA_obtenirEtat(TO_obtenirTache(*liste, indice)) == false){
        TO_validerTache(liste, indice);
    } else {
        TO_invaliderTache(liste, indice);
    }
}