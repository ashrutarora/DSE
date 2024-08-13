#include <iostream>
using namespace std;

#define MAX 7

class Queue{
	
	public:
	int myQueue[MAX];
	int front;
	int rear;
	
	Queue() {
		front = -1;
		rear = -1;
	}
	
	void isFull();
	void isEmpty();
	void peek();
	void display();
	void enqueue(int element);
	void dequeue();
	
};

		
//EMPTY?
void Queue::isEmpty(){
	
	 if(rear == -1 && front == -1){
	 cout << "Queue is EMPTY"<<endl;
}
	 
	 else{
	 cout << "Queue is NOT EMPTY" <<endl;
	}
}

//FULL?
void Queue::isFull(){
	
	 if(rear == MAX-1 ){
	 cout << "Queue is FULL"<<endl;
	}
	 
	 else{
	 cout << "Queue is NOT FULL" <<endl;
	}
	
}

//INSERT ELEMENT
void Queue::enqueue( int element ){
	
 if (rear == MAX-1)
  cout<<"Queue Overflow" <<endl;
  
 else{
 	
  if( front == -1){ 
   front = 0;
}
  rear++;
  myQueue[rear] = element;
 }
}

//DELETE ELEMENT
void Queue::dequeue(){
 if( rear == -1 && front == -1 )
  cout<<"Queue Underflow" <<endl;
  
 else if( front == rear ){
  front = rear = -1;
}

 else
 	cout << myQueue[front] << " DEQUEUED" <<endl;
 	front++;
}

//First element of Queue
void Queue::peek(){
	
 		cout<<"PEEK: " << myQueue[front]<<endl;
}

//DISPLAY
void Queue::display(){
	
 if(rear == -1 && front == -1)
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
	
	int val,ch;
	class Queue queue;
	
   cout<< "--------------------------------MENU--------------------------------" <<endl;
   cout<<"1) Enqueue" << endl;
   cout<<"2) Dequeue" << endl;
   cout<<"3) Display Queue" << endl;
   cout<<"4) Is Queue Empty?" << endl;
   cout<<"5) Is Queue Full?" << endl;
   cout<<"6) Peek Queue" << endl;
   cout<<"7) Exit" << endl;
   
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
            queue.isEmpty();
            break;
         }
         case 5: {
            queue.isFull();
            break;
         }
         case 6: {
            queue.peek();
            break;
         }
         case 7: {
            cout<<"Exit"<<endl;
            break;
         }
         default: {
            cout<<"Invalid Choice"<<endl;
         }
      }
   }
   while(ch!=7);


 return 0;
}
