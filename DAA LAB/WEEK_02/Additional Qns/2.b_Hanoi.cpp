//Write a program to implement recursive solution to the Tower of Hanoi puzzle and analyze its time efficiency.

#include<iostream>
using namespace std;

//recursive funtion
void TowerOfHanoi(int numDisks,char source,char dest,char auxiliary){
  if(numDisks == 1)
  {
    cout<<"Move from "<< source <<" to "<< dest << endl;
  }

    else
    {
        TowerOfHanoi(numDisks-1, source, auxiliary, dest);
        cout<<"Move from "<< source <<" to "<< dest << endl;
        TowerOfHanoi(numDisks-1 ,auxiliary, dest, source);
    }
}

//main funtion
int main(){
  int numOfDisk;
  cout<<"Enter the no. of disks"<<endl;
  cin>>numOfDisk;
  
  //calling recursive funtion
  TowerOfHanoi(numOfDisk,'A','C','B');//A is the source rod , C is destination rod ,B is auxiliary rod
  cout<<endl;
}
