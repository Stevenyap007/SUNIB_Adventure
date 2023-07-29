import java.util.ArrayList;
import java.util.Scanner;

public class GSLCFIshing {
	private static ArrayList<String> fishList = new ArrayList<String>();
	private static ArrayList<Double> weightList = new ArrayList<Double>();
	private static int totalFish = 0;
	private static double totalWeight = 0.0;
	
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int choice = 1;
		do {
			try {
				choice = 1;
				System.out.println("Welcome to Bee Fishing Game");
				System.out.println("1. View Fish");
				System.out.println("2. Go Fishing");
				System.out.println("3. Exit");
				System.out.print("Choice: ");
				choice = scan.nextInt();
	            
	            switch (choice) {
	                case 1:
	                    viewFish();
	                    break;
	                case 2:
	                	goFishing();
	                    break;
	                case 3:
	                    System.out.println("Thanks for playing!");
	                    System.exit(0);
	            }
				
			}catch(Exception e) {
				System.out.println("Harap masukkan input angka!!!");
				choice = 0;
			}
			scan.nextLine();
			if(choice < 1 || choice > 3) {
				System.out.println("Pilih menu 1-3!!!");
				System.out.println();
			}
		}while (choice < 1 || choice > 3);
	scan.close();	
	}
	
	private static void viewFish() {
		System.out.println();
		Scanner scan = new Scanner(System.in);
	    if (totalFish == 0) {
	        System.out.println("Belum ada ikan masbro, silahkan mancing dulu");
	    } else {
	        System.out.println("Your Fish: ");
	        for (int i = 0; i < totalFish; i++) {
	            System.out.println(i+1+ ". " + fishList.get(i) + "\t\t" + weightList.get(i) + " kg");
	        }
	        System.out.println("Total fish: " + totalFish);
	        System.out.println("Total weight: " + totalWeight + " kg");
	    }
	    System.out.println("Press enter to continue! ");  
	    scan.nextLine();
	    main(null);
	    scan.close();
	}
	
	private static void goFishing() {
		System.out.println();
		Scanner scan = new Scanner(System.in);
        String[] fishNames = {"Bullhead", "Bass", "Mackerel", "Snapper", "Grouper"};
        int FishIndex = (int) (Math.random()*5);
        String Fish = (String)fishNames[FishIndex];
        double weight;
        boolean isSuperFish = Math.random()*100 < 10;
        System.out.println("Fishing ...");
        if (isSuperFish) {
            Fish = "Super " + Fish;
            weight = Math.round((Math.random() * 5 + 10)*100.0)/100.0;
            System.out.println("Woah, you got a SUPER Fish!");
            System.out.println(Fish + " ( " + weight + " kg )");
        } else {
            weight = Math.round((Math.random() * 4 + 1.0)*100.0)/100.0;
            System.out.println(Fish + " ( " + weight + " kg )");
        }
        fishList.add(Fish);
        weightList.add(weight);
        totalFish++;
        totalWeight += weight;
        System.out.println("Press enter to continue! ");  
        scan.nextLine();
        main(null);
        scan.close();
    }
}


