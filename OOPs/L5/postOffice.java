import java.util.Scanner;

class Parcel
{
	String cust_name;
	String parcel_id;
	double parcel_wt;
	
	Parcel (String name, String id, double weight)
	{
		cust_name = name;
		parcel_id = id;
		parcel_wt = weight;
	}
	double cal()
	{
		double charges;
		
		if (parcel_wt <= 0)
			charges = 0;
		
		else if (parcel_wt <= 2.0)
			charges = 32.50;
		
		else
			charges = 32.50 + (parcel_wt - 2.0)*10.5;
		
		return charges;
	}
	void show()
	{
		System.out.println("Customer Name : " +cust_name);
		System.out.println("Parcel Id : " +parcel_id);
		System.out.println("Parcel Weight : " +parcel_wt);
		System.out.println("Charges : " +cal());
	}
}

public class postOffice {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner (System.in);
		
		int n;
		
		System.out.println("Enter the number of parcels : ");
		n = sc.nextInt();
		
		Parcel[] p = new Parcel[n];
		
		System.out.println("Start entering the details : ");
		

		for (int i=0; i<n; i++)
		{
			String name, id;
			double parcel_wt;
			
			System.out.println("Enter Customer Name: ");
			name = sc.next();
			
			System.out.println("Enter Parcel ID: ");
			id = sc.next();
			
			System.out.println("Enter Parcel Weight: ");
			parcel_wt = sc.nextDouble();
			
			p[i] = new Parcel(name, id, parcel_wt);
			p[i].show();
			
			System.out.println();
		}

	}
	}
	