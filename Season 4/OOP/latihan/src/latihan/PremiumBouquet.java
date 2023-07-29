package latihan;

public class PremiumBouquet extends BasicBouquet {
	
	private String message;
	
	public PremiumBouquet(String flower, int price, String message) {
		super(flower,price);
		this.message = message;
	}

	public String getMessage() {
		return message;
	}

	public void setMessage(String message) {
		this.message = message;
	}

	
	
}
