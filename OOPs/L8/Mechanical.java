import java.util.Scanner;

class Vehicle{
	double HPower;
	int exhausts;
	
	void inputV() {
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the Horse Power: ");
		HPower = sc.nextDouble();
		
		System.out.print("Enter the number of Exhausts: ");
		exhausts = sc.nextInt();
	}
	
}

class Car extends Vehicle{
	String colour;
	String type;
	String company;
	String model;
	
	void inputC() {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the Colour of Car: ");
		colour = sc.next();
		
		System.out.print("Enter the Type of Car: ");
		type = sc.next();
		
		System.out.print("Enter the Company of Car: ");
		company = sc.next();
		
		System.out.print("Enter the Model of Car: ");
		model = sc.next();
	}
	
	void details() {
		
		System.out.println("Details:  ");
		
		System.out.println("Company :  " + company);
		System.out.println("Model:  " + model);
		System.out.println("Type:  " + type);
		System.out.println("Colour:  " + colour);
		System.out.println("Horse Power:  " + HPower);
		System.out.println("Exhausts:  " + exhausts);
		
		
	}

}



public class Mechanical {

	public static void main(String[] args) {
		
		try {
			Car car = new Car();
			car.inputV();
			car.inputC();
			car.details();
		}
		catch(Exception e) {
			System.out.println("Invalid Input");
		}
	}

}
