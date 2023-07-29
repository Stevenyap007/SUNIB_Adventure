
public class MountainBike extends Bicycle {
	private int seatHeight;
	
	public MountainBike(int gear, int speed, int seatHeight) {
		super(gear, speed);
		this.setSeatHeight(seatHeight);
	}
	
	public void speedUp() { //overriding
		this.speed += 15;
	}

	public int getSeatHeight() {
		return seatHeight;
	}

	public void setSeatHeight(int seatHeight) {
		this.seatHeight = seatHeight;
	}
	
	
}
