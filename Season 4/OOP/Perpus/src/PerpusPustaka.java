
public abstract class PerpusPustaka {
	protected String judul;
	protected int tahunTerbit;
	  
	public PerpusPustaka(String judul, int tahunTerbit) {
		this.judul = judul;
		this.tahunTerbit = tahunTerbit;
	}
	  
	public abstract void tampilkanInformasi();
}
