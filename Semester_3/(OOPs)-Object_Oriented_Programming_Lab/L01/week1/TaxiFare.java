//package week1;

import java.util.Scanner;

public class TaxiFare{
	
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter TAXI number: ");
        String taxiNo = sc.next();

        System.out.println("Enter Fare: ");
        float fare = sc.nextFloat();
        
        float dist = 0;

        if (fare>0 && fare <= 50)
            dist = fare/10 ;
        
        else if (fare > 50 && fare <=170)
            dist = (fare-50) /8 + 5 ;
        
        else if (fare > 170 && fare <= 300)
            dist = (fare - 170)/5 + 20;
        
        
        System.out.println("Taxi No: " + taxiNo);
        System.out.println("Distance covered: " + dist);
        System.out.println("Amount: " + fare);

    }


}
