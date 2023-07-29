package shape;

public class Circle {
	
	//attribute
	public double radius;
	public final static double PHI = 3.14;
	
	public Circle(double radius){
		// codingan disini akan dipanggil
		//ketika lingkaran di buat / malloc
		this.radius = radius;
	}
	
	//method
	public double getArea() {
		return PHI * radius * radius;
	}
	
	public double getPerimeter() {
		return 2 * PHI * radius;
	}
	
	
	
}
