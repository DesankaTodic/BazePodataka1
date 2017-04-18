#include <stdio.h>
#include <stdlib.h>
#include "opcije.h"


int main()
{
    int a;

    do {
        printf("\n\n===============MENI==============\n\n");
        printf("1. Formiranje prazne datoteke\n");
        printf("2. Izbor aktivne datoteke zadavanjem imena\n");
        printf("3. Prikaz naziva aktivne datoteke\n");
        printf("4. Formiranje serijske datoteke\n");
        printf("5. Formiranje sekvencijalne datoteke\n");
        printf("6. Formiranje indeks-sekvencijalne datoteke\n");
        printf("7. Upis novog sloga\n");
        printf("8. Trazenje proizvoljnog sloga u aktivnoj datoteci\n");
        printf("9. Reorganizacija aktivne datoteke\n");
        printf("10. Prikaz datoteka\n");
        printf("11. Kraj\n");

        printf("\n=================================\n");
        printf("Unesite vas izbor: ");
        scanf("%d", &a);

        switch(a) {
        case 1:
            formiranjePrazne();
            break;

        case 2:
           izborAktivne();
           break;

        case 3:
            prikazAktivne();
            break;

        case 4:
            formiranjeSerijske();
            break;

        case 5:
            formiranjeSekvencijalne();
            break;


        case 6:
            formiranjeIndeksSekvencijalne();
            break;

        case 7:
            upisNovogSloga();
            break;

        case 8:
            trazenjeSlogUPrimarnoj();
            break;


        case 10:
            printf("1. Prikaz serijske\n");
            printf("2. Prikaz sekvencijalne\n");

            int b;
            printf("Unesite vas izbor: ");
            scanf("%d", &b);
            switch(b) {
            case 1:
                citajSerijsku();
                break;

           case 2:
                citajSekvencijalnu();
                break;


            }
            break;
        }

    }while(a>0 && a<12);
    return 0;
}
