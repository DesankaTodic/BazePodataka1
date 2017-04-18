#ifndef TYPEDEF_H_INCLUDED
#define TYPEDEF_H_INCLUDED


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 30
#define FBL 5
#define MAX_BLOKOVA 15
#define n 2 //red stabla = 2
#define IBF 0.6


char aktivna[MAX_CHAR];
FILE *indSek,*sekvenc, *serijska;

enum Status_sloga{
            NEAKTUELAN=0,
            AKTUELAN=1,
};

typedef struct slog{
    int evidencioni_broj;
    char registarska_oznaka[11];
    char datum_vrijeme[70];
    char polaziste[70];
    char odrediste[70];
    int iznos;
    struct slog *pok;
    enum Status_sloga status;
} Slog;

typedef struct blok {
    Slog slogovi[FBL];
    //int adresa;
    struct blok *pok;
} Blok;

typedef struct blok_primarne{
    Blok blok;
    int prekoracioci;
} Blok_primarne;

typedef struct cvor{
    int najveci_l;//najveci lijevi
    int najveci_d;//najveci desni
    int adresa_l;//adresa lijevog u cvoru
    int adresa_d;//adresa desanog u cvoru
} TCvor;

typedef struct blok_prekoracilac{
    Slog slog;
    int prekoracioci;
} Blok_prekoracilac;

#endif // TIPOVI_H_INCLUDED

