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

LCT_ListeChainee LCT_listeVide(){
  return NULL;
}

bool LCT_estVide(LCT_ListeChainee liste){
  return liste == NULL;
}

TA_Tache LCT_obtenirElement(LCT_ListeChainee liste){
  assert(!LCT_estVide(liste));
  return liste->element;
}

LCT_ListeChainee LCT_obtenirListeSuivante(LCT_ListeChainee liste){
  assert(!LCT_estVide(liste));
  return liste->listeSuivante;
}

void LCT_fixerElement(LCT_ListeChainee* liste, TA_Tache element){
  assert(!LCT_estVide(*liste));
  (*liste)->element = element;
}

void LCT_fixerListeSuivante(LCT_ListeChainee* liste, LCT_ListeChainee listeSuivante){
  assert(!LCT_estVide(*liste));
  (*liste)->listeSuivante = listeSuivante;
}


void LCT_afficher(LCT_ListeChainee liste){
  if (!LCT_estVide(liste)){
    TA_Tache element = LCT_obtenirElement(liste);
    TA_afficherTache(element);
    LCT_afficher(LCT_obtenirListeSuivante(liste));
  }
}

void LCT_supprimerTete(LCT_ListeChainee* liste){
  assert(!LCT_estVide(*liste));
  LCT_ListeChainee temp = *liste;
  *liste = LCT_obtenirListeSuivante(*liste);
  free(temp);
}

void LCT_supprimer(LCT_ListeChainee* liste){
  if (!LCT_estVide(*liste)){
    LCT_supprimerTete(liste);
    LCT_supprimer(liste);
  }
}

void LCT_ajouter(LCT_ListeChainee* liste, TA_Tache element){
  LCT_ListeChainee temp = (LCT_ListeChainee)malloc(sizeof(LCT_Noeud));
  
  LCT_fixerElement(&temp, element);
  LCT_fixerListeSuivante(&temp, *liste);
  *liste = temp;
}

int LCT_longueur(LCT_ListeChainee liste){
  if (LCT_estVide(liste)){
    return 0;
  } else {
    return 1+LCT_longueur(LCT_obtenirListeSuivante(liste));
  }
}

void LCT_inserer(LCT_ListeChainee* liste, TA_Tache element, int position){
  LCT_ListeChainee temp = (LCT_ListeChainee)malloc(sizeof(LCT_ListeChainee));
  if (LCT_estVide(*liste)){
    LCT_ajouter(liste, element);
  } else {
    if (position > 0){
      temp = LCT_obtenirListeSuivante(*liste);
      LCT_inserer(&temp, element, position-1);
      LCT_fixerListeSuivante(liste, temp);
    } else {
      LCT_ajouter(liste, element);
    }
  }
}

TA_Tache LCT_iemeElement(LCT_ListeChainee liste, int position){
  assert(LCT_longueur(liste) > position);
  LCT_ListeChainee temp = liste;

  for (int i = 0; i < position; i++){
    temp = LCT_obtenirListeSuivante(temp);
  }
  return LCT_obtenirElement(temp);
}

void LCT_supprimerElement(LCT_ListeChainee* liste, TA_Tache element){
  if (!LCT_estVide(*liste)){
    if (TA_obtenirNumero(LCT_obtenirElement(*liste)) == TA_obtenirNumero(element)){
      LCT_supprimerTete(liste);
    } else {
      LCT_ListeChainee temp = LCT_obtenirListeSuivante(*liste);
      LCT_supprimerElement(&temp, element);
      LCT_fixerListeSuivante(liste, temp);
    }
  }
}

bool LCT_membre(LCT_ListeChainee liste, TA_Tache element){
  if (!LCT_estVide(liste)){
    if (TA_obtenirNumero(LCT_obtenirElement(liste)) == TA_obtenirNumero(element)){
      return true;
    } else {
      return LCT_membre(LCT_obtenirListeSuivante(liste), element);
    }
  } else {
    return false;
  }
}

void LCT_fixerIemeElement(LCT_ListeChainee* liste, TA_Tache element, int position){
	if (position == 0){
		LCT_fixerElement(liste, element);
	} else {
    LCT_ListeChainee ls = LCT_obtenirListeSuivante(*liste);
		LCT_fixerIemeElement(&ls, element, position-1);
	}
}

void LCT_supprimerIemeElement(LCT_ListeChainee* liste, int position){
  if (position == 0){
    LCT_supprimerTete(liste);
  } else {
    LCT_ListeChainee temp = LCT_obtenirListeSuivante(*liste);
    LCT_supprimerIemeElement(&temp, position-1);
    LCT_fixerListeSuivante(liste, temp);
  }

}
