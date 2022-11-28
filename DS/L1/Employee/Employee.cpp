#include <iostream>
using namespace std;

class EMPLOYEE
{
	int Employee_Number;
	char Employee_Name[30];
	float Basic, DA, IT, Net_Sal, Gross_salary;
	
	public:
	
	void read_emp_details(int i)
	{
		cout << "\n\nEnter Employee "<<i<< " Details\n";
		
		cout << "Enter Employee Number: ";
		cin >> Employee_Number;
		
		cout << "Enter Employee Name: ";
		cin >> Employee_Name;
		
		cout << "Enter Basic Salary: ";
		cin >> Basic;
	}
	
	void find_net_gross()
	{
		DA = Basic * 0.12;
		Gross_salary = Basic + DA;
		IT = Gross_salary * 0.18;
		Net_Sal = Gross_salary - IT;
		
	}
	
	void display_emp_details(int i)
	{
		cout<<"\n\n Employee "<<i<<" Details \n";
		
		cout << "\n\nEmployee Number: "<< Employee_Number;
		cout << "\nEmployee Name: "<< Employee_Name;
		cout << "\nNet Salary: "<< Net_Sal;
		cout << "\nGross Salary: "<< Gross_salary;	
	}
};

int main()
{
	EMPLOYEE emp[100];
	int n, i;
	
	cout << "\nPlease enter the number of Employees: ";
	cin >> n;
	
	
	for(i=0 ; i < n; i++)
	{
		emp[i].read_emp_details(i+1);
	}
		
	for(i=0 ; i < n; i++)
	{
		emp[i].find_net_gross();
	}
	
	
	for(i=0 ; i < n; i++)
	{
		emp[i].display_emp_details(i+1);
	}
	
	return 0;
}





