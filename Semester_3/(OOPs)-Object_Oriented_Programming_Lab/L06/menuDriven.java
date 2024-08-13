/* 
L6-3:  Write a menu driven program to do the following: 
-To compare two strings
-To convert the uppercase character to lower and vice-versa
-To display whether an entered string is a substring of the other or not 
-If the entered string is a substring of the other, replace it with “Hello”
*/
import java.util.Scanner;

public class menuDriven {

     public static void main(String[] args) {
         
         while(true) {

            System.out.println("Menu");
    
            System.out.println("1. compare two strings");
            System.out.println("2. convert the uppercase character to lower and vice-versa");
            System.out.println("3. Entered string is a substring of the other or not ");
            System.out.println("4. Entered string is a substring of the other, replace it with 'Hello'");
            System.out.println("5. Exit");
    
            System.out.print("Enter your choice (1-5): ");
            Scanner in = new Scanner(System.in);
            int ch = in.nextInt();


            switch(ch) {
                case 1: compareTwoStrings();
                        break;
                case 2: stringChangeCase();
                        break;
                case 3: checkSubstring();
                        break;
                case 4: substringChangeWithHello();
                        break;
                case 5: System.out.println("Exiting..");
                        System.exit(0);
                        break;

                default: System.out.println("Invalid Choice!!");
            }
        }

     }

     private static void compareTwoStrings() {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter string 1: ");
        String s1 = in.nextLine();
        
        System.out.println("Enter string 2: ");
        String s2 = in.nextLine();

        if (s1.equals(s2)) {
            System.out.println(s1 + " and " + s2 + " are equal");
        }
        else {
            System.out.println(s1 + " and " + s2 + " are unequal");
        }
        
     }

     private static void stringChangeCase() {
         Scanner in = new Scanner(System.in);
        
        System.out.println("Enter a string: ");
        String s1 = in.nextLine();
        
        System.out.println("result: ");
        for (int i=0; i < s1.length(); i++) {
            if (Character.isUpperCase(s1.charAt(i))) {
                System.out.print(Character.toLowerCase(s1.charAt(i)));
            }
            else {
                System.out.print(Character.toUpperCase(s1.charAt(i)));
            }
        }

     }
    
     private static void checkSubstring() {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter string 1: ");
        String s1 = in.nextLine();
        
        System.out.println("Enter string 2 to search: ");
        String s2 = in.nextLine();

        if (s1.contains(s2)) {
            System.out.println(s2 + " is a substring");
        }
        else {
            System.out.println(s2 + " is not a substring");
        }
     }

     private static void substringChangeWithHello() {
        Scanner in = new Scanner(System.in);
        
        System.out.println("Enter string 1: ");
        String s1 = in.nextLine();
        
        System.out.println("Enter string 2 to search: ");
        String s2 = in.nextLine();

        String newString = s1.replace(s2, "Hello");

        System.out.println("New String is: " + newString);
        
     }
}