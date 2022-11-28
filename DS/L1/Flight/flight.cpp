#include <iostream>
using namespace std;

class flight
{
	int flight_number;
	 string Destination;
	float Distance, Fuel;
	
	float calculate_fuel()
	{
		float fuel = 13.2;
		
		if ( Distance <= 1000 )
		{
			fuel = 500;
		}
		else if( Distance > 1000 && Distance <=2000)
		{
			fuel = 1100;
		}
		else
		fuel = 2200;
		return fuel;
	}
	
	public:
		
		flight(){
			cout << "Flight Information\n";
			information_entry();
		}
		
		flight(int num, char destination, float distance)
		{
			flight_number = num;
			Destination = destination;
			Distance = distance;
			Fuel = calculate_fuel();
		}
		
		void information_entry()
		{
	        cout << "Enter Flight number: " ;
	        cin >> flight_number;
	        
	        cout << "Enter Destination: " ;
	        cin >> Destination;
	        
	        cout << "Enter Distance: " ;
	        cin >>  Distance ;
	        
	        Fuel = calculate_fuel();
	        
	        cout << "Fuel : " << Fuel;
		}
		
		void display_info() 
		{
		cout << "\nFlight number: " << flight_number;
        cout << "\nDestination: " << Destination;
        cout << "\nDistance: " << Distance;
        cout << "\nFuel : " << Fuel;             	
		}

};


int main()
{
	flight desti;
	cout << "\n\n";
    desti.display_info();
   
   return 0;	
}
