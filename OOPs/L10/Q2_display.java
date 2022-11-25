import java.io.File;
import java.io.IOException;

public class Q2_display {
	
   public static void main(String args[]) throws IOException {
	   
      //Creating a File object for directory
      File directoryPath = new File("D:\\");
      
      //List of all files and directories
      String contents[] = directoryPath.list();
      
      System.out.println("List of files and directories in the specified directory:");
      
      for(int i=0; i<contents.length; i++) {
         System.out.println(contents[i]);
      }
   }
}