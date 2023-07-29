import java.util.Random;

public class Eksekutif extends Ekonomi implements PremiumLounge {
	
	private String pin;

	public Eksekutif(String destinasi, String asal, double hargaDasar) {
		super(destinasi, asal, hargaDasar);
		// TODO Auto-generated constructor stub
		pin = generatePin();
	}

	public String getPin() {
		return pin;
	}

	@Override
	public double getTotalBayar() {
		// TODO Auto-generated method stub
		return (hargaDasar + 150000) * 1.11;
	}

	@Override
	public String generatePin() {
		// TODO Auto-generated method stub
		String tempPin = "";
		String huruf = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
		String angka = "0123456789";
		
		Random rand = new Random();
		tempPin += huruf.charAt(rand.nextInt(26));
		tempPin += angka.charAt(rand.nextInt(10));
		tempPin += angka.charAt(rand.nextInt(10));
		tempPin += angka.charAt(rand.nextInt(10));
		tempPin += angka.charAt(rand.nextInt(10));
		tempPin += huruf.charAt(rand.nextInt(26));
		
		return tempPin;
	}
	
}
