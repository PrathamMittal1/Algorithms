import java.util.Arrays;
import java.util.Scanner;

public class Quick_sort {
    static int comparisons = 0;
    static void quickSort(int[] arr, int l, int r) {
        int s;
        if (l<r){
            //s = lomutoPartition(arr,l,r);
            s = hoarePartition(arr, l, r);
            quickSort(arr, l, s); quickSort(arr, s+1, r);
        }
    }
    private static int lomutoPartition(int[] A, int l, int r) {
        int p=A[l], s=l;
        for (int i=l+1; i<r; i++){
            if (A[i]<p) {
                s++; swap(A,s,i);
                comparisons++;
            }
        }
        swap(A,l,s);
        return s;
    }
    private static int hoarePartition(int[] A, int l, int r) {
        int p=A[l], i=l, j=r;
        while (i<j){
            i=i+1;
            while (A[i]<p & i<r-1){
                i++; comparisons++;
            }
            j=j-1;
            while (A[j]>p){
                j--; comparisons++;
            }
            swap(A, i, j);
        }
        swap(A, i, j);
        swap(A, l, j);
        return j;
    }
    private static void swap(int[] A, int i, int j){
        var temp = A[i]; A[i] = A[j]; A[j] = temp;
    }
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter a list of integers: ");
        String str = scanner.nextLine();
        String[] str_arr = str.split(" ");
        int[] arr = new int[str_arr.length];
        for (int i = 0; i < str_arr.length; i++) {
            arr[i] = Integer.parseInt(str_arr[i]);
        }
        int n = arr.length;
        //int[] arr = 15 10 20 80 90 89 2 45 4
        System.out.println("Original list...");
        System.out.println(Arrays.toString(arr));
        quickSort(arr, 0, n);
        System.out.println("\n\nAfter sorting list...");
        System.out.println(Arrays.toString(arr));
        System.out.println("\nTotal comparisons made: " + comparisons + ".");
    }
}
