import java.util.Scanner;
import java.io.FileWriter;
import java.io.*;

class read {

}

class copyTo {

}

public class Q3_menuDriven {

	public static void main(String[] args) throws Exception {

		Scanner sc = new Scanner(System.in);

		String input,sourceFile, destFile, line, content="";

		while (true) {

			System.out.println();
			System.out.println("1) Write to a File");
			System.out.println("2) Read from a File");
			System.out.println("3) Copy Bytes from 1 File to another File");
			System.out.println("4) Exit");

			System.out.println("Enter your choice");
			int choice = sc.nextInt();

			switch (choice) {

			case 1: // WRITE TO A FILE
				BufferedWriter bw = null;

				try {
					
//					System.out.println("Your Input in FILE: ");
//					input = sc.next();
					input = "This is my life and i can do whatever i want";

					FileWriter fw = new FileWriter("D:\\write.txt");
					bw = new BufferedWriter(fw);

					bw.write(input);
					bw.close();
					
				} catch (Exception e) {
					System.out.println(e);
				}

				break;

			case 2: // READ FROM A FILE

				try {
					FileReader fr = new FileReader("D:\\write.txt");

					int i;
					while ((i = fr.read()) != -1) {
						System.out.print((char) i);
					}
				} catch (Exception e) {
					System.out.println(e);
				}
				break;

			case 3: // COPY BYTES FROM 1 FILE TO ANOTHER
				
//				  System.out.print("Enter the Name of Source File: ");
//			      sourceFile = sc.next();
//			      
//			      System.out.print("Enter the Name of Destination File: ");
//			      destFile = sc.next();
			      
			      
			      FileInputStream Fread =new FileInputStream("sample.txt"); 
	              FileOutputStream Fwrite=new FileOutputStream("wow123.txt") ; 
	               
	               System.out.println("File is Copied"); 
	               int c; 
	               
	               while((c=Fread.read())!=-1) 
	               Fwrite.write((char)c); 
	               
	               Fread.close(); 
	               Fwrite.close(); 
			  
				break;

			case 4: // EXIT
				System.out.println("The End");
				System.exit(0);
				break;

			default:
				System.out.println("Invalid choice.");
			}
		}
	}
}
