package week2;
import java.util.Scanner;

public class Conversions {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);

        System.out.println("Enter int: ");
        int a = sc.nextInt();

        System.out.println("Enter double: ");
        double b = sc.nextDouble();

        System.out.println("Enter char: ");
        char c = sc.next().charAt(0);
		

		byte p = (byte) a;
		System.out.println("int to byte value = "+p);

        int q = c - '0';
        System.out.println("char to int value = "+q);

        byte r = (byte) b;
        System.out.println("double to byte value = "+r);

        int s = (int) a;
        System.out.println("double to int value = "+s);

		
		
	}

}
