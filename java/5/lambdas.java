

import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


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
    public static int helper(String s1 , String s2) {
        for (int i =0; i<s1.length(); i++) { if( s1.charAt(i) == 'E' || s1.charAt(i) == 'e' ){
            return -1;
        }
        }
        for (int i = 0; i<s2.length(); i++) {
            if (s2.charAt(i)  == 'E' || s2.charAt(i) == 'e') {
                return 1;
            }
        }
        return 0; 

    }
    public static void stringWithE() {
        String[] arr = {"Huzaifa" , "Afridi" , "tomcat" , "Jerry" , "Mouse" , "Ethernet" , "Wiffi"};

        List<String> l = Arrays.stream(arr).sorted( (s1,s2) -> {for (int i =0; i<s1.length(); i++) { if( s1.charAt(i) == 'E' || s1.charAt(i) == 'e' ){
            return -1;
        }
        }
        for (int i = 0; i<s2.length(); i++) {
            if (s2.charAt(i)  == 'E' || s2.charAt(i) == 'e') {
                return 1;
            }
        }
        return 0;    
    } ).collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }

    }

    public static void stringWithEWithHelper() {

        String[] arr = {"Huzaifa" , "Afridi" , "tomcat" , "Jerry" , "Mouse" , "Ethernet" , "Wiffi"};

        List<String> l = Arrays.stream(arr).sorted( (s1,s2) -> { return helper(s1, s2);
    } ).collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }

    }

    public static void evenOddInts() {
        int[] arr = {22 , 45 , 7 , 56 , 509 , 9 , 104 };
        

        IntStream s = Arrays.stream(arr);
        List<String> l = s.mapToObj((ob) -> { if (ob%2 == 0) { String temp = "";
            temp += "e";
            temp += Integer.toString(ob);
            return temp;
            }
            return "O"+Integer.toString(ob);
        }).collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }
    }

    //rest of questions are done in the fucntions above they are callable
    public static void main(String[] args) {
        String[] arr = {"are" , "mar" , "arm" , "ear" , "aksdjf" , "jaslhf" , "abr" , "bar" };
        

        List<String> l = Arrays.stream(arr).filter(c -> c.length() <= 3 && c.charAt(0) == 'a').collect(Collectors.toList());

        for (String i : l)
        {
            System.out.println(i);
        }

    }
}
