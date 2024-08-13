/*
L6-2. Create a class as Student containing ID, Marks (array of 5). 
Now create methods for students to find the total and print the student score. 
Identify if the student is passed or failure with a minimum mark as 40M.
*/


import java.util.Scanner;

public class Student1 {
    public final int MIN_MARKS = 40;

    int id;
    int marks[] = new int[5];


    int total;
    int score;
    String result;

    public Student1(int id, int m1, int m2, int m3, int m4, int m5) {
        this.id = id;
        this.marks[0] = m1;
        this.marks[1] = m2;
        this.marks[2] = m3;
        this.marks[3] = m4;
        this.marks[4] = m5;
    }
    
    public int getId() {
        return id;
    }

    public int getTotal() {
        return marks[0] + marks[1] + marks[2] + marks[3] + marks[4];
    }

    public double getScore() {
        return getTotal() / 500.0 * 100.0;
    }

    public String getResult() {
            if (getScore() >= MIN_MARKS) {
                return "Pass";
            }
            else {
                return "Fail";
            }
    }

     public static void main(String[] args) {
    	 
    	 Scanner sc = new Scanner (System.in);
 		
 		System.out.println("Enter ID: ");
 		int ID = sc.nextInt();
 		
 		System.out.println("Enter Subject 1 Marks: ");
 		int m1 = sc.nextInt();
 		
 		System.out.println("Enter Subject 2 Marks: ");
 		int m2 = sc.nextInt();
 		
 		System.out.println("Enter Subject 3 Marks: ");
 		int m3 = sc.nextInt();
 		
 		System.out.println("Enter Subject 4 Marks: ");
 		int m4 = sc.nextInt();
 		
 		System.out.println("Enter Subject 5 Marks: ");
 		int m5 = sc.nextInt();
    	 
    	 
        Student1 s1 = new Student1(ID, m1, m2, m3, m4, m5);
        
        System.out.println("Student Scores:");
        System.out.println("ID: " + s1.getId());
        
        System.out.println("Total: " + s1.getTotal());
        System.out.println("Score: " + s1.getScore());
        System.out.println("Result: " + s1.getResult());

        
    }

}