import java.util.Scanner;

public class Rect {
   public static void main (String[] args)
   {
	   Scanner sc = new Scanner(System.in);

	   System.out.println("Enter the length of Rectangle:");
	   double length = sc.nextDouble();

	   System.out.println("Enter the breadth of Rectangle:");
	   double breadth = sc.nextDouble();
	   
	   double Area = length*breadth;
       double Circumf = 2*(length + breadth);

	   System.out.println("Area of Rectangle is: "+Area);
       System.out.println("Circumference of Rectangle is: "+Circumf);
       
   }
}