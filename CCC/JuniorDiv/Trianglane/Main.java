
import java.util.Scanner;


public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] arr = new int[2][n];
        int ans = 0;
        for(int r = 0; r < 2; r ++){
            for(int i = 0; i < n; i++){
                arr[r][i] = sc.nextInt();
                if(arr[r][i] == 1)
                    ans += 3;
            }
        }
        sc.close();
        for(int i = 0; i < n-1; i++){
            if(arr[0][i] == 1 && arr[0][i+1] == 1){
                ans-=2;
            }
            if(arr[1][i] == 1 && arr[1][i+1] == 1){
                ans-=2;
            }
        }
        for(int i = 0; i < n; i++){
            if(i%2 == 0 && arr[0][i] == 1 && arr[1][i] == 1){
                ans-=2;
            }
        }

        System.out.println(ans);
    }
    
}
