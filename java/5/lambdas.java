

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import static java.lang.Integer.compare;


public class lambdas {
    public static void stol() {
        String[] arr = {"Huzaifa" , "Afridi" , "tomcat" , "Jerry" , "Mouse" , "Ethernet" , "Wiffi"};

        List<String> l = Arrays.stream(arr).sorted((s1 , s2) -> compare(s1.length() , s2.length())).collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }
    }

    public static void ltos() {
        String[] arr = {"Huzaifa" , "Afridi" , "tomcat" , "Jerry" , "Mouse" , "Ethernet" , "Wiffi"};

        List<String> l = Arrays.stream(arr).sorted((s2 , s1) -> compare(s1.length() , s2.length())).collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }
    }

    public static void firstLetterSort() {
        String[] arr = {"Huzaifa" , "Afridi" , "tomcat" , "Jerry" , "Mouse" , "Ethernet" , "Wiffi"};

        List<String> l = Arrays.stream(arr).sorted((s1 , s2) -> compare(Character.toLowerCase(s1.charAt(0)) , Character.toLowerCase(s2.charAt(0)))).collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }
    }
    public static void main(String[] args) {
        String[] arr = {"Huzaifa" , "Afridi" , "tomcat" , "Jerry" , "Mouse" , "Ethernet" , "Wiffi"};

        List<String> l = Arrays.stream(arr).sorted((s1 , s2) -> { return Integer.signum(s1.indexOf("e") - s2.indexOf("e")); } ).collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }

    }
}
