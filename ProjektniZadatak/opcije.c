#include "opcije.h"
#include "typedef.h"
#include "listaSlogova.h"


void formiranjePrazne() {
    FILE *datoteka;
    char naziv[MAX_CHAR];
    printf("\nUnesite naziv datoteke: ");
    fflush(stdin);
    gets(naziv);

    datoteka = fopen(naziv,"wb");

    if(datoteka == NULL){
        printf("\nDatoteka nije uspesno otvorena!");
    }else
        printf("\nDatoteka <%s> je uspesno otvorena",naziv);

    fclose(datoteka);

}
void izborAktivne() {

    FILE *datoteka;
    char naziv[MAX_CHAR];
    printf("\nUnesite naziv datoteke koju zelite da proglasite aktivnom: ");
    fflush(stdin);
    gets(naziv);

    datoteka = fopen(naziv,"rb+");

    if(datoteka == NULL) {
        printf("\nDatoteka <%s> nije uspjesno otvorena!",naziv);
        return;
    }

    if(indSek != NULL)
        fclose(indSek);

    indSek = datoteka;
    strcpy(aktivna,naziv);
    printf("\nDatoteka <%s> je aktivna!",naziv);

    fclose(datoteka);

}
void prikazAktivne() {
    if(strcmp(aktivna,"") == 0)
        printf("\nNijedna datoteka nije aktivna!");
    else
        printf("\nNaziv aktivne datoteke je <%s>!",aktivna);
}
void formiranjeSerijske() {

    FILE *datoteka;

    Slog pomocni;
    Slog novi;
    Blok blok;
     Blok b;
    int kljuc;
    int dan;
    int mjesec;
    int godina;
    int sat;
    int minut;
   int ni;//broj slogova koji korisnik zeli da unese
    int pomi;
    int i;
    //int broj_slogova=0;//promjenljiva kad je =FBL upisujemo blok u datotetku
    /* for(pomi=0;pomi<FBL;pomi++){
                 blok.slogovi[pomi].evidencioni_broj=0;
                 memset(blok.slogovi[pomi].registarska_oznaka, 0x00, 12);//jer je reg oznaka 11 karakter+/0
                 memset(blok.slogovi[pomi].datum_vrijeme, 0x00, 71);
                memset(blok.slogovi[pomi].polaziste, 0x00, 71);
                memset(blok.slogovi[pomi].odrediste, 0x00, 71);
                blok.slogovi[pomi].iznos=0;
                blok.slogovi[pomi].status=NEAKTUELAN;
            }
   // printf("\nKoliko slogova zelite da unesete? ");
    //scanf("%d",&ni);
    datoteka = fopen("serijska","wb+");
    ni = 5;
    for(i=0;i<ni;i++){

        printf("--------------------------------------");
        novi.status = AKTUELAN;//svaki novi slog koji dodajem je aktuelan
       do {
            printf("\nUnesite evidencioni broj (7 cifara): ");
            fflush(stdin);
            scanf("%d",&kljuc);
            //kontrola kljuca
            //iscita sve blokove iz datoteke i provjeri da li neki slog ima uneseni kljuc
             for(pomi=0;pomi<FBL;pomi++){
                 if(blok.slogovi[pomi].evidencioni_broj==kljuc){
                    printf("\nEvidencioni broj postoji.\n");
                        kljuc = 0;
                        break;
                 }
             }

            while(1){
                if(!fread(&b,sizeof(Blok),1,datoteka))
                    break;

                for(pomi=0;pomi<FBL;pomi++){
                    Slog slog = b.slogovi[pomi];
                    if(slog.evidencioni_broj == kljuc){
                        printf("\nEvidencioni broj postoji.\n");
                        kljuc = 0;
                        break;
                    }

                }///for

            } ///while

        } while (kljuc>9999999 || kljuc<1000000);

        novi.evidencioni_broj = kljuc;

       //fclose(datoteka);
        do{
            printf("\nUnesite registarsku oznaku vozila (najvise 11 karaktera): \n");
            fflush(stdin);
            gets(novi.registarska_oznaka);
        }while(strlen(novi.registarska_oznaka)>11);


        do {
            printf("\nUnesite godinu: ");
            fflush(stdin);
            scanf("%d",&godina);
            if(godina<2000 || godina>2050) {
                printf("\nNeispravan format!\n");
                }
            } while(godina<2000 || godina>2050);

        do {
            printf("\nUnesite mjesec: ");
            fflush(stdin);
            scanf("%d", &mjesec);
            if(mjesec <1 || mjesec>12) {
                printf("\nNeispravan format!\n");
                }
            } while(mjesec<1 || mjesec>12);

        if(mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) {
            do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>31 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>31 || dan<1);

        } else if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) {
         do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>30 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>30 || dan<1);

        } else if(godina%4 == 0) {
             do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan> 29 || dan < 1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>29 || dan<1);

        } else {
         do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>28 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>28 || dan<1);
        }


        do {
            printf("\nUnesite sat: ");
            fflush(stdin);
            scanf("%d", &sat);
            if(sat<0 || sat>23) {
                printf("\nNeispravan format!\n");
            }
        } while (sat<0 || sat>23);

        do {
            printf("\nUnesite minut: ");
            fflush(stdin);
            scanf("%d", &minut);
            if(minut < 0 || minut> 59) {
                printf("\nNeispravan format!\n");
            }
        } while(minut>59 || minut <0);

         sprintf(novi.datum_vrijeme, "%d.%d.%d.  %d:%d", dan, mjesec, godina, sat, minut);


        printf("\nUnesi odrediste: ");
        fflush(stdin);
        gets(novi.odrediste);

        printf("\nUnesi polaziste: ");
        fflush(stdin);
        gets(novi.polaziste);


        do {
            printf("\nUnesi iznos: ");
            fflush(stdin);
            scanf("%d", &novi.iznos);

            if(novi.iznos > 1000000000)
                printf("Prekoracili ste maksimalni iznos usluge!");
        }   while(novi.iznos>1000000000);

       // datoteka = fopen("serijska","ab+");
      // fwrite(&novi,sizeof(Slog),1,datoteka);
      blok.slogovi[broj_slogova]=novi;
        ++broj_slogova;//dodat je novi slog
        if(broj_slogova == FBL){//upis blok u serijsku
            broj_slogova = 0;

           if(fwrite(&blok,sizeof(Blok),1,datoteka)){
                printf("\nBlok od 5 slogova je uspjesno upisan u serijsku datoteku!");
                 for(pomi=0;pomi<FBL;pomi++){
                     blok.slogovi[pomi].evidencioni_broj=0;
                     memset(blok.slogovi[pomi].registarska_oznaka, 0x00, 12);//jer je reg oznaka 11 karakter+/0
                     memset(blok.slogovi[pomi].datum_vrijeme, 0x00, 71);
                     memset(blok.slogovi[pomi].polaziste, 0x00, 71);
                     memset(blok.slogovi[pomi].odrediste, 0x00, 71);
                     blok.slogovi[pomi].iznos=0;
                     blok.slogovi[pomi].status=NEAKTUELAN;
                }
            }else
                printf("Greska prilikom upisa bloka u serijsku datoteku!");
            }

       //fclose(datoteka);
    }
     if(broj_slogova>0){//ako nisu svi slogovi upisani u serijsku
            if(fwrite(&blok,sizeof(Blok),1,datoteka)){
                printf("\nBlok je uspjesno upisan u serijsku datoteku!");
            }
        }
       //datoteka=fopen("serijska","rb");


    while(1){
        if(!fread(&b,sizeof(Blok),1,datoteka))
            break;

        for(pomi=0;pomi<FBL;pomi++){
                Slog slog = b.slogovi[pomi];
            if(slog.status!=NEAKTUELAN){
                printf("--------------------------------------");
                printf("\n\tEvidencioni broj: %d",slog.evidencioni_broj);
                printf("\n\tRegistarska oznaka: %s",slog.registarska_oznaka);
                printf("\n\tDatum i vrijeme: %s",slog.datum_vrijeme);
                printf("\n\tPolaziste: %s",slog.polaziste);
                printf("\n\tOdrediste: %s",slog.odrediste);
                printf("\n\tIznos usluge: %d\n",slog.iznos);
            }

        }
    }*/
    printf("\nUnesite broj slogova: ");
    scanf("%d",&ni);
    for(i = 0;i < ni; i++){

        printf("--------------------------------------");
        novi.status = AKTUELAN;//svaki novi slog koji dodajem je aktuelan
       datoteka = fopen("serijska","rb");
       do {
            printf("\nUnesite evidencioni broj (7 cifara): ");
            fflush(stdin);
            scanf("%d",&kljuc);
            //kontrola kljuca
            //iscita sve blokove iz datoteke i provjeri da li neki slog ima uneseni kljuc

             while (fread(&pomocni,sizeof(Slog),1,datoteka)){
                if (pomocni.evidencioni_broj==kljuc){
                    printf("\nEvidencioni broj postoji.\n");
                    kljuc=0;
                    break;
                }
            }

        } while (kljuc>9999999 || kljuc<1000000);

        novi.evidencioni_broj = kljuc;

       fclose(datoteka);
        do{
            printf("\nUnesite registarsku oznaku vozila (najvise 11 karaktera): \n");
            fflush(stdin);
            gets(novi.registarska_oznaka);
        }while(strlen(novi.registarska_oznaka)>11);


        do {
            printf("\nUnesite godinu: ");
            fflush(stdin);
            scanf("%d",&godina);
            if(godina<2000 || godina>2050) {
                printf("\nNeispravan format!\n");
                }
            } while(godina<2000 || godina>2050);

        do {
            printf("\nUnesite mjesec: ");
            fflush(stdin);
            scanf("%d", &mjesec);
            if(mjesec <1 || mjesec>12) {
                printf("\nNeispravan format!\n");
                }
            } while(mjesec<1 || mjesec>12);

        if(mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) {
            do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>31 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>31 || dan<1);

        } else if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) {
         do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>30 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>30 || dan<1);

        } else if(godina%4 == 0) {
             do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan> 29 || dan < 1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>29 || dan<1);

        } else {
         do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>28 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>28 || dan<1);
        }


        do {
            printf("\nUnesite sat: ");
            fflush(stdin);
            scanf("%d", &sat);
            if(sat<0 || sat>23) {
                printf("\nNeispravan format!\n");
            }
        } while (sat<0 || sat>23);

        do {
            printf("\nUnesite minut: ");
            fflush(stdin);
            scanf("%d", &minut);
            if(minut < 0 || minut> 59) {
                printf("\nNeispravan format!\n");
            }
        } while(minut>59 || minut <0);

         sprintf(novi.datum_vrijeme, "%d.%d.%d.  %d:%d", dan, mjesec, godina, sat, minut);


        printf("\nUnesi odrediste: ");
        fflush(stdin);
        gets(novi.odrediste);

        printf("\nUnesi polaziste: ");
        fflush(stdin);
        gets(novi.polaziste);


        do {
            printf("\nUnesi iznos: ");
            fflush(stdin);
            scanf("%d", &novi.iznos);

            if(novi.iznos > 1000000000)
                printf("Prekoracili ste maksimalni iznos usluge!");
        }   while(novi.iznos>1000000000);
        datoteka=fopen("serijska","ab+");
        fwrite(&novi,sizeof(Slog),1,datoteka);
        fclose(datoteka);
    }


}
void citajSerijsku(){
    serijska = fopen("serijska","rb");
    //Blok blok;
    Slog slog;

    int i=0;
    //int j=0;
     while(fread(&slog,sizeof(Slog),1,serijska)){
            if(slog.status==AKTUELAN){
                printf("\nSlog: %d",i+1);
                printf("\n\tEvidencioni broj: %d",slog.evidencioni_broj);
                printf("\n\tRegistarska oznaka: %s",slog.registarska_oznaka);
                printf("\n\tDatum i vrijeme: %s",slog.datum_vrijeme);
                printf("\n\tPolaziste: %s",slog.polaziste);
                printf("\n\tOdrediste: %s",slog.odrediste);
                printf("\n\tIznos usluge: %d\n",slog.iznos);
            }
       i++;
     }
     fclose(serijska);

}
void formiranjeSekvencijalne(){

   /* while(1){
            printf("Citam serijskuuu\n");
        for(pomi=0;pomi<FBL;pomi++){
                 blok.slogovi[pomi].evidencioni_broj=0;
                 memset(blok.slogovi[pomi].registarska_oznaka, 0x00, 12);//jer je reg oznaka 11 karakter+/0
                 memset(blok.slogovi[pomi].datum_vrijeme, 0x00, 71);
                 memset(blok.slogovi[pomi].polaziste, 0x00, 71);
                 memset(blok.slogovi[pomi].odrediste, 0x00, 71);
                 blok.slogovi[pomi].iznos=0;
                 blok.slogovi[pomi].status=NEAKTUELAN;
        }
        if(!fread(&blok,sizeof(Blok),1,serijska))
            break;
        for(pomi=0;pomi<FBL;pomi++){
            printf("\n da li aktuelannn jeee\n");
            if(blok.slogovi[pomi].status != NEAKTUELAN){
                printf("\naktuelannn jeee\n");
                dodajSlog(&glava,blok.slogovi[pomi]);
                broj_slogova++;
            }
        }
    }
    printf("\nBroj slogova! %d",broj_slogova);
    fclose(serijska);
    sekvenc = fopen("sekvencijalna","wb");
    //upisujemo broj slogova u sekvencijalnu
    fwrite(&broj_slogova, sizeof(int),1,sekvenc);


    int i = 0;
    int broj_blokova = 0;//broj blokova u sekvencijalnoj
    while(glava != NULL){
        printf("\nGlava nije prazna\n");
        blok.slogovi[i] = *glava;
        i++;
        if(i == FBL){
            printf("\nUpis bloka u sekvencijalnu!\n");
            fwrite(&blok,sizeof(Blok),1,sekvenc);
            i = 0;
            broj_blokova++;
            //anulacija slogova bloka nakon upisa bloka u datoteku
             for(pomi=0;pomi<FBL;pomi++){
                 blok.slogovi[pomi].evidencioni_broj=0;
                 memset(blok.slogovi[pomi].registarska_oznaka, 0x00, 12);//jer je reg oznaka 11 karakter+/0
                 memset(blok.slogovi[pomi].datum_vrijeme, 0x00, 71);
                memset(blok.slogovi[pomi].polaziste, 0x00, 71);
                memset(blok.slogovi[pomi].odrediste, 0x00, 71);
                blok.slogovi[pomi].iznos=0;
                blok.slogovi[pomi].status=NEAKTUELAN;
            }
        }
        pomocna = glava;
        glava = glava->pok;
        free(pomocna);
    }
    if(i>0){
        fwrite(&blok,sizeof(Blok),1,sekvenc);
        broj_blokova++;
    }
    printf("Broj blokova: %d ", broj_blokova);


    fclose(sekvenc);
    //free(iterator);
    //obrisiListu(&glava);
    printf("\nSekvencijalna datoteka je uspjesno formirana!\n");

    sekvenc = fopen("sekvencijalna","rb");
    i=0;
    int j=0;
    Slog slog;

    fread(&broj_slogova,sizeof(int),1,sekvenc);//iscitavam koliko slogova ima u sekvencijalnoj

   // printf("\nBrojcic slogova!!!!= %d",broj_slogova);

     while(1){
        printf("\nCitam sekvencijalnuuuuu");
        printf("%d",fread(&blok,sizeof(Blok),1,sekvenc));
        if(!fread(&blok,sizeof(Blok),1,sekvenc))
            break;
        printf("\nBlok: %d",j++);
        for(i=0;i<FBL;i++){
            slog = blok.slogovi[i];
            printf("%d",slog.status);
            if(slog.status!=NEAKTUELAN){
                printf("\nAktuelan jeee!");

                printf("\nSlog: %d",i+1);
                printf("\n\tEvidencioni broj: %d",slog.evidencioni_broj);
                printf("\n\tRegistarska oznaka: %s",slog.registarska_oznaka);
                printf("\n\tDatum i vrijeme: %s",slog.datum_vrijeme);
                printf("\n\tPolaziste: %s",slog.polaziste);
                printf("\n\tOdrediste: %s",slog.odrediste);
                printf("\n\tIznos usluge: %d\n",slog.iznos);
            }
        }

     }
     fclose(sekvenc);
     */

    Slog pomocni;
    Blok blok;
    TSlog *glava = NULL;
    TSlog *iterator;
    int broj_slogova = 0;//koliko slogova ucitavamo iz serijske

    serijska = fopen("serijska","rb");
    while(fread(&pomocni,sizeof(Slog),1,serijska)){
        if(pomocni.status == AKTUELAN){
            dodajSlog(&glava,&pomocni);
            broj_slogova++;
        }
    }
    fclose(serijska);


    sekvenc = fopen("sekvencijalna","wb");
    //upisujemo broj slogova u sekvencijalnu
    fwrite(&broj_slogova, sizeof(int),1,sekvenc);

    iterator = glava;

       while(iterator != NULL) {
            printf("\n%d\n",iterator->slog.evidencioni_broj);
            iterator = iterator->next;
        }

    int i = 0;
    int pomi;//za anulaciju slogova
    iterator = glava;
    while(iterator != NULL){
        printf("\nGlava nije prazna!");
        blok.slogovi[i] = iterator -> slog;
        i++;
        if(i == FBL){
            fwrite(&blok,sizeof(Blok),1,sekvenc);
            i = 0;
        }
        iterator = iterator->next;
    }//ako nije popunjen cijeli blok
    if(i>0){

        for(pomi=i;pomi<FBL;pomi++){
                 blok.slogovi[pomi].evidencioni_broj=0;
                 memset(blok.slogovi[pomi].registarska_oznaka, 0x00, 12);//jer je reg oznaka 11 karakter+/0
                 memset(blok.slogovi[pomi].datum_vrijeme, 0x00, 71);
                 memset(blok.slogovi[pomi].polaziste, 0x00, 71);
                 memset(blok.slogovi[pomi].odrediste, 0x00, 71);
                 blok.slogovi[pomi].iznos=0;
                 blok.slogovi[pomi].status=NEAKTUELAN;
        }
        fwrite(&blok,sizeof(Blok),1,sekvenc);
        printf("Zapisaoooooooooooooo");
    }


    fclose(sekvenc);
    free(iterator);
    obrisiListu(&glava);
    printf("\nSekvencijalna datoteka je uspjesno formirana!\n");
}
void citajSekvencijalnu() {
   sekvenc = fopen("sekvencijalna","rb");
    Blok blok;
    Slog slog;
    int broj_slogova = 0;
    int i=0;
    int j=0;
    fread(&broj_slogova,sizeof(int),1,sekvenc);
     while(fread(&blok,sizeof(Blok),1,sekvenc)){
        printf("\nBlok: %d",j);
        for(i=0;i<FBL;i++){
            slog = blok.slogovi[i];
            //printf("%d",slog.status);
            if(slog.status!=NEAKTUELAN){
               // printf("\nAktuelan jeee!");
                printf("\nSlog: %d",i);
                printf("\n\tEvidencioni broj: %d",slog.evidencioni_broj);
                printf("\n\tRegistarska oznaka: %s",slog.registarska_oznaka);
                printf("\n\tDatum i vrijeme: %s",slog.datum_vrijeme);
                printf("\n\tPolaziste: %s",slog.polaziste);
                printf("\n\tOdrediste: %s",slog.odrediste);
                printf("\n\tIznos usluge: %d\n",slog.iznos);
            }
        }
        j++;
     }
     fclose(sekvenc);
}

