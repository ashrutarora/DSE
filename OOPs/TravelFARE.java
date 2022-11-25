import java.util.Scanner;

abstract class CarPlans{
	
	abstract void planCost();
	
}

class BMW extends CarPlans{
	
	String model;
	double price;
	int InitialDistance;
	int TotalTravelled;
	
	BMW(String model, int InitialDistance, int TotalTravelled){
		
		this.model =model;
		this.InitialDistance = InitialDistance;
		this.TotalTravelled  = TotalTravelled;
	}
	
	void planCost() {
		
		price = 20* (TotalTravelled - InitialDistance);
		
		System.out.println("Travel Fare for BMW = " + price);
	}
	
}

class Audi extends CarPlans{
	
	String model;
	double price;
	int InitialDistance;
	int TotalTravelled;
	
	Audi(String model, int InitialDistance, int TotalTravelled){
		
		this.model =model;
		this.InitialDistance = InitialDistance;
		this.TotalTravelled  = TotalTravelled;
	}
	
	void planCost() {
		
		price = 20* (TotalTravelled - InitialDistance);
		
		System.out.println("Travel Fare for Audi = " + price);
	}
	
}

class Benz extends CarPlans{
	
	String model;
	double price;
	int InitialDistance;
	int TotalTravelled;
	
	Benz(String model, int InitialDistance, int TotalTravelled){
		
		this.model =model;
		this.InitialDistance = InitialDistance;
		this.TotalTravelled  = TotalTravelled;
	}

	
	void planCost() {
		
		price = 20* (TotalTravelled - InitialDistance);
		
		System.out.println("Travel Fare for Benz = " + price);
	}
}





public class TravelFARE {

	public static void main(String[] args) throws IndexOutOfBounds {
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter Model: ");
		String model = sc.next();
		
		System.out.println("Enter Initial Distance : ");
		int InitialDistance = sc.nextInt();

		System.out.println("Enter Total Distance Travelled: ");
		int TotalTravelled = sc.nextInt();

		BMW bmw = new BMW(model, InitialDistance, TotalTravelled);
		Audi audi = new Audi(model, InitialDistance, TotalTravelled);
		Benz benz = new Benz(model, InitialDistance, TotalTravelled);
		
		
		System.out.println("Choose from the Following : ");
		System.out.println();
		
		try {
		System.out.println("1.BMW");
		System.out.println("2.Audi");
		System.out.println("3.Benz");
		int choice = sc.nextInt();
		
		switch(choice) {
		
		case 1:
			bmw.planCost();
			break;
			
		case 2:
			audi.planCost();
			break;
			
		case 3:
			benz.planCost();
			break;	
			
		default:
			System.out.println("Invalid Choice");
			}
		
		}catch(Exception e) {
			{
				System.out.println(e);
			}
		}	
	}
		
}

