import java.io.IOException;
import java.util.Scanner;


public class Game {
    
    private static int random()
    {
        return (int) (Math.random() * (99)+1);
    }
    public static void main(String[] args) throws IOException {

        int num = random();
        System.out.println(num);
        Scanner scan = new Scanner(System.in);
        
        for (int i=0; i<5; i++){

            int input = scan.nextInt();
            if (Math.abs(num - input) < 10){
                System.out.println("youre answer was correct");
                scan.close();
                return;
            }
        }
        scan.close();
        System.out.println("out of tries program closing");
    }
}
