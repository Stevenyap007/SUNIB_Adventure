import shape.Block;
import shape.Circle;
public class Main {

	public static void main(String[] args) {
		// ToDO Auto-generated method stub
		Circle myFirstCircle = new Circle(14);
		Circle secondCircle = new Circle(7);
		System.out.println(myFirstCircle.radius);
		System.out.println(myFirstCircle.getArea());
		System.out.println(myFirstCircle.getPerimeter());
		System.out.println("");
		
		System.out.println(secondCircle.radius);
		System.out.println(secondCircle.getArea());
		System.out.println(secondCircle.getPerimeter());
		System.out.println("");
		
		Block FirstBlock = new Block(5,5,5);
		System.out.println(FirstBlock.getVolume());
		System.out.println(FirstBlock.getSurfaceArea());
	}
}
