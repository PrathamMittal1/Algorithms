import java.util.Scanner;

public class Factorial {
    static long fact(int n){
        long ans=1;
        for (int i=2;i<=n;i++){
            ans*=i;
        }
        return ans;
    }
    static int factR(int n){
        if (n==1 || n==0){
            return 1;
        }
        else return n*factR(n-1);
    }

    public static void main(String[] args) {
        System.out.print("Enter a natural number: ");
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        long f = fact(n);
        System.out.println("Factorial using loop is "+f+".");
        f = factR(n);
        System.out.println("Factorial using recursion is "+f+".");
    }
}
