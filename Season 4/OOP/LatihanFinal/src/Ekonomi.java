
public class Ekonomi {

	protected String destinasi;
	protected String asal;
	protected double hargaDasar;
	
	public Ekonomi(String destinasi, String asal, double hargaDasar) {
		super();
		this.destinasi = destinasi;
		this.asal = asal;
		this.hargaDasar = hargaDasar;
	}

	public double getTotalBayar() {
		return hargaDasar * 1.11;
	}
	
	public String getDestinasi() {
		return destinasi;
	}

	public void setDestinasi(String destinasi) {
		this.destinasi = destinasi;
	}

	public String getAsal() {
		return asal;
	}

	public void setAsal(String asal) {
		this.asal = asal;
	}

	public double getHargaDasar() {
		return hargaDasar;
	}

	public void setHargaDasar(double hargaDasar) {
		this.hargaDasar = hargaDasar;
	}
	
	
	
}
