#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

#define MAX_ISIM 20

int main() {
    FILE* dosya = fopen("trafik_kodlari.txt", "r");
    if (!dosya) {
        printf("Dosya a��lamad�!\n");
        return 1;
    }

    int kod, sehirKodu;
    char sehirAdi[MAX_ISIM];
    int bulundu = 0;

    printf("Trafik kodunu girin: ");
    scanf("%d", &kod);

    while (fscanf(dosya, "%d %s", &sehirKodu, sehirAdi) == 2) {
        if (sehirKodu == kod) {
            printf("%s Do�u Karadeniz b�lgesinde yer al�r.\n", sehirAdi);
            bulundu = 1;
            break;
        }
    }
    fclose(dosya);

    if (!bulundu) {
        printf("Hatal� Kod Girdiniz\n");
    }
    return 0;
}
