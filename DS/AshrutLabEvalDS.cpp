#include <iostream>
using namespace std;

class Node{
	
	public: 
	
		char Name;
		int Emp_id;
		int Age;
		double Emp_Salary;
		int Emp_performance;
		Node* next;
	
	Node(char Name, int Emp_id, int Age, double Emp_Salary, int Emp_performance){
		
		this -> Name = Name;
		this -> Emp_id = Emp_id;
		this -> Age = Age;
		this -> Emp_Salary = Emp_Salary;
		this -> Emp_performance = Emp_performance;
		this -> next = NULL;
	}
	
	~Node(){
		
		int val = Name;
		
		if(this -> next != NULL){
		
			delete next;
			this -> next = NULL;
}	}
};

void insertAtHead(char Name, int Emp_id, int Age, double Emp_Salary, int Emp_performance, Node* &head){
	
	Node* temp = new Node(Name, Emp_id, Age, Emp_Salary, Emp_performance);
	
	temp -> next = head;
	head = temp;	
}

void performanceChecker(Node* head){
	
	Node* temp = head;
	Node* temp1 = head;
	
	while(temp -> next != NULL){
		
		if( temp -> Emp_performance <= 20){
			
			cout << "Name: " << head -> Name << endl;
			cout << "Employee ID: " << head -> Emp_id << endl;
			cout << "Age: " << head -> Age << endl;
			cout << "Employee Salary: " << head -> Emp_Salary << endl;
			cout << "Employee Performance: " << head -> Emp_performance << endl;
			
			temp1 = temp;
			delete temp1;
			temp= temp-> next;
		}
	} 
}

void Display(Node* &head){
	
	Node* temp = head;
	
	while(temp != NULL){
		
		cout << "Name: " << temp -> Name << endl;
		cout << "Employee ID: " << temp -> Emp_id << endl;
		cout << "Age: " << temp -> Age << endl;
		cout << "Employee Salary: " << temp -> Emp_Salary << endl;
		cout << "Employee Performance: " << temp -> Emp_performance << endl;
		
		cout <<endl;
		
		temp = temp -> next;
	}
	
}


int main(){
	
	Node* newNode = new Node('a', 1, 18, 5000, 69);
	Node* head = newNode;
	
//	Display(head);
	
	insertAtHead('A', 2, 18, 500, 20, head);
	//Display(head);
	
	insertAtHead('B', 3, 18, 500, 55, head);
////	Display(head);
//	
	insertAtHead('C', 4, 18, 500, 10, head);
	Display(head);
	
//	performanceChecker(head);
	
//	cout <<endl;
//	
	//Display(head);
//	
	return 0;
}
