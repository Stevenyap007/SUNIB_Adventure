import java.util.Scanner;
import java.util.Vector;

public class Main {
	Scanner scan;
	Vector<Ekonomi> penerbangan;
	
	public void menu1() {
		String tipe;
		String asal;
		String tujuan;
		double harga;
		
		do {
			System.out.println("Masukkan type penerbangan [ekonomi|eksekutif]: ");
			tipe = scan.nextLine();
		} while (!tipe.equals("ekonomi") && !tipe.equals("eksekutif"));
		
		do {
			System.out.println("Masukkan kode bandara asal [3 huruf, capital]: ");
			asal = scan.nextLine();
		} while (asal.length() != 3 || !asal.equals(asal.toUpperCase()));
		
		do {
			System.out.println("Masukkan kode bandara tujuan [3 huruf, capital]: ");
			tujuan = scan.nextLine();
		} while (tujuan.length() != 3 || !tujuan.equals(tujuan.toUpperCase()) || asal.equals(tujuan));
		
		do {
			System.out.println("Masukkan harga dasar [kelipatan 10rb]: ");
			harga = scan.nextDouble();
			scan.nextLine();
		} while (harga % 10000 != 0);
		
		if(tipe.equals("ekonomi")) {
			penerbangan.add(new Ekonomi(tujuan, asal, harga));
		}else if (tipe.equals("eksekutif")) {
			penerbangan.add(new Eksekutif(tujuan, asal, harga));
		}
		
		System.out.println("Penerbangan berhasil didaftarkan.");
		scan.nextLine();
	}

	public void menu2() {
		System.out.printf("%5s | %-4s | %-15s  | %s \n","Penerbangan", "Total Harga", "Tipe", "PIN Lounge");
		
		for (int i = 0; i < penerbangan.size(); i++) {
			String tipe = "Ekonomi";
			String pin = "-";
			
			if(penerbangan.get(i).getClass() == Eksekutif.class) {
				tipe = "Eksekutif";
				pin = ((Eksekutif)penerbangan.get(i)).getPin();
			}
			
			System.out.printf("%s - %-5s | %.0f IDR  | %-16s | %s\n ",penerbangan.get(i).getAsal(), penerbangan.get(i).getDestinasi(), penerbangan.get(i).getTotalFee(), tipe, pin);
		}
		scan.nextLine();
	}
	
	public void menu() {
		int input;
		
		do {
			System.out.println("1. Tambah penerbngan");
			System.out.println("2. Lihat penerbngan");
			System.out.println("3. Keluar");
			System.out.println("Input: ");
			input = scan.nextInt();
			scan.nextLine();
			if(input == 1) {
				menu1();
			}else if(input == 2) {
				menu2();
			}else if(input == 3) {
				
			}
		}while(input !=3);
	}
	
	
	
	public Main() {
		scan = new Scanner(System.in);
		penerbangan = new Vector<Ekonomi>();
		menu();
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}