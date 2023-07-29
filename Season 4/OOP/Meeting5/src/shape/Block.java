package shape;


public class Block {
	private double length, width, height;

	public Block(double length, double width, double height){
		this.length = length;
		this.width = width;
		this.height = height;
	}
	
	public double getVolume(){
		return length * width * height;
	}
	
	public double getSurfaceArea(){
		return 2*(length*width + length*height + width*height);
	}
}
