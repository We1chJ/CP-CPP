
import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);

        int[] days = new int[5];
        int n = sc.nextInt();

        for(int i = 0; i < n; i++){
            String s = sc.next();
            for(int d = 0; d < 5; d++){
                char c = s.charAt(d);
                if(c == 'Y'){
                    days[d]++;
                }
            }
        }
        sc.close();

        int max = 0;
        int ind = -1;
        for(int i = 0; i < 5; i++){
            max = Math.max(max, days[i]);
        }

        ArrayList<Integer> list = new ArrayList<>();
        for(int i = 0; i < 5; i++){
            if(days[i] == max){
                list.add(i+1);
            }
        }
        String result = list.toString().replace("[","")
                                         .replace("]","")
                                         .replace(" ","");

        System.out.println(result);
    }
}
