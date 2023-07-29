
public abstract class Enemy {

	protected int hp;
	protected int dmg;
	protected int x;
	protected int y;
	
	public Enemy(int hp, int dmg, int x, int y) {
		this.hp = hp;
		this.dmg = dmg;
		this.x = x;
		this.y = y;
	}
	
	public abstract void walk();
}
