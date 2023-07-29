
public class Student {
	private String name;
	private String NIM;
	private double gpa;

	public Student(String name, String NIM, double gpa) {
		this.name = name;
		this.NIM = NIM;
		this.gpa = gpa;
	}
	
	public String getNIM() {
		return NIM;
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public String getName() {
		return name;
	}

	public double getGpa() {
		return gpa;
	}

	public void setGpa(double gpa) {
		if (gpa <  0) this.gpa = 0;
		else if (gpa > 4.0) this.gpa = 4.0;
		else this.gpa = gpa;
	}
	
	
	
	
}
