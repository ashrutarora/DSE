import java.util.Scanner;

class q1{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int[] arrOfInt = new int[3];
    
        try {
            System.out.println("Enter 3 Numbers: ");
            for(int i=0; i<3; i++)  
            {
                arrOfInt[i]=sc.nextInt();  
            }  

        } catch (Exception e) {
            System.out.println("Enter a numeric value");
        }

    
}
}