package labirentoyun;
import java.util.Scanner;


class Kisi{    //labirent içindeki kişilerin konumlarını ve mesafelerini saklamak için
	int x,y;
	double uzaklık;
	
	Kisi(int x,int y){
		this.x=x;
		this.y=y;
	}
}

public class labirent {
	public static double oklidmesafe(int x1, int y1, int x2, int y2) {
        return Math.sqrt(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2));
    }
	
	public static double manhattanmesafe(int x1,int y1,int x2,int y2) {
		return Math.abs(x2-x1)+Math.abs(y2-y1);
		
	}
	public static void main(String[]args) {
		Scanner scanner =new Scanner(System.in);
		
		System.out.println("Labirent genişliği :");
		int genislik=scanner.nextInt();
		System.out.println("Labirent yüksekliği");
		int yukseklık=scanner.nextInt();
		
		System.out.println("Labirentte kaç kişi var ?");
		int kisisys=scanner.nextInt();
		Kisi[]kisiler=new Kisi[kisisys];
		
		for (int i = 0; i < kisisys; i++) {    //Kullanıcı yanlış giriş yaparsa tekrar giriş yapmasını isteyecek
		    boolean dogruGiris = false;
		    while (!dogruGiris) {
		        System.out.print("Kişi " + (i + 1) + " koordinatları (x y): ");
		        
        if (scanner.hasNextInt()) {     //sayı girilip girilmedğini kontrol et
            int x = scanner.nextInt();
        if (scanner.hasNextInt()) {
		    int y = scanner.nextInt();
		    kisiler[i] = new Kisi(x, y);
		    dogruGiris = true; // Başarılı giriş
		    } 
	    else  {
            System.out.println("Hatalı giriş! Lütfen iki tam sayı girin.");
            scanner.nextLine(); // Hatalı girişi temizle
		      }
		        } 
		    }
		}

		
		System.out.println("Kendi konumunuz (x,y): ");
		int x=scanner.nextInt();
		int y=scanner.nextInt();
		
		System.out.println("Tespit mesafesi: ");
		double mesafelmt=scanner.nextDouble();
		
		System.out.println("Uzaklık metodu seçiniz (1: Öklid , 2: Manhattan): ");
		int secim=scanner.nextInt();
		
		Kisi enyakin=null, enuzak=null;
		System.out.println("\nEtrafınızdaki kişiler: ");
		
		for (int i = 0; i < kisiler.length; i++) {
		    Kisi kisi = kisiler[i];
		    double mesafe = (secim == 1) ? oklidmesafe(x, y, kisi.x, kisi.y) : manhattanmesafe(x, y, kisi.x, kisi.y);
		    kisi.uzaklık = mesafe;

		    if (mesafe <= mesafelmt) {
		        System.out.println("Kişi " + (i + 1) + " (" + kisi.x + ", " + kisi.y + ") - Uzaklık: " + mesafe);
		    }
			
			if (enyakin == null || kisi.uzaklık < enyakin.uzaklık) {
                enyakin = kisi;
            }
            if (enuzak == null || kisi.uzaklık > enuzak.uzaklık) {
                enuzak = kisi;
            }
        }
        
        System.out.println("En yakın kişi: (" + enyakin.x + ", " + enyakin.y + ") - Uzaklık: " + enyakin.uzaklık);
        System.out.println("En uzak kişi: (" + enuzak.x + ", " + enuzak.y + ") - Uzaklık: " + enuzak.uzaklık);
        
        scanner.close();
      }

	}

