#ifndef LISTASLOGOVA_H_INCLUDED
#define LISTASLOGOVA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "typedef.h"

typedef struct tSlog{
    Slog slog;
    struct tSlog *next;
}TSlog;


void dodajSlog(TSlog** glava, Slog* slog);
void obrisiListu(TSlog** glava);

void obrisiZaIS(Slog** glava);
void dodajZaIS(Slog** glava,Slog slog);

#endif // LISTASLOGOVA_H_INCLUDED
