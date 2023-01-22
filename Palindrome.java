import java.util.Scanner;

public class Palindrome {
    static String reverse(String str){
        String[] arr=str.split("");
        int n = arr.length;
        for (int i=0,j=n-1;i<n/2;i++,j--){
            String temp = arr[i]; arr[i] = arr[j]; arr[j] = temp;
        }
        str = String.join("",arr);
        return str;
    }

    public static void main(String[] args) {
        System.out.print("Enter a string: ");
        Scanner scanner = new Scanner(System.in);
        String str = scanner.nextLine();
        String strR = reverse(str);
        System.out.println("Reverse is "+ strR);
        if (strR.equals(str)) System.out.println("The entered string is palindrome!");
        else System.out.println("The entered string is not palindrome.");
    }
}
