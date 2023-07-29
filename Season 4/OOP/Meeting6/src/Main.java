
public class Main {
	public static void main(String[] args){
		Student albert =
				new Student("Albert Wijaya","2601912934",3.00);
		albert.setGpa(5.00);
		System.out.println("Name : " +  albert.getName());
		System.out.println("NIM : " + albert.getNIM());
		System.out.println("GPA : " + albert.getGpa());
		
		Bicycle bicycle = new Bicycle(4,30);
		MountainBike mountainBike = new MountainBike(6,30,20);
		bicycle.speedUp();
		mountainBike.speedUp();
		System.out.println("Bike: " + bicycle.getSpeed());
		System.out.println("Mountain Bike: " + mountainBike.getSpeed());
	}
}
