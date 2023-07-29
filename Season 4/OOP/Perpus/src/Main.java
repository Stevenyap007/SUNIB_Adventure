
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Buku buku = new Buku("naruto", 2002, "Hokage");
	    buku.tampilkanInformasi();
	    
	    System.out.println();
	    buku.pinjamPustaka();
	    buku.tampilkanInformasi();

	    System.out.println();
	    buku.kembalikanPustaka();
	    buku.tampilkanInformasi();
		
	}

}
