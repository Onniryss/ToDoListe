#ifndef __TACHE__
#define __TACHE__

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

typedef struct {
    long int numero;
    bool etat;
    char* description;
    time_t dateDebut;
    time_t dateFin;
} TA_Tache;

long int TA_obtenirNumero(TA_Tache tache);
void TA_fixerNumero(TA_Tache* tache, long int numero);
bool TA_obtenirEtat(TA_Tache tache);
void TA_fixerEtat(TA_Tache* tache, bool etat);
char* TA_obtenirDescription(TA_Tache tache);
void TA_fixerDescription(TA_Tache* tache, char* description);
time_t TA_obtenirDateDebut(TA_Tache tache);
void TA_fixerDateDebut(TA_Tache* tache, time_t debut);
time_t TA_obtenirDateFin(TA_Tache tache);
void TA_fixerDateFin(TA_Tache* tache, time_t fin);
double TA_obtenirTempsRestant(TA_Tache tache);
void TA_afficherTache(TA_Tache tache);
#endif