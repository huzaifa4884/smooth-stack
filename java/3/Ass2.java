import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;

public class Ass2 {
    
    public static void main(String[] args) {
        try {
            //true flag is to open file in append mode
            FileWriter fw = new FileWriter("data.txt" , true);
            BufferedWriter bw = new BufferedWriter(fw);
            bw.write("\nAnd the 2nd line got appended");
            bw.close();


        } catch (IOException e) {
            System.out.println("excpetion occurred at main");
            e.printStackTrace();
        }
    }
}
