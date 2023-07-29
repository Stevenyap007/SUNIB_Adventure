
public class Main {
	
	
	
	public Main() {
		Zombie z = new ConedZombie(10, 10, 10, 1);
		z.walk();
		((ConedZombie)z).defense();
		((ConedZombie)z).sundul();
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
	}

}
