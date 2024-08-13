#include <iostream>
using namespace std;

#define MAX 7

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
	
	void isFull();
	void isEmpty();
	void peek();
	void display();
	void enqueue(int element);
	void dequeue();
	
};
		
//EMPTY?
void Queue::isEmpty(){
	
	 if(count == 0){
	 cout << "Queue is EMPTY"<<endl;
	}
	 
	 else{
	 cout << "Queue is NOT EMPTY" <<endl;
	}
}

//FULL?
void Queue::isFull(){
	
	 if(count == MAX ){
	 cout << "Queue is FULL"<<endl;
	}
	 
	 else{
	 cout << "Queue is NOT FULL" <<endl;
	}
	
}

//INSERT ELEMENT
void Queue::enqueue( int element ){
	
 if (count == MAX)
  cout<<"Queue Full" <<endl;
  
 else{
 	
  	myQueue[rear] = element;
  	rear = (rear + 1) % MAX;
  	count += 1;
  	cout << element << " Added" << endl;
 }
}

//DELETE ELEMENT
void Queue::dequeue(){
 if( count == 0 )
  cout<<"Queue Empty" <<endl;

 else{
 	cout << myQueue[front] << " Removed" << endl;
// 	myQueue[front] = 0;
 	front = (front + 1) % MAX;
 	count -= 1;
}
}

//First element of Queue
void Queue::peek(){
	
 		cout<<"PEEK: " << myQueue[front]<<endl;
}

//DISPLAY
void Queue::display(){
	
 if(count == 0)
  cout<<"Queue Empty" << endl;
  
 else{
 	cout << "Queue: ";
 	
  for( int i=front ; i!= rear ; i = (i+1)%MAX ){
  	
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
