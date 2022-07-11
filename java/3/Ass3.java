import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class Ass3 {
    public static void main(String[] args) {
        char letter = args[0].charAt(0);
        int count = 0;
        try {
            FileReader fr = new FileReader("data.txt");
            BufferedReader br = new BufferedReader(fr);
            String line;
            while ( (line = br.readLine()) != null) {

                for (int i = 0; i < line.length(); i++) {

                    if (letter == line.charAt(i))
                    {
                        count++;
                    }
                }

            } 
        } catch (IOException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
        System.out.print("Number of Time the letter repeated was   ");
        System.out.println(count);
        
    }
}
