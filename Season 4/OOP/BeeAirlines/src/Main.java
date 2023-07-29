import java.util.Scanner;
import java.util.Vector;

public class Main {
	
	Scanner scan;
	Vector<Ekonomi> Penerbangan;
	
	public void menu2() {
		System.out.println("Penerbangan | Total Harga | Tipe | PIN Lounge ");
		
		for (int i = 0; i < Penerbangan.size(); i++) {
			String tipe = "Ekonomi";
			String pin = "-";
			if(Penerbangan.get(i).getClass() == Eksekutif.class) {
				tipe = "Eksekutif";
				pin = ((Eksekutif)Penerbangan.get(i)).getPin();
			}
			System.out.printf("%s - %s | %.0f IDR | %s | %s\n ",
					Penerbangan.get(i).getAsal(),
					Penerbangan.get(i).getDestinasi(),
					Penerbangan.get(i).getTotalBayar(),
					tipe,pin);
			scan.nextLine();
		}
		
	}
	
	public void menu1() {
		String tipe;
		String asal;
		String tujuan;
		double harga;
		
		do {
			System.out.println("Masukkan tipe penerbangan(ekonomi/eksekutif)");
			tipe = scan.nextLine();
		}while(!tipe.equals("ekonomi")&&!tipe.equals("eksekutif"));
		
		do {
			System.out.println("Masukkan kode bandara asal(3 huruf dan kapital)");
			asal = scan.nextLine();
		}while(asal.length() != 3 || asal != asal.toUpperCase());
		
		do {
			System.out.println("Masukkan kode bandara tujuan(3 huruf dan kapital)");
			tujuan = scan.nextLine();
		}while(asal.equals(tujuan)|| tujuan.length() != 3 || !tujuan.equals(tujuan.toUpperCase()));
		
		do {
			System.out.println("Masukkan harga dasar(kelipatan 10k)");
			harga = scan.nextDouble();	
			scan.nextLine();
		}while(harga % 10000 != 0);
		
		if(tipe.equals("ekonomi")) {
			Penerbangan.add(new Ekonomi(tujuan, asal, harga));
		}else if(tipe.equals("eksekutif")) {
			Penerbangan.add(new Eksekutif(tujuan, asal, harga));
		}
		
		System.out.println("Penerbangan berhasil ditambah...");
		scan.nextLine();
	}

	public void menu() {
		int input;
		
		do {
		System.out.println("1. Tambah Penerbangan");
		System.out.println("2. Lihat Penerbangan");
		System.out.println("2. Keluar");
		input = scan.nextInt();
		scan.nextLine();
		if(input == 1) {
			menu1();	
		}else if(input == 2) {
			menu2();
		}else if(input == 3) {
			
		}
		
		}while(input != 3);
		
		
	}
	
	public Main() {
		scan = new Scanner(System.in);
		Penerbangan = new Vector<Ekonomi>();
		
		menu();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		new Main();
		
	}

}
