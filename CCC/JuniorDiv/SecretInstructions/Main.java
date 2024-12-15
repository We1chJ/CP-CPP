
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int dir = 0;
        while(sc.hasNextLine()){
            String s = sc.nextLine();
            if(s.equals("99999")) break;
            int a = s.charAt(0) - '0';
            int b = s.charAt(1) - '0';
            int sum = a + b;
            String res = "";
            if (sum %2 == 1){
                res += "left";
                dir = 0;
            }else if(sum == 0){
                res += (dir == 0)? "left" : "right";
            }else{
                res += "right";
                dir = 1;
            }
            res += " " + s.substring(2);
            System.out.println(res);
        }
        sc.close();
    }
}
