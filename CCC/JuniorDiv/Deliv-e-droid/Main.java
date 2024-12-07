import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt();
        int c = sc.nextInt();
        sc.close();

        System.out.println((p*50 - c * 10) + ((p > c) ? 500 : 0));
    }    
}