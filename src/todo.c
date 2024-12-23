#include <malloc.h>
#include "tache.h"
#include "listeChaineeTache.h"
#include <stdio.h>

#define JOURS 24*60*60

typedef LCT_ListeChainee TO_TodoListe;

TO_TodoListe TO_listeVide(){
    return LCT_listeVide();
}

TA_Tache TO_obtenirTache(TO_TodoListe liste, int indice){
    return LCT_iemeElement(liste, indice);
}

void TO_ajouterTache(TO_TodoListe* liste, char* description, long int tempsRestant){
    TA_Tache* tache = (TA_Tache*)malloc(sizeof(TA_Tache));
    TA_fixerEtat(tache, 0);
    TA_fixerDateDebut(tache, time(NULL));
    TA_fixerDateFin(tache, time(NULL)+tempsRestant*JOURS);
    TA_fixerDescription(tache, description);
    TA_fixerNumero(tache, 0);
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

int TO_nombreTaches(TO_TodoListe liste){
    return LCT_longueur(liste);
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