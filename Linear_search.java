import java.util.Scanner;
public class Linear_search {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a list of numbers: ");
        String[] str = scanner.nextLine().split(" ");
        float[] arr = new float[str.length];
        for (int i=0; i< str.length; i++) arr[i] = Float.parseFloat(str[i]);
        System.out.print("Enter a number to find in array: ");
        float n = scanner.nextFloat();
        int in = -1;
        for (int i = 0; i< arr.length; i++)
            if(arr[i] == n){
                in = i; break;
            }
        System.out.println("Found " + n + " at index " + in + '.');
    }
}
