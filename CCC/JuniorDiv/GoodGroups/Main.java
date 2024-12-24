
import java.util.HashSet;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        sc.nextLine(); // consume the newline character
        String[][] together = new String[x][2];
        for(int i  =0 ; i < x; i++){
            together[i] = sc.nextLine().split(" ");
        }
        int y = sc.nextInt();
        sc.nextLine(); // consume the newline character
        String[][] notTogether = new String[y][2];
        for(int i  =0 ; i < y; i++){
            notTogether[i] = sc.nextLine().split(" ");
        }

        // Not using this because one rule can be violated multiple times but the problem only asked for once
        // int ans = 0;
        HashSet<Integer> ansTogether = new HashSet<>();
        HashSet<Integer> ansNotTogether = new HashSet<>();

        int g = sc.nextInt();
        sc.nextLine(); // consume the newline character
        for(int i = 0; i < g; i++){
            String[] str = sc.nextLine().split(" ");
            // check groups
            for(int i_temp = 0; i_temp < together.length; i_temp++){
                String[] p = together[i_temp];
                int cnt = 0;
                for(String a : p){
                    for(String cur : str){
                        if(a.equals(cur)){
                            cnt++;
                        }
                    }
                }
                if(cnt == 1){
                    ansTogether.add(i_temp);
                }
            }
            // check not groups
            for(int i_temp = 0; i_temp < notTogether.length; i_temp++){
                String[] p = notTogether[i_temp];
                int cnt = 0;
                for(String a : p){
                    for(String cur : str){
                        if(a.equals(cur)){
                            cnt++;
                        }
                    }
                }
                if(cnt == 2){
                    ansNotTogether.add(i_temp);
                }
            }
        }
        sc.close();
        System.out.println(ansTogether.size() + ansNotTogether.size());
    }
    
}
