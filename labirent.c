#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define _CRT_SECURE_NO_WARNINGS

typedef struct {
	int x, y;
} Kisi;

double oklidMesafesi(Kisi a, Kisi b) {
	return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

double manhattanMesafesi(Kisi a, Kisi b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {

	int labirentYukseklik;
	int labirentGenislik;
	int kisiSayisi;
	int mesafeTuru;
	int tespitMesafesi;

	printf("Labirentin yuksekligini giriniz: ");
	scanf_s("%d", &labirentYukseklik);
	printf("Labirentin genisligini giriniz: ");
	scanf_s("%d", &labirentGenislik);


	printf("Labirentteki kisi sayisini giriniz: ");
	scanf_s("%d", &kisiSayisi);

	Kisi* kisiler = (Kisi*)malloc(kisiSayisi * sizeof(Kisi));

	printf("Kisilerin koordinatlarini giriniz: \n");

	for (int i = 0;i < kisiSayisi;i++) {
		printf("%d. kisinin (x,y) koordinatlarini giriniz: ", i + 1);
		scanf_s("%d %d", &kisiler[i].x, &kisiler[i].y);
		
	}

	Kisi kendi;
	printf("Kendi konumunuzun koordinatlarini giriniz: \n");
	printf("(x , y): ");
	scanf_s("%d %d", &kendi.x, &kendi.y);
	
	printf("En fazla ne kadar uzaktaki kisiyi tespit etmek istersiniz:");
	scanf_s("%d", &tespitMesafesi);
	
	
	printf("Mesafe turunu seciniz: (1: Oklid 2: Manhattan) \n");
	scanf_s("%d", &mesafeTuru);

	double (*mesafeHesapla)(Kisi, Kisi)=(mesafeTuru == 1) ? oklidMesafesi : manhattanMesafesi;

	double minMesafe = 1e9, maxMesafe = -1;
	Kisi enYakin, enUzak;

	printf("\nSizin bulundugunuz nokta: (%d , %d)\n", kendi.x, kendi.y);
	printf("Yakinizdaki kisiler (%d mesafe icerisinde olanlar):\n", tespitMesafesi);

	for (int i = 0;i < kisiSayisi;i++) {
		double mesafe = mesafeHesapla(kendi, kisiler[i]);

		if (mesafe <= tespitMesafesi) {
			printf("%d. kisi: (%d, %d) - mesafe: %.2lf\n", i + 1, kisiler[i].x, kisiler[i].y, mesafe);

		}
		else if (mesafe < minMesafe) {
			minMesafe = mesafe;
			enYakin = kisiler[i];
			printf("En yakin kisi: (%d, %d) - mesafe: %.2lf\n", kisiler[i].x, kisiler[i].y,minMesafe);
		}
		else {
			maxMesafe = mesafe;
			enUzak = kisiler[i];
			printf("En uzak kisi: (%d, %d) - mesafe: %.2lf\n", kisiler[i].x, kisiler[i].y, maxMesafe);
		}
	}



	return 0;
}