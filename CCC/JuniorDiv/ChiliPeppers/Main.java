package CCC.JuniorDiv.ChiliPeppers;


import java.util.Map;
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int ans =0 ;
        Map<String, Integer> map = Map.of(
            "Poblano", 1500,
            "Mirasol", 6000,
            "Serrano", 15500,
            "Cayenne", 40000,
            "Thai", 75000,
            "Habanero", 125000
        );
        for(int i = 0 ;  i< n ;i ++){
            String s = sc.next();
            ans += map.get(s);
        }

        sc.close();
        System.out.println(ans);
    }
    
}
