import java.util.*;
import java.io.*;
public class Q4_randomAccessFile {
	public static void main(String[] args) {
		Scanner sc = new Scanner (System.in);
		try {
			System.out.println("File : ");
			String fn = sc.next();
			RandomAccessFile file = new RandomAccessFile(fn, "rw");  
			file.seek(0);  
			long size = file.length();
			byte[] bytes = new byte[(int)size];  
	        file.read(bytes);
	        System.out.println(new String(bytes));
	        System.out.println("At what position to write? : ");
	        int pos = sc.nextInt();
	        file.seek(pos);  
	        System.out.println("What to write? : ");
	        String data = sc.next();
	        file.write(data.getBytes());  
	        file.close();  
		}
		catch (IOException e) {
			System.out.println("ERROR!!!");
		}
	}
}