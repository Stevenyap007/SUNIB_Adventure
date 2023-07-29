
public class Main {

	//reuse function, typecasting, compile error level reminder
	
	public <E> void print(E array[]) {
		for (int i = 0; i < array.length; i++) {
			System.out.println(array[i]);
		}
	}
	
	
	public Main() {
		String cities[] = {"Jakarta","Malang","Bandung"};
		Integer income[]= {100000,900000,700000};
		
		this.<String>print(cities);
		this.<Integer>print(income);
		
		
		
		
//		GenericStack<String> mhs = new GenericStack<>();
//		mhs.push("Abdul");
//		mhs.push("Richard");
//		mhs.push("Andre");
//		mhs.push("Jonathan");
//		String mhsPop1 = mhs.pop();
//		String mhsPop2 = mhs.pop();
//		System.out.println(mhsPop1 + " & " + mhsPop2 + " just removed");
//		mhs.print();
		GenericStack<Integer> mhs = new GenericStack<>();
		mhs.push(100);
		mhs.push(90);
		mhs.push(95);
		mhs.push(98);
		int mhsPop1 = mhs.pop();
		int mhsPop2 = mhs.pop();
		System.out.println(mhsPop1 + " & " + mhsPop2 + " just removed");
		mhs.print();
		
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		new Main();
		
	}

}
