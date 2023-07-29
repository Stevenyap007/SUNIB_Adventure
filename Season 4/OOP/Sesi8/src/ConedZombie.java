
public class ConedZombie  extends Zombie implements Helm{

	public ConedZombie(int hp, int dmg, int x, int y) {
		super(hp, dmg, x, y);
		// TODO Auto-generated constructor stub
	}

	@Override
	public void defense() {
		// TODO Auto-generated method stub
		int before = hp;
		hp +=10;
		System.out.println("defense! HP from " + before + " to " + hp );
	}

	@Override
	public void sundul() {
		// TODO Auto-generated method stub
		int before = y;
		y++;
		System.out.println("Sundul! Y from " + before + " to " + y );
	}
	
}
