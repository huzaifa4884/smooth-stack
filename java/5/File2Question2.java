import java.util.Arrays;
import java.util.List;
// import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class File2Question2 {
    public static void main(String[] args) {

        int[] arr = {16 , 8 , 886 , 8 , 1};
        // Function<Integer , Integer> ismome = (num) -> {return num%10;};
        IntStream s = Arrays.stream(arr);
        List<Integer> l = s.mapToObj(num -> { return num % 10;}).collect(Collectors.toList());
        l.forEach(num -> {System.out.println(num);});

        //question 3
        IntStream s1 = Arrays.stream(arr);
        List<Integer> l1 = s1.mapToObj(num -> { return num * 2;}).collect(Collectors.toList());
        l1.forEach(num -> {System.out.println(num);});
    }
}
