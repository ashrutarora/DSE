
import java.util.Scanner;

public class Swap {

	 public static void main(String[] args) {
	        
	        
		 Scanner n = new Scanner(System.in);

		 	System.out.println("Enter a string: ");
	        String a = n.nextLine();
	        
	        System.out.println("Enter int: ");
	        int b = n.nextInt();
	        

	        String c = Integer.toString(b);

			System.out.println("Before Swap");
			System.out.println("a = " + a);
			System.out.println("b = " + c);

			String temp = a;
	        a = c;
	        c = temp;

			System.out.println("After swap");
			System.out.println("a = " + a);
			System.out.println("b = " + c);
		}
}
