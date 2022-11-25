import java.util.Arrays;
import java.util.Scanner;

public class firstlast {

   public static void main(String args[]){

    Scanner sc = new Scanner(System.in);

      System.out.println("Enter the required size of the array : ");
      
      int size = sc.nextInt();

      int myArray[] = new int [size];
      

      System.out.println("Enter the elements of the array one by one: ");

      for( int i=0; i<size; i++)
      {
         myArray[i] = sc.nextInt();
      }

      System.out.println("Elements of the array are: "+Arrays.toString(myArray));

      if(size%2 == 0)
      {
        System.out.println("Sum of First and Last element of array is: " +(myArray[0] + myArray[size-1]));
      }
      else
      {
        System.out.println("Sum of First and Last element of array is: " +(myArray[0] + myArray[size-1] + myArray[size/2]));
      }

   }
}