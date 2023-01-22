import java.util.Scanner;
public class Prime_or_not {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter an integer: ");
        int n = scanner.nextInt();
        boolean prime=true;
        if (n <= 1) {
            prime = false;
            System.out.println("Not prime! Try another input.");
        } else {
            for(int i=2; i<=(Math.sqrt(n)); i++) {
                if (n % i == 0) {
                    prime = false;
                    System.out.println("Not Prime! Divisible by " + i);
                    break;
                }
            }
        }
        if(prime) System.out.println("The given integer is prime number.");
    }
}
