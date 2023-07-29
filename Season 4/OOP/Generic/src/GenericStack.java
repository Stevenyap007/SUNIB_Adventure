import java.util.ArrayList;

public class GenericStack<E> {
	
	ArrayList<E> list = new ArrayList<>();
	
	public void push(E obj) {
		list.add(obj);
	}
	
	public E pop() {
		int lastIndex = list.size()-1;
		E poppedObject = list.get(lastIndex);
		list.remove(lastIndex);
		return poppedObject;
	}
	
	public void print() {
		for (int i = 0; i < list.size(); i++) {
			System.out.println(list.get(i));
		}
	}
}
