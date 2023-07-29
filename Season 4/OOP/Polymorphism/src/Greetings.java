
public class Greetings {

	public void sayHello(String name) {
		System.out.println("Hello "+ name);
	}
	
	public void sayHello(String name, String gender) {
		String title = "mr";
		if (gender.equalsIgnoreCase("woman")) {
			title = "Mrs.";
		}
		System.out.println("Hello " + title +name);
	}
}
