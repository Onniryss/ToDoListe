#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#define JOURS 24*60*60

typedef struct {
    long int numero;
    bool etat;
    char* description;
    time_t dateDebut;
    time_t dateFin;
} TA_Tache;

long int TA_obtenirNumero(TA_Tache tache){
    return tache.numero;
}

void TA_fixerNumero(TA_Tache* tache, long int numero){
    tache->numero = numero;
}

bool TA_obtenirEtat(TA_Tache tache){
    return tache.etat;
}

void TA_fixerEtat(TA_Tache* tache, bool etat){
    tache->etat = etat;
}

char* TA_obtenirDescription(TA_Tache tache){
    return tache.description;
}

void TA_fixerDescription(TA_Tache* tache, char* description){
    tache->description = description;
}

time_t TA_obtenirDateDebut(TA_Tache tache){
    return tache.dateDebut;
}

void TA_fixerDateDebut(TA_Tache* tache, time_t debut){
    tache->dateDebut = debut;
}

time_t TA_obtenirDateFin(TA_Tache tache){
    return tache.dateFin;
}

void TA_fixerDateFin(TA_Tache* tache, time_t fin){
    tache->dateFin = fin;
}

unsigned long TA_obtenirTempsRestant(TA_Tache tache){
    return (unsigned long)difftime(tache.dateFin, tache.dateDebut)/(24*60*60);
}

void TA_afficherTache(TA_Tache tache){
    if (tache.etat) {
        printf("[x] -- %s -- %ld jours restants\n", TA_obtenirDescription(tache), TA_obtenirTempsRestant(tache));
    } else {
        printf("[ ] -- %s -- %ld jours restants\n", TA_obtenirDescription(tache), TA_obtenirTempsRestant(tache));
    }
}