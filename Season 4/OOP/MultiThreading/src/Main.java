
public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Thread standupThread 
			= new Thread(new StandupReminder());
		Thread timeshowerThread
			= new Thread(new TimeShower());
		
		standupThread.start();
		timeshowerThread.start();
		
	}

}
