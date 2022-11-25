import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
 
public class Q1_count 
{   
    public static void main(String[] args) 
    {
        BufferedReader reader = null;  
         
        int charCount = 0;
        int wordCount = 0;
        int lineCount = 0;
        int vowlCount = 0;
         
        try
        {
            reader = new BufferedReader(new FileReader("D:\\sample.txt"));
             
            //Reading the first line into currentLine
            String currentLine = reader.readLine();
             
            while (currentLine != null){
                lineCount++;
                 
                //Getting number of words in currentLine
                String[] words = currentLine.split(" ");
                
                wordCount = wordCount + words.length;
 
                //Iterating each word
                for (String word : words){
                    charCount = charCount + word.length();
                }
                
                //Counting Number of Vowels
                for(int i=0;i<words.length;i++)
                {
                   for(int j=0;j<words[i].length();j++)
                   {
                      char ch=words[i].charAt(j);   //Read the word char by char
                      if(ch == 'a' || ch == 'e' || ch == 'i' ||ch == 'o' || ch == 'u')   //Checking for vowels
                      {
                             vowlCount++;
                        }
                   }
                }
                
                 
                //Reading next line into currentLine
                currentLine = reader.readLine();
            }
             
            System.out.println("No Of Characters In File : "+charCount);
            System.out.println("No Of Vowels In File : "+vowlCount);
            System.out.println("No Of Words In File : "+wordCount);
            System.out.println("No Of Lines In ile : "+lineCount);
        } 
        catch (IOException e) {
            e.printStackTrace();
        }
        finally {
            try{
                reader.close();           
            }
            catch (IOException e) {
                e.printStackTrace();
            }
        }
    }   
}