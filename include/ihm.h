#ifndef __IHM__
#define __IHM__

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "todo.h"

#define clear() printf("\033[H\033[J")
#define gotoxy(x,y) printf("\033[%d;%dH", (y), (x))

void IHM_gererEntrees(TO_TodoListe* liste, bool* exit);
void IHM_afficherTerminal(TO_TodoListe liste);

#endif