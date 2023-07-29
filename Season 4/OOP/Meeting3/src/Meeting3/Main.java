package Meeting3;

import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {
	
	public static int calculate(int x, int y ) 
			throws Exception
	{
		if(x < 0 || y < 0) {
			throw new IllegalArgumentException("parameter must be positive");
		}
		return x / y;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		int num;
		int div;
		int result;
		Scanner scan = new Scanner(System.in);
		
		try {
			System.out.println("Input yout number:");
			num = scan.nextInt();
			System.out.println("Devided by: ");
			div =scan.nextInt();
			result = calculate(num,div);
			System.out.println("Result: "+ result);
//		}catch(InputMismatchException e){
//			System.out.println("Your input must be numeric");
//			System.out.println("Message: "+ e.getMessage());
//			System.out.println("Cause:"+ e.getCause());
//		}catch(ArithmeticException e) {
//			System.out.println("Devided by 0 is not allowed");
//			System.out.println("Message: "+ e.getMessage());
//			System.out.println("Cause:"+ e.getCause());
		}catch(Exception e) {
			System.out.println("Message: "+ e.getMessage());
		}finally {
			System.out.println("");
		}
		
		
		
		
//		 **************ARRAY***************
		int[] score = new int[10];
		score[0] = 90;
		score[1] = 80;
		score[2] = 70;
		
		for (int x: score) {
			System.out.println(x);
		}
		int[] adjustedScore = (int[])score.clone();
		for (int i = 0; i < adjustedScore.length; i++) {
			adjustedScore[i] += 5;
			System.out.println("Before: " + score[i] + " Adj. Score: "+adjustedScore[i]);
		}
		

	}

}
