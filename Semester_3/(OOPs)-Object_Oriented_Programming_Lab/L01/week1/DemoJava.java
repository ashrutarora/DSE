package week1;
import java.util.Scanner;

public class DemoJava {

	public static void main(String[] args) {
		
		System.out.println("Hello User");
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter student details: ");
		
		System.out.println("Enter your name: ");
		String Sname = sc.nextLine();
		
		System.out.println("Enter RegNo: ");
		int regNo = sc.nextInt();
		
		System.out.println("Hi "+Sname);
		System.out.print("Your Registeration Number is "+regNo);
		

	}

}
