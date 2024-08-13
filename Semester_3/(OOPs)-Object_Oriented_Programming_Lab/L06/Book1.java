/*1. Create Book class with fields-> name, id, price with a constructor and get methods
     for all fields. [hint: constructor will be Book(id, name, price), methods will be
     getID(), getName() and getPrice().] */



import java.util.Scanner;

class Book{
	
	String name;
	int id;
	double price;
	
	Book(int id, String name, double price){
		this.name = name;
		this.id = id;
		this.price = price;
	}
	
	void getID(){
		System.out.println("ID-> "+id);
	}
	
	void getName(){
		System.out.println("Name-> "+name);
	}
	
	void getPrice(){
		System.out.println("Price-> "+price);
	}
}


public class Book1 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner (System.in);
		
		System.out.println("Enter Name: ");
		String name = sc.nextLine();
		
		System.out.println("Enter ID: ");
		int id = sc.nextInt();
		
		System.out.println("Enter Price: ");
		double price = sc.nextDouble();
		

		Book d1 = new Book(id, name, price);
		
		d1.getName();
		d1.getID();
		d1.getPrice();
		
		
	}

}
