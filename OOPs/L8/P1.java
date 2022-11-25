import java.util.Scanner;

class College{
	String College_Name;
}


class Student_Detail extends College{
	
	String name;
	int ID;

	void input() {
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter your Name: ");
		name = sc.next();
		
		System.out.println("Enter your ID: ");
		ID = sc.nextInt();
		
		System.out.println("Enter your College Name: ");
		College_Name = sc.next();
	}
	
	void display_details() {
		
		System.out.println("Name:  " + name);
		System.out.println("ID:  " + ID);
		System.out.println("College Name:  " + College_Name);	
	}
}


public class P1 {

	public static void main(String[] args) {
		
		Student_Detail deets = new Student_Detail(); 
		
		try {
		deets.input();
		deets.display_details();
		}
		catch(Exception e) {
			System.out.println("Invalid Input");
		}

	}

}
