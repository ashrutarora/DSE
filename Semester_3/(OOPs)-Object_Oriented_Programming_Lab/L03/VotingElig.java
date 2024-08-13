import java.util.Scanner;

public class VotingElig {

    public static void main(String[] args) {
    int counter =0;
    Scanner sc = new Scanner(System.in);

    System.out.println("Enter your NAME: ");
    String name = sc.next();

    System.out.println("Enter your AGE: ");
    int age = sc.nextInt();

    System.out.println("Are you a citizen of india? (Enter 1 for YES. Enter 2 for NO.)");
    int citizen= sc.nextInt();
    
    System.out.println("Do you have a criminal record? (Enter 1 for Yes. Enter 2 for NO)");
    int criminal= sc.nextInt();
    
    switch(citizen) {
    case 1:
    	counter=counter+1;
    	break;
    	
    default:
    	break;
    
    }
    switch(criminal) {
    case 2:
    	counter=counter+1;
    	break;
    default:
    	break;
    }
    if(age>=18) {
    	counter=counter+1;
    }
    if(counter==3) {
    	System.out.println(name+" is eligible for voting");
    }
    
    


    }
}
