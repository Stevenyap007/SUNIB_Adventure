package latihan;
import java.util.Scanner;
import java.util.Vector;

public class BinusMain {
	
	Vector<BasicBouquet> cart= new Vector<>();
	Scanner scan = new Scanner(System.in);
	
	public void menu1() {
		System.out.printf("%2s %-15s %-15s %s", "No", "Flower Type", "Bouquet Type", "Message");
		for (int i = 0; i < cart.size(); i++) {
			String bouquetType ="", message="";
			if(cart.get(i).getClass() == BasicBouquet.class) {
				bouquetType = "Basic";
				message = "(blank)";
			}else if(cart.get(i).getClass() == PremiumBouquet.class) {
				bouquetType = "Premium";
				message = ((PremiumBouquet) cart.get(i)).getMessage();
			}
			System.out.printf("%2d %-15s %-15s %s", i+1, cart.get(i).getFlower(), bouquetType, message);
		}
	}
	
	public void menu2() {
		String bouquetType, flowerType, message;
		int price = 0;
		System.out.print("Input bouquet type [basic/premium]: ");
		bouquetType = scan.nextLine();
		
		System.out.print("Input flower type [rose/daisy/tulip]: ");
		flowerType  = scan.nextLine();
		
		if(flowerType.equals("rose")) {
			price += 150000;
		}else if(flowerType.equals("daisy")) {
			price += 200000;
		}else if(flowerType.equals("tulip")) {
			price += 250000;
		}
		
		if(bouquetType.equals("basic")) {
//			BasicBouquet temp = new BasicBouquet(flowerType, price);
//			cart.add(temp);
			
			//anonymous object
			cart.add(new BasicBouquet(flowerType, price));
		}else if(bouquetType.equals("premium")) {
			System.out.println("Input your message [5..100]: ");
			message = scan.nextLine();
			price += (message.replace(" ","").length() * 500);
			
			cart.add(new PremiumBouquet(flowerType, price, message));
		}
		
	}
	
	public void menu() {
		int choice;
		do {
		System.out.println("Binus Bouquet Shop");
		System.out.println("===================");
		System.out.println("1. View Item");
		System.out.println("2. Add Bouquet");
		System.out.println("3. Exit");
		System.out.println("Input your choice: ");
		choice = scan.nextInt();
		scan.nextLine();
		
		if(choice == 1) {
			menu1();
		}else if(choice == 2) {
			menu2();
		}else if(choice == 3) {
			
		}
		
		
		
		}while(choice != 3);
	}
	
	public BinusMain() {
		// code here
		menu();
		
	}

	public  static void main(String[]args) {
		new BinusMain();
	}
}
