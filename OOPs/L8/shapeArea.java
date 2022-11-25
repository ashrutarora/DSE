import java.util.InputMismatchException;
import java.util.Scanner;

class Area{
	double height;
}

class triangle extends Area{
	double base;
	
	void areaOfTri(double height, double base) {
		
		System.out.println("The area of Triangle = "+ (base * height)/2);
	}
}

class rectangle extends Area{
	double width;
	
	void areaOfRect(double height, double width) {
		
		System.out.println("The area of Rectangle = "+ (height*width));	
	}
}


public class shapeArea {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		try {
			rectangle rect = new rectangle();
			triangle tri = new triangle();
			
			System.out.println("Enter the Height: ");
			double a = sc.nextDouble();
			
			System.out.println("Enter the Base of Triangle: ");
			double b = sc.nextDouble();
			
			System.out.println("Enter the Width of Rectangle: ");
			double c = sc.nextDouble();
			
			
			tri.areaOfTri(a, b); 
			rect.areaOfRect(a, c);
		}
		catch(Exception e) {
			System.out.println("Invalid Input");
		}
		

	}

}
