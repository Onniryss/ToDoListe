#ifndef __TODO__
#define __TODO__

#include <malloc.h>
#include "tache.h"
#include "listeChaineeTache.h"

#define TAILLE_DESCRIPTION 16

typedef LCT_ListeChainee TO_TodoListe;

TO_TodoListe TO_listeVide();
TA_Tache TO_obtenirTache(TO_TodoListe liste, int indice);
void TO_ajouterTache(TO_TodoListe* liste, char* description, long int tempsRestant);
void TO_supprimerTache(TO_TodoListe* liste, int indice);
void TO_validerTache(TO_TodoListe* liste, int indice);
void TO_invaliderTache(TO_TodoListe* liste, int indice);
void TO_changerEtat(TO_TodoListe* liste, int indice);
int TO_nombreTaches(TO_TodoListe liste);
void TO_supprimerListe(TO_TodoListe* liste);

#endif