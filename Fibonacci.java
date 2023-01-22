public class Fibonacci {
    public static void main(String[] args) {
        int a = 0, b= 1, c;
        System.out.println("Fibonacci Series...");
        System.out.print(a); System.out.print(", " + b);
        for (int i=2; i<20; i++){
            c=a+b; a=b; b=c;
            System.out.print(", " + c);
        }
        System.out.print(",...");
    }
}
