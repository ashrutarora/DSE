import java.util.Scanner;

public class IsPrime {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a number to check if its Prime or Not: ");
        int number = sc.nextInt();

        if(Prime(number)) {
            System.out.println(number + " is prime number");
        }
        else{
            System.out.println(number + " is not a prime number");
        }
    }

    static Boolean Prime(int num)
    {
        if(num<=1)
        {
            return false;
        }
       for(int i=2; i<=num/2; ++i)
       {
           if((num%i)==0)
               return  false;
       }
       return true;
    }

    }
        
    