void formiranjeIndeksSekvencijalne(){
    Blok_primarne blok_prim;//blok primarne zone
    Blok blok;//obican blok

    Slog* glava = NULL;
    Slog* pomocni;
    //smjestamo u zaglavlje
    int zona_indeksa = 0;
    int zona_prekoracilac = 0;
    int korijen = 0;//adresa korijena
    int h = 0;//visina stabla
    int slobodnih = 0;
    int broj_slogova;//ukupan broj slogova zapisan u zaglavlje sekvencijalne

    if(indSek == NULL){
         printf("\nOdredi aktivnu datoteku!");
         return;
     }
    sekvenc = fopen("sekvencijalna","rb");
    indSek = fopen(aktivna, "rb+");

    rewind(indSek);//postavljenje pozicije na pocetak fajla
    fwrite(&zona_indeksa,sizeof(int),1,indSek);

    fwrite(&zona_prekoracilac,sizeof(int),1,indSek);

    fwrite(&slobodnih,sizeof(int),1,indSek);

    fwrite(&h,sizeof(int),1,indSek);

    fwrite(&korijen,sizeof(int),1,indSek);


    fread(&broj_slogova,sizeof(int),1,sekvenc);
    int zauzeti_blokovi = (int)ceil(broj_slogova/(FBL*IBF));
    //dinamicki zauxet niz koji sadrzi max kljuc za svaki blok
    int *kljucevi = (int*)malloc(sizeof(int)*zauzeti_blokovi);
    int i,j,k;
    for(i = 0;i < zauzeti_blokovi; i++)
        kljucevi[i] = 0;
        //ucitavamo sve blokove iz sekvncijalne
    while(1){
        for(i = 0;i < FBL;i++){
            blok.slogovi[i].status = NEAKTUELAN;
        }
        if(!fread(&blok,sizeof(Blok),1,sekvenc))
            break;
            //////////////////////////////////////////pogledaj listu i dodaj
        for(i = 0;i < FBL;i++){
            if(blok.slogovi[i].status != NEAKTUELAN){
                dodajZaIS(&glava,blok.slogovi[i]);
            }
        }
        ///////////////////////////////////////////////////////////////////////////
    }
    int slogoviPrimarnog = 0;
    int adresa = 0;//redni broj bloka predstavlja adresu primarnog bloka
    int broj_blokova = IBF*FBL;//u nasem slucaju 3 = 0.6*5;
    printf("\nBroj blokova: %d", broj_blokova);
    while(glava != NULL){

        if(slogoviPrimarnog + 1 <= broj_blokova){//ako ima mjesta u bloku
            blok_prim.blok.slogovi[slogoviPrimarnog] = *glava;
            slogoviPrimarnog++;
            printf("\nDodat je slog sa kljucem %d u blok %d kao %d. slog! \n",(*glava).evidencioni_broj,adresa,slogoviPrimarnog);
        }else{//kad nema mjesta uzimamo posljedni kljuc i punimo drugi blok
            blok_prim.prekoracioci = -1;//nemamo prekoracilaca
            kljucevi[adresa] = blok_prim.blok.slogovi[slogoviPrimarnog - 1].evidencioni_broj;
            slogoviPrimarnog = 0;
            //upisemo blok u datoteku
            fwrite(&blok_prim,sizeof(Blok_primarne),1,indSek);
            //oslobodimo pomocni blok
            for(j = 0;j < FBL; j++)
                blok_prim.blok.slogovi[j].status = NEAKTUELAN;
            adresa++;//novi redni broj bloka tj. adresa

            blok_prim.blok.slogovi[slogoviPrimarnog] = *glava;
            slogoviPrimarnog++;
            printf("\nDodat je slog sa kljucem %d u blok %d kao %d. slog! \n",(*glava).evidencioni_broj,adresa,slogoviPrimarnog);
        }
        pomocni = glava;
        glava = glava -> pok;
        free(pomocni);
    }
    if(slogoviPrimarnog > 0){
        blok_prim.prekoracioci = -1;//nema prekoracilaca
        kljucevi[adresa] = blok_prim.blok.slogovi[slogoviPrimarnog - 1].evidencioni_broj;
        slogoviPrimarnog = 0;
        fwrite(&blok_prim,sizeof(Blok_primarne),1,indSek);

        for(j = 0;j < FBL; j++){
            blok_prim.blok.slogovi[j].status = NEAKTUELAN;
        }
        adresa++;
    }
    kljucevi[adresa - 1] = 9999999;//u kao kljuc posljednjeg bloka dodjelujemo
                                    //najvecu mogucu vrijednost kljuca
    printf("\nNajveci kljucevi: \n");
    for(i = 0;i < adresa;i++)
        printf("%d  ",kljucevi[i]);
    //visina stabla je h=log baze n od (broj blokova),n=red stabla
    double logN = log10((double)adresa)/log10((double)n);
    h = (int)ceil(logN);

    int C = 0;//ukupan broj cvorova stabla
    int *brojCvorova = (int*)malloc(sizeof(int)*(h + 1));//zauzimamo memoriju za smjestanje cvorova
    brojCvorova[0] = -1;//ne treba nam nulti nivo
    //na najvisem nivou(h-tom) je korijen
    //racunanje ukupnog broja cvorova u stablu C=suma od 1 do h(broj blokova/n na h-i+1)
    for(i = 1;i <= h;i++){
        brojCvorova[i] = (int)ceil((double)adresa/pow((double)n,h-i+1));
        C += brojCvorova[i];
        printf("\n Visina %d, broj cvorova %d\n",i,brojCvorova[i]);
    }
    //5 promjenljivih je u zaglavlju datotetke
    //zona_indeksa je offset za pozicioniranje
    zona_indeksa = 5*sizeof(int) + sizeof(Blok_primarne)*adresa;
    int brojListova = brojCvorova[h];//broj listova
    //zauzimanje memorije za listove
    TCvor* listovi = (TCvor*)malloc(sizeof(TCvor)*brojListova);
    int rbBloka = 0;//redni broj bloka u primarnoj
    int rbLista = 0;//redni broj lista
    while(rbBloka < adresa){
        if(rbBloka % 2 == 0){
            //za paran redni broj bloka popunjavamo lijevo mjesto u listu
            listovi[rbLista].najveci_l = kljucevi[rbBloka];
            listovi[rbLista].adresa_l = rbBloka;
            //ako je se u bloku nalazi najveci kljuc onda on nema desanog
            //tj posljednj je blok
            if(kljucevi[rbBloka] == 9999999){
                listovi[rbLista].najveci_d = -1;
                listovi[rbLista].adresa_d = -1;
            }
        }else{
            listovi[rbLista].najveci_d = kljucevi[rbBloka];
            listovi[rbLista].adresa_d = rbBloka;
            rbLista++;//zavrsiili smo popunjavanje jednog lista prelazimo na drugi
        }
        rbBloka++;//prelazimo na sljedeci blok
    }
        //pozicioniranje poslije primarne zone
        fseek(indSek,zona_indeksa,SEEK_SET);
        //upis svih listova
        for(i = 0;i < brojListova;i++){
            fwrite(&listovi[i],sizeof(TCvor),1,indSek);
            printf("\n%d. list(visina = %d) -> \t%d | %d \t||\t %d | %d\n",i,h,listovi[i].adresa_l,listovi[i].najveci_l,listovi[i].adresa_d,listovi[i].najveci_d);
        }
        TCvor* prethodni;
        TCvor* novi;
        int rbCvora = 0;//redni broj cvora
        for(i = h - 1;i > 0;i--){//kreiranje visih nivoa
            if(i == h - 1)
                prethodni = listovi;//u prvom prolazu prethodni su listovi
            else
                prethodni = novi;//kasnije su to bivsi novi
            //zauzimanje memorije koliko nivo moze imati mogucih cvorova
            novi = (TCvor*)malloc(sizeof(TCvor)*brojCvorova[i]);
            k = 0;//za kretanje kroz podredjene
            for(j = 0;j < brojCvorova[i+1];j++,rbCvora++){
                //popunjavanje lijevih
                if(j % 2 == 0){
                    if(prethodni[j].najveci_d == -1){//ako smo dosli do onog koji nema desnog
                        novi[k].najveci_l = prethodni[j].najveci_l;
                        novi[k].adresa_l = rbCvora;//adrese su redni brojevi cvora unutar zone indeksa
                    }else{
                        novi[k].najveci_l = prethodni[j].najveci_d;
                        novi[k].adresa_l = rbCvora;
                    }
                    //ako je u prethodnom nivou bio neparan broj cvorova
                    //u posljednjiem cvoru desni je prazan
                    //for jos nije povecao j ;)
                    if(j == brojCvorova[i + 1] - 1){
                        novi[k].adresa_d = -1;
                        novi[k].najveci_d = -1;
                    }
                    //popunjavanje desnih
                }else{
                    if(prethodni[j].najveci_d == -1){
                        novi[k].najveci_d = prethodni[j].najveci_l;
                        novi[k].adresa_d = rbCvora;
                    }else{
                        novi[k].najveci_d = prethodni[j].najveci_d;
                        novi[k].adresa_d = rbCvora;
                    }
                    k++;//redni broj novog cvora i inkrementuje se svaki2x
                }
            }//upis cvorova datog nivoa u datoteku
            for(j = 0;j < brojCvorova[i];j++){
                printf("\n%d. visina \t-> \t%d | %d \t||\t %d | %d\n",i,novi[j].adresa_l,novi[j].najveci_l,novi[j].adresa_d,novi[j].najveci_d);
                fwrite(&novi[j],sizeof(TCvor),1,indSek);
            }
        }//for visine
        //zona_prekoracilac pocinje tamo gdje se zavrsila indeksna
        zona_prekoracilac = ftell(indSek);//ftell vraca trenutnu poziciju unutar aktivne
        slobodnih = zona_prekoracilac;
        korijen = zona_prekoracilac - sizeof(TCvor);//pocetak korijena u zoni indeksa koji je posljedni dodat
        rewind(indSek);
        fwrite(&zona_indeksa,sizeof(int),1,indSek);
        printf("\nZona indeksa: %d",zona_indeksa);
        fwrite(&zona_prekoracilac,sizeof(int),1,indSek);
        printf("\nZona prekor: %d",zona_prekoracilac);
        fwrite(&slobodnih,sizeof(int),1,indSek);
        printf("\nZona slobodnih: %d",slobodnih);
        fwrite(&h,sizeof(int),1,indSek);
        printf("\nVisina: %d",h);
        fwrite(&korijen,sizeof(int),1,indSek);
        printf("\nKorijen: %d", korijen);

        rewind(indSek);
        fread(&zona_indeksa,sizeof(int),1,indSek);
        printf("\nZona indeksa: %d",zona_indeksa);

        fclose(sekvenc);
        fclose(indSek);
}
//funkcija vraca adresu bloka sa datim kljucem
int pronadjiBlok(int ev_br){
    int zona_indeksa;//prva dodata u zglavlje
    int h;//visina stabla, cetvrta
    int korijen;//peti u zaglavlju
    int pomocna;//za preuzimanje adresa podredenih cvorova
    int zona_prekoracilac;
    int slobodnih;
    TCvor cvorko;
    indSek = fopen(aktivna, "rb+");
    rewind(indSek);
    fread(&zona_indeksa,sizeof(int),1,indSek);
    printf("\nZona indeksa: %d",zona_indeksa);
    //ucitavanje visine
    fread(&zona_prekoracilac,sizeof(int),1,indSek);
    printf("\nZona prekor: %d",zona_prekoracilac);
    fread(&slobodnih,sizeof(int),1,indSek);
    printf("\nZona slobodnih: %d",slobodnih);
    //fseek(indSek,3*sizeof(int),SEEK_SET);

    fread(&h,sizeof(int),1,indSek);
    printf("\nVisina: %d", h);

    fread(&korijen,sizeof(int),1,indSek);
    printf("\nKorijen: %d", korijen);
    fseek(indSek,korijen,SEEK_SET);
    fread(&cvorko,sizeof(TCvor),1,indSek);//ucitamo cijeli korijen
    //posto od njega pocinjemo pretragu
    for(h;h > 0;h--){
        if(ev_br <= cvorko.najveci_l)//ako je kljuc veci prelazmio u desnog podredjenog jer su tamo veci
            pomocna = cvorko.adresa_l;
        else//inace kljuc je manji i prelazimo u lijevo podstablo
            pomocna = cvorko.adresa_d;
        //adresa sadrz redni broj bloka u indeksnoj zoni
        //tj. njegov pocetak od pocetka indeksne
        fseek(indSek,zona_indeksa+pomocna*sizeof(TCvor),SEEK_SET);
        //ucitamo blok podredenog
        fread(&cvorko,sizeof(TCvor),1,indSek);
        //i ponavljamo algoritam
    }
    printf("\nAdresa bloka sa kljucem %d :  %d",ev_br,pomocna);
    return pomocna;
}
void trazenjeSlogUPrimarnoj(){
    Blok_primarne blok_prim;
    int ev_br;//kljuc sloga koji hocemo da nadjemo
    int adresa_bloka;//adresa bloka u kojoj je slog
    indSek = fopen(aktivna, "rb+");

     /////////////////////////////////////////////////////
     int zona_indeksa;//prva dodata u zglavlje
    int h;//visina stabla, cetvrta
    int korijen;//peti u zaglavlju
    int pomocna;//za preuzimanje adresa podredenih cvorova
    int zona_prekoracilac;
    int slobodnih;

    rewind(indSek);
    fread(&zona_indeksa,sizeof(int),1,indSek);
    printf("\nZona indeksa: %d",zona_indeksa);
    //ucitavanje visine
    fread(&zona_prekoracilac,sizeof(int),1,indSek);
    printf("\nZona prekor: %d",zona_prekoracilac);
    fread(&slobodnih,sizeof(int),1,indSek);
    printf("\nZona slobodnih: %d",slobodnih);
    //fseek(indSek,3*sizeof(int),SEEK_SET);

    fread(&h,sizeof(int),1,indSek);
    printf("\nVisina: %d", h);

    fread(&korijen,sizeof(int),1,indSek);
    printf("\nKorijen: %d", korijen);
//////////////////////////////////////////
    printf("\nUnesite evidencioni broj sloga koj zelite da nadjete: ");
    scanf("%d",&ev_br);
    //rewind(indSek);
    adresa_bloka = pronadjiBlok(ev_br);

    fseek(indSek,5*sizeof(int),SEEK_SET);
    //pozicioniranje na zeljenu blok primarne zone
    fseek(indSek,adresa_bloka*sizeof(Blok_primarne),SEEK_CUR);
    fread(&blok_prim,sizeof(Blok_primarne),1,indSek);
    int i;
    int ind = 0;
    for(i = 0;i < FBL; i++){
        if(blok_prim.blok.slogovi[i].evidencioni_broj == ev_br){
            printf("\nNadjen je slog u primarnoj zoni! Blok: %d, slog %d",adresa_bloka,i);
            printf("\n---------------------------------------------------");
            Slog slog = blok_prim.blok.slogovi[i];
            printf("\n\tEvidencioni broj: %d",slog.evidencioni_broj);
            printf("\n\tRegistarska oznaka: %s",slog.registarska_oznaka);
            printf("\n\tDatum i vrijeme: %s",slog.datum_vrijeme);
            printf("\n\tPolaziste: %s",slog.polaziste);
            printf("\n\tOdrediste: %s",slog.odrediste);
            printf("\n\tIznos usluge: %d\n",slog.iznos);
            ind = 1;
        }
    }
    if(ind == 0){
        printf("\nTrazeni slog nije u primarnoj zoni. Pogledacu u prekoraciocima.");
    }
    fclose(indSek);
}
void upisNovogSloga(){
    Slog upisani;
    Blok_primarne blok_prim;
    Blok_prekoracilac prekoracilac;
    int kljuc;
    int dan;
    int mjesec;
    int godina;
    int sat;
    int minut;

    upisani.status = AKTUELAN;
     do {
            printf("\nUnesite evidencioni broj (7 cifara): ");
            fflush(stdin);
            scanf("%d",&kljuc);

        } while (kljuc>9999999 || kljuc<1000000);

        upisani.evidencioni_broj = kljuc;

        do{
            printf("\nUnesite registarsku oznaku vozila (najvise 11 karaktera): \n");
            fflush(stdin);
            gets(upisani.registarska_oznaka);
        }while(strlen(upisani.registarska_oznaka)>11);


        do {
            printf("\nUnesite godinu: ");
            fflush(stdin);
            scanf("%d",&godina);
            if(godina<2000 || godina>2050) {
                printf("\nNeispravan format!\n");
                }
            } while(godina<2000 || godina>2050);

        do {
            printf("\nUnesite mjesec: ");
            fflush(stdin);
            scanf("%d", &mjesec);
            if(mjesec <1 || mjesec>12) {
                printf("\nNeispravan format!\n");
                }
            } while(mjesec<1 || mjesec>12);

        if(mjesec==1 || mjesec==3 || mjesec==5 || mjesec==7 || mjesec==8 || mjesec==10 || mjesec==12) {
            do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>31 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>31 || dan<1);

        } else if(mjesec==4 || mjesec==6 || mjesec==9 || mjesec==11) {
         do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>30 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>30 || dan<1);

        } else if(godina%4 == 0) {
             do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan> 29 || dan < 1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>29 || dan<1);

        } else {
         do {
                printf("\nUnesite dan: ");
                fflush(stdin);
                scanf("%d", &dan);
                if(dan>28 || dan<1) {
                    printf("\nNeispravan format!\n");
                }
            } while (dan>28 || dan<1);
        }


        do {
            printf("\nUnesite sat: ");
            fflush(stdin);
            scanf("%d", &sat);
            if(sat<0 || sat>23) {
                printf("\nNeispravan format!\n");
            }
        } while (sat<0 || sat>23);

        do {
            printf("\nUnesite minut: ");
            fflush(stdin);
            scanf("%d", &minut);
            if(minut < 0 || minut> 59) {
                printf("\nNeispravan format!\n");
            }
        } while(minut>59 || minut <0);

         sprintf(upisani.datum_vrijeme, "%d.%d.%d.  %d:%d", dan, mjesec, godina, sat, minut);


        printf("\nUnesi odrediste: ");
        fflush(stdin);
        gets(upisani.odrediste);

        printf("\nUnesi polaziste: ");
        fflush(stdin);
        gets(upisani.polaziste);


        do {
            printf("\nUnesi iznos: ");
            fflush(stdin);
            scanf("%d", &upisani.iznos);

            if(upisani.iznos > 1000000000)
                printf("Prekoracili ste maksimalni iznos usluge!");
        }   while(upisani.iznos>1000000000);

        indSek = fopen(aktivna, "rb+");
        int adresa_bloka = 0;//adresa bloka u koji cemo mozda smjestiti slog
        int offset_slobodni;//za zaglavlje datoteke
        int offset_prek;//offset za prekoracioca

        adresa_bloka = pronadjiBlok(upisani.evidencioni_broj);
        fseek(indSek,sizeof(int),SEEK_SET);
        fread(&offset_prek,sizeof(int),1,indSek);
        fread(&offset_slobodni,sizeof(int),1,indSek);

        fseek(indSek,5*sizeof(int)+adresa_bloka*sizeof(Blok_primarne),SEEK_SET);
        fread(&blok_prim,sizeof(Blok_primarne),1,indSek);

        int u_primarnoj = 0;//indikator gdje je smejsten novi slog
        int prekoracenje = 0;
        int i;
        for(i = 0;i < FBL;i++){
            if(blok_prim.blok.slogovi[i].evidencioni_broj == upisani.evidencioni_broj){
                printf("\nPostoji takav slog!");
                return;
            }//ako je blok nepopunjen
            if(blok_prim.blok.slogovi[i].status == NEAKTUELAN){
                printf("\nSlog je dodat u nepopunjeni blok.");
                blok_prim.blok.slogovi[i] = upisani;
                prekoracenje = 0;
                u_primarnoj = 1;
            }//akoo se trazenje slog zavrsili u bloku i ako to mjesto nije slobodno
            //bivseg najveceg potiskujemo u prekoracioce
            if(blok_prim.blok.slogovi[i].evidencioni_broj > upisani.evidencioni_broj){
                if(blok_prim.blok.slogovi[FBL-1].status ==AKTUELAN){
                    printf("\nNajveci slog odlazi u prekoracioce...");
                    prekoracilac.slog = blok_prim.blok.slogovi[FBL-1];
                    u_primarnoj = 1;
                    prekoracenje = 1;
                }else{
                    u_primarnoj = 1;
                    prekoracenje = 0;
                }//ima slobodnih mjesta u zoni podataka
                int j;//pomjeramo kljuceve vece od kljuca novog
                for(j = FBL - 1;j != i;j--){
                    blok_prim.blok.slogovi[j] = blok_prim.blok.slogovi[j - 1];
                }
                blok_prim.blok.slogovi[i] = upisani;
                //slogovi su pomjereni a novi je dodat
                break;
            }
        }
        //ako je upisan u primarnu
        if(u_primarnoj == 1){
            prekoracilac.slog = upisani;
            printf("\nSlog je dodat u primarnu!");
        }else{
            prekoracenje = 1;
            prekoracilac.slog = upisani;
            printf("\nNovoupisani ce u zonu prekoracenja!");
        }
        /*if(prekoracenje == 1){//ako  je doslo do prekoracenja
            if(blok_prim == -1){
                blok_prim = offset_slobodni;//ako nema prekoracilac u primarnom bloku
                prekoracilac.prekoracioci = -1;//prekoracilac ne pokazuje ni kog
                fseek(indSek,offset_slobodni,SEEK_SET);
                fwrite(&offset_prek,sizeof(Blok_prekoracilac),1,indSek);
                printf("\nOsnovan je lanac prekoracilaca!");
                u_primarnoj = 1;
                offset_slobodni += sizeof(Blok_prekoracilac);//offset slobodnih povecamamo za velicinu bloka prek
            }else{//ako vec ima lanac prekoracilaca u moramo ga produziti
                int adresa_tekuceg;//adrese potrebne za smjestanje u polje prekoracioca
                int adresa_preth;//i pokazuju na sljedeceg u lancu
                Blok_prekoracilac pomocni,prethodni;
                adresa_tekuceg = blok_prim.prekoracioci;
                while(1){
                    fseek(indSek,adresa_tekuceg,SEEK_SET);//pozicioniram se na pocetak zone prekoracenja
                    fread(&pomocni,sizeof(Blok_prekoracilac),1,indSek);
                    if(pomocni.slog.evidencioni_broj > prekoracilac.slog.evidencioni_broj){
                        //ako je onaj koji je ucitan iz lista prekoracilaca veci od prekoracioca

                    }
                }
            }
        }*/
        if(u_primarnoj == 1){
            fseek(indSek,5*sizeof(int)+adresa_bloka*sizeof(Blok_primarne),SEEK_SET);
            fwrite(&blok_prim,sizeof(Blok_primarne),1,indSek);
        }
        fclose(indSek);

}



