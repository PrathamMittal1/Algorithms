import java.util.Arrays;
import java.util.Scanner;

public class Binary_search {
    static int binary_search(int[] A, float n){
        int mid, l=0, r=A.length;
        while (l<r){
            mid = (l+r)/2;
            if (A[mid] == n) return mid;
            else {
                if (n<A[mid]) r = mid;
                else if (n>A[mid]) l=mid+1;
                }
            }
        return -1;
        }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a list of integers: ");
        String[] str = scanner.nextLine().split(" ");
        int[] arr = new int[str.length];
        for (int i = 0; i < str.length; i++) arr[i] = Integer.parseInt(str[i]);
        Quick_sort.quickSort(arr, 0, arr.length);
        System.out.println("Sorted list: "+ Arrays.toString(arr));
        System.out.print("Enter a number to find in sorted list: ");
        int n = scanner.nextInt();
        int in = binary_search(arr, n);
        System.out.println("Found " + n + " at index " + in + '.');
    }
}
