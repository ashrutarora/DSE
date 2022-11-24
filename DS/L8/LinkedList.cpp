#include <iostream>
using namespace std;

class Linked_List{
	
	struct node {
		int info;
		struct node *link;
	};
	
	struct node *start;
	
	public:
		
		Linked_List(){
		start = NULL;
		}
		
		void Create_List(int element);
		void AddAtBeg(int);
		void AddAtEnd(int);
		void AddAfter(int,int);
		void AddBefore(int,int);
		void Delete();
		void Display();
				
};

void Linked_List :: Create_List(int data){
	
	struct node *q,*tmp;
//New node is created with new operator

		tmp= (struct node *)new(struct node);
		tmp->info=data;
		tmp->link=NULL;
		
		if (start==NULL) /*If list is empty */
		start=tmp;
		
		else
		{ /*Element inserted at the end */
			q=start;
			
			while(q->link!=NULL){
				q=q->link;
			}
			q-> link=tmp;
		}
	}	


void Linked_List::AddAtBeg(int data){
	
	struct node *tmp;
	tmp=(struct node*)new(struct node);
	tmp->info=data;
	tmp->link=start;
	start=tmp;
}

void Linked_List::AddAtEnd(int data){
	
	struct node *tmp;
	tmp=(struct node*)new(struct node);
	tmp->info=data;
	tmp->link=start;
	start=tmp;
	
}


void Linked_List::AddAfter(int data,int pos)
{

	struct node *tmp,*q;
	int i;
	q=start;

	for(i=0;i<pos-1;i++)
	{
		q=q->link;
		
		if(q==NULL){
			cout<<"There are less than "<<pos<<" elements";
			getch();
			return;
		}
	}/*End of for*/
	tmp=(struct node*)new(struct node);
	tmp->link=q->link;
	tmp->info=data;
	q->link=tmp;
}

//void Linked_List::AddBefore(int data,int pos)
//{
//
//	struct node *tmp,*q;
//	int i;
//	q=start;
//
//	for(i=0;i<pos-1;i++)
//	{
//		q=q->link;
//		
//		if(q==NULL){
//			cout<<"There are less than "<<pos<<" elements";
//			getch();
//			return;
//		}
//	}/*End of for*/
//	tmp=(struct node*)new(struct node);
//	tmp->link=q->link;
//	tmp->info=data;
//	q->link=tmp;
//}


void Linked_List::Delete()
{
	struct node *tmp,*q;
	int data;
	
	if(start==NULL){
		cout<<"\n\nList is empty";
		return;
	}
	
	cout<<"\n\nEnter the element for deletion : ";
	cin>>data;
	
	if(start->info == data)
	{	
		tmp=start;
		start=start->link; //First element deleted
		delete(tmp);
		return;
	}

	q=start;
	
	while(q->link->link != NULL){
		if(q->link->info==data) {
		//Element deleted in between
			tmp=q->link;
			q->link=tmp->link;
			delete(tmp);
			return;
		}
		q=q->link;
	}
	
	if(q->link->info==data) //Last element deleted
	{
		tmp=q->link;
		delete(tmp);
		q->link=NULL;
		return;
	}
	
	cout<<"\n\nElement "<<data<<" not found";
	getch();
}
	
void Linked_List::Display()
{
	struct node *q;
	
	if(start == NULL){
		
		cout<<"\n\nList is empty";
		return;
	}
	q=start;
	
	cout<<"\n\nList is : ";
	
	while(q!=NULL) {
		
		cout<<q->info;
		q=q->link;
		cout << " ";
	}
	
	
cout<< endl;
getch();
}

int main(){
	
	int choice,n,m,position,i;
	Linked_List po;
	
	while(1)
	{
		
		cout<<"1.Create List\n";
		cout<<"2.Add at Begining\n";
		cout<<"3.Add at End \n";
		cout<<"4.Add After\n";
		cout<<"5.Add Before\n";
		cout<<"6.Delete\n";
		cout<<"7.Display\n";
		cout<<"8.Quit\n";
		
		cout<<"\nEnter your choice:";
		cin>>choice;
		
	switch(choice)
	{
		case 1:
			cout<<"\n\nHow many nodes you want: ";
			cin>>n;
			
			for(i=0;i<n;i++)
			{
			cout<<"\nEnter the element:";
			cin>>m;
			
			po.Create_List(m);
			}
			break;
	
	 	case 2:
			cout<<"\n\nEnter the element: ";
			cin>>m;
			po.AddAtBeg(m);
			
			break;
			
		case 3:
			cout<<"\n\nEnter the element: ";
			cin>>m;
			po.AddAtEnd(m);
			
			break;
			
		case 4:
			cout<<"\n\nEnter the element: ";
			cin>>m;
			
			cout<<"\nEnter the position after which this element is inserted: ";
			cin>>position;
			
			po.AddAfter(m,position);
			
			break;
			
		case 5: 
		//Add before
		break;	
		
	 	case 6:
			po.Delete();
			break;
	
	 	case 7:
			po.Display();
			break;
			
	 	case 8:
		exit(0);
		
	 	default:
		cout<<"\n\nWrong choice";
	}/*End of switch */
}/*End of while */
}
	
	


