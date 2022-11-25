//package week1;

import java.util.Scanner;

public class DseYear {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter a 9-digit registertion number: ");
        int reg = sc.nextInt();

        //int n1 = reg, n2 = reg;

        while(reg > 100){
            
            reg /= 10;
        }

        System.out.println("The student joined in year " +(2000+ reg));


    }
    
}
