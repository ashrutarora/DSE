#include <iostream>
using namespace std;

#define MAX 5

class Queue{
	
	public:
	int myQueue[MAX];
	int front;
	int rear;
	int count;
	
	Queue() {
		front = -1;
		rear = -1;
		count = 0;
	}
	
	bool isFull();
	bool isEmpty();
	//void peek();
	void display();
	void enqueue(char element);
	void dequeue();
	
};
		
//EMPTY?
bool Queue::isEmpty(){
	
	 if(count == 0)
	 return true;
	 
	 else
	 return false;
}

//FULL?
bool Queue::isFull(){
	
	if (count == MAX) {
      return true;
    }
    
    if (front == rear + 1) {
      return true;
    }
    
    return false;
}

//INSERT ELEMENT
void Queue::enqueue( char element ){
	
 if (count == MAX)
  cout<<"Queue Overflow" <<endl;
  
 else{
 	
 	myQueue[rear] = element;
 	rear = (rear + 1) % MAX;
 	count += 1;
}
}

//DELETE ELEMENT
void Queue::dequeue(){
	
 if( count == 0)
  cout<<"Queue Underflow" <<endl;
  
 else{
 	
 	myQueue[front] = 0;
 	front = (front + 1) % MAX;
 	count -= 1;

 }
}


//DISPLAY
void Queue::display(){
	
 if(count == 0)
  cout<<"Queue Underflow" << endl;
  
 else{
 	cout << "Queue: ";
 	
  for( int i=front ; i<= rear ; i++){
  	
   cout << myQueue[i] <<" ";
}

  cout<<endl;
 }
}



int main()
{
	
	int ch;
	char val;
	class Queue queue;
	
   cout<< "--------------------------------MENU--------------------------------" <<endl;
   cout<<"1) Enqueue" << endl;
   cout<<"2) Dequeue" << endl;
   cout<<"3) Display Queue" << endl;
//   cout<<"4) Is Queue Empty?" << endl;
//   cout<<"5) Is Queue Full?" << endl;
//   cout<<"6) Peek Queue" << endl;
   cout<<"4) Exit" << endl;
   
   do {
      cout<<endl<<"Enter choice: "<<endl;
      cin>>ch;
      
      switch(ch) {
         case 1: {
            cout<<"Enter value to ENQUEUE it:"<<endl;
            cin>>val;
            
            queue.enqueue(val);
            break;
         }
         case 2: {
            queue.dequeue();
            break;
         }
         case 3: {
            queue.display();
            break;
         }
         case 4: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }
   while(ch!=4);


 return 0;
}
