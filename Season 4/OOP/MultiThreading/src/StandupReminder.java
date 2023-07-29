
public class StandupReminder implements Runnable{

	@Override
	public void run() {
		// TODO Auto-generated method stub
		for (int i = 0; i < 3; i++) {
			System.out.println("Ayo berdiri udah 10 detik coy");
		
			try {
				Thread.sleep(10000);
			} catch (InterruptedException e) {
				// TODO Auto-generated catch block
	//			kalau ada yang kill thread ini
	//			maka code yg chatch akan dijalankan
				e.printStackTrace();
			}
		}
		
	}

}
