#include "listaSlogova.h"
//////////////////////////////////lista za sekvencijalnu
void dodajSlog(TSlog** glava, Slog* slog) {
    printf("Dodajem sloggggggggg");
    TSlog *prethodni;
    TSlog *trenutni;
    //alokacija mem velicine liste za cuvanje dobijenog sloga
    TSlog *temp = (TSlog*) malloc(sizeof(TSlog));
    //kopira slog iz memorije u memoriju sloga tempa
    memcpy(&temp->slog, slog, sizeof(Slog));
    //da li je lista prazna
    //ili kljuc sloga glave manji od kljuca dobijenog sloga
    //u tom slucaju slog dodajemo ispred sloga glave
    if ((*glava) == NULL || ( (*glava)->slog.evidencioni_broj) > slog->evidencioni_broj) {
        temp->next = *glava;
        *glava = temp;
    }
    else//kljuca dob. sloga je veci od sloga glave
        {
            prethodni = *glava;
            trenutni = (*glava)->next;

            while (1) {
            //slog uvezujemo tako da glava pokazuje na njega
            //a on pokazuje na ono na sta je pokazivala glava
                if ((trenutni == NULL) || (trenutni->slog.evidencioni_broj > slog->evidencioni_broj)) {
                    prethodni->next = temp;
                    temp->next = trenutni;
                    break;
                }
                else {//prolazimo kroz listu sve dok ne zadovoljimo uslov if-a
                    prethodni = trenutni;
                    trenutni = trenutni->next;
                }
            }
        }


}
void obrisiListu(TSlog** glava) {

    TSlog* temp = *glava;
    TSlog* prethodni;

    while (temp) {
        prethodni = temp;
        temp = temp->next;
        free(prethodni);
    }

    *glava = NULL;
}
/////////////////////////////lista za indeks-sekvencijalnu

void dodajZaIS(Slog** glava,Slog slog){
        Slog *temp = (Slog*)malloc(sizeof(Slog));
        temp->evidencioni_broj = slog.evidencioni_broj;
        strcpy(temp->datum_vrijeme,slog.datum_vrijeme);
        strcpy(temp->registarska_oznaka,slog.registarska_oznaka);
        strcpy(temp->odrediste,slog.odrediste);
        strcpy(temp->polaziste,slog.polaziste);
        temp->iznos = slog.iznos;
        temp->pok = NULL;

        Slog *tekuci = *glava, *prethodni = *glava;
        if(*glava){//ako lista nije prazna
            while(tekuci){//ako je tekuci id veci od novog
                if(tekuci->evidencioni_broj > temp->evidencioni_broj){
                    temp->pok = tekuci;
                    if(tekuci == *glava)
                        *glava = temp;
                    else
                        prethodni->pok = temp;
                break;
                }
                prethodni = tekuci;
                tekuci = tekuci->pok;
                if(tekuci == NULL)//dodavanje na kraj liste
                    prethodni->pok = temp;
            }
        }else{//kad je prazna
            *glava = temp;
        }
}
void obrisiZaIS(Slog** glava) {

    Slog* temp = *glava;
    Slog* prethodni;

    while (temp) {
        prethodni = temp;
        temp = temp->pok;
        free(prethodni);
    }

    *glava = NULL;
}
