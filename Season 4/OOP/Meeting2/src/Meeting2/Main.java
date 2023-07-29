package Meeting2;
import java.util.Iterator;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
        
        Integer semester = Integer.valueOf(4);
        String sem = semester.toString();
    
//        String jurusan;
//        do{
//            System.out.print("Massukan Jurusan[TI/SI/KA]: ");
//            jurusan = scan.nextLine();
//        }while(jurusan.equalsIgnoreCase("TI")==false && jurusan.equals("SI")==false && jurusan.equals("KA")==false);
//        System.out.println("Jurusan: " + jurusan);
        
        String name = "Steven";
        System.out.println("Length = " + name.length());
        System.out.println("Char at = " + name.charAt(3));
        System.out.println("Mr.".concat(name));
        System.out.println(name.substring(0,6));
        System.out.println(name.toLowerCase());
        System.out.println(name.toUpperCase());
        System.out.println(name.replace("e", "o"));
        System.out.println(name.replaceFirst("e", "o"));
        
        String address = " Jl. Kebon Jeruk ";
        System.out.println(address);
        System.out.println(address.trim());

        String text = "Steven,19,0812534689";
        String data[] = text.split(",");
        for (int i = 0; i < data.length; i++) {
			System.out.println(data[i]);
		}
      
        // contains, startWith, EndWith
        System.out.println(name.contains("v"));
        System.out.println(name.startsWith("v"));
        System.out.println(name.endsWith("v"));
        
        
//      0-5
//      dari 5-10.99999, ada berapa angaka
        for (int i = 0; i < 100; i++) {
			double x = Math.floor(Math.random()*6)+5;
			System.out.println(x);
		}
        
        
	}
}
