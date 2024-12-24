#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "listeChaineeTache.h"
#include "tache.h"
#include "todo.h"
#include "ihm.h"

#define JOURS 24*60*60

int main(){
	TO_TodoListe liste = TO_listeVide();
	TO_ajouterTache(&liste, "Tests", 2);
	TO_ajouterTache(&liste, "IHM Terminal", 7);
	TO_ajouterTache(&liste, "IHM SDL", 1000);
	TO_validerTache(&liste, 2);
	bool exit = false;
	IHM_Menu scene = MENU;
	while(!exit){
		IHM_afficher(liste, scene);
		IHM_gererEntrees(&liste, &exit, &scene);
	}
	TO_supprimerListe(&liste);
}
