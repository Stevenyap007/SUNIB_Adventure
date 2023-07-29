
public class Buku extends PerpusPustaka implements Pinjaman  {
	private String penulis;
	private boolean ready;

	public Buku(String judul, int tahunTerbit, String penulis) {
		super(judul, tahunTerbit);
		// TODO Auto-generated constructor stub
		this.penulis = penulis;
	    this.ready = true;
	}
	
	@Override
	public void tampilkanInformasi() {
		// TODO Auto-generated method stub
		System.out.println("Judul: " + judul);
	    System.out.println("Penulis: " + penulis);
	    System.out.println("Tahun Terbit: " + tahunTerbit);
	    System.out.println("Status Tersedia: " + (ready ? "Tersedia" : "Tidak tersedia"));
	}

	@Override
	public void pinjamPustaka() {
		// TODO Auto-generated method stub
		if (ready) {
	         ready = false;
	         System.out.println("Buku '" + judul + "' telah dipinjam.");
	      } else {
	         System.out.println("Buku '" + judul + "' sedang tidak tersedia.");
	      }
	}
	
	@Override
	public void kembalikanPustaka() {
		// TODO Auto-generated method stub
		ready = true;
	    System.out.println("Buku '" + judul + "' telah dikembalikan.");
	}
}
