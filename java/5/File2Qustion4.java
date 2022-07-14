import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class File2Qustion4 {
    public static void main(String[] args) {
        String[] arr = {"ax" , "bb" , "cx" , "c"};

        List l = Arrays.stream(arr).map(word -> { return word.replace("x", "");}).collect(Collectors.toList());
        
        l.forEach(word -> {System.out.println(word);});
    }
}
