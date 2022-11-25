package week2;
import java.util.Scanner;

public class BitwiseAdd {

	public static void main(String[]args) {
		
		int x,y;

        Scanner n = new Scanner(System.in);

        System.out.println("Enter 1st number: ");
        int a = n.nextInt();

        System.out.println("Enter 2nd number: ");
        int b = n.nextInt();

        x = a;
        y = b;

        while(b!=0)
        {
            int btw = a & b;
            a = a ^ b;
            b = btw <<1;
        }
        System.out.println("Sum of 2 numbers "+x+ " and " +y+ " = "+a);
        
	}
		
}
