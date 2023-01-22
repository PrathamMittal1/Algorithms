import java.util.Arrays;
import java.util.Scanner;
public class Bubble_sort {
    static void bSort(int[] A){
        for (int i=0; i<A.length; i++){
            for (int j=i+1; j<A.length; j++){
                if (A[j]<A[i]) {
                    var temp = A[i]; A[i] = A[j]; A[j] = temp;
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a list of integers: ");
        String[] str = scanner.nextLine().split(" ");
        int[] arr = new int[str.length];
        for (int i=0;i< str.length;i++) arr[i] = Integer.parseInt(str[i]);
        bSort(arr);
        System.out.println("After sorting list is...");
        System.out.println(Arrays.toString(arr));
    }
}
