
public class Zombie extends Enemy{

	public Zombie(int hp, int dmg, int x,int y) {
		super(hp, dmg, x, y);
		// TODO Auto-generated constructor stub
		
	}

	int positionX = 100;
	
	@Override
	public void walk() {
		int before = x;
		x--;
		System.out.println("Zombie walk from "+ before + " to " + x);
		//rendering gambar zombie bisa lagi jalan
	}
}
