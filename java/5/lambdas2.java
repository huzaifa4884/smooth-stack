import java.util.Arrays;
import java.util.function.Function;
import java.util.stream.IntStream;


public class lambdas2 {
    public static void main(String[] args) {
        String[] arr = {"5" , "1 4" , "2 5" , "3 898" , "1 3" , "2 12"};
        Function<Integer , String> isOdd = (s1) -> { if(s1 % 2 !=0) {return "Odd";} else {return "Even";}};
        // Function<Integer , Boolean> isEven = (s1) -> { if(s1 % 2 ==0) {return true;} else {return false;}};
        Function<Integer , String> isPrime = (s1) -> { for (int i=2; i<s1/2+1; i++) {if(s1 % i ==0) { System.out.println(i); return "COMPOSITE";}} return "PRIME";};
        Function<Integer , Boolean> isPalindrom = (number) -> {return number == IntStream.iterate(number, i -> i / 10)
            .map(n -> n % 10)
            .limit(String.valueOf(number).length())
            .reduce(0, (a, b) -> a = a * 10 + b);};

        Arrays.stream(arr).forEach((obj -> {String[] temp = obj.split(" "); if (temp[0].equals("1")) { System.out.println(isOdd.apply(Integer.parseInt(temp[1])));}

            if(temp[0].equals("2")) {System.out.println(isPrime.apply(Integer.parseInt(temp[1])));}
            if(temp[0].equals("3")) {System.out.println(isPalindrom.apply(Integer.parseInt(temp[1])));}
            else {System.out.println();}
        }));
        
        
        
    }
}
