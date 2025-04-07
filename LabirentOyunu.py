def mesafe_hesaplama(x1, y1, x2, y2):
    return ((x2 - x1) ** 2 + (y2 - y1) ** 2) ** 0.5


def koordinat_al(mesaj):
    while True:
        try:
            x, y = map(int, input(mesaj).split())
            return x, y
        except ValueError:
            print("Hatalı giriş! Lütfen iki tam sayı giriniz (x y).")


def main():
    genislik = int(input("Labirentin genişliğini girin: "))
    yukseklik = int(input("Labirentin yüksekliğini girin: "))

    kisi_sayisi = int(input("Kaç kişi var?: "))
    kisiler = []
    for i in range(kisi_sayisi):
        kisiler.append(koordinat_al(f"Kişi {i + 1} koordinatları (x y): "))

    x_oyuncu, y_oyuncu = koordinat_al("Kendi konumunuzu girin (x y): ")

    print("\nKonumunuz:", (x_oyuncu, y_oyuncu))


    en_yakin = None
    en_uzak = None
    min_mesafe = float('inf')
    max_mesafe = float('-inf')

    for i, (x, y) in enumerate(kisiler):
        mesafe = mesafe_hesaplama(x_oyuncu, y_oyuncu, x, y)

        if mesafe < min_mesafe:
            min_mesafe = mesafe
            en_yakin = (x, y)

        if mesafe > max_mesafe:
            max_mesafe = mesafe
            en_uzak = (x, y)

    if en_yakin:
        print(f"En yakın kişi: {en_yakin} - {min_mesafe:.2f}")
    if en_uzak:
        print(f"En uzak kişi: {en_uzak} - {max_mesafe:.2f}")


if __name__ == "__main__":
    main()