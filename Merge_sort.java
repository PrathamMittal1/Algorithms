import java.util.Scanner;
public class Merge_sort {
    static int comparisons = 0;
    static void mergeSort(int[] A){
        int n = A.length; int[] R, L;
        int mid = n/2;
        if (n>1) {
            L = new int[mid]; R = new int[n - mid];
            for (int i = 0; i < mid; i++) L[i] = A[i];
            for (int i = mid, j = 0; i < n; i++, j++) R[j] = A[i];
            mergeSort(L); mergeSort(R);  //recursive calls
            merge(L,R,A);
        }
    }
    static void merge(int[] l, int[] r, int[] a){
        int i, j, k; i=j=k=0;
        int p = l.length, q = r.length;
        while (i<p && j<q){
            if (l[i]<=r[j]) a[k] = l[i++];
            else a[k] = r[j++];
            k++; comparisons++;
        }
        if (i==p){
            for (int n=j;n<q;n++) a[k++]=r[n];
        } else {
            for (int n=i;n<p;n++) a[k++]=l[n];
        }
        comparisons++;
    }
    static void display(int[] arr){         //display array
        for (int i: arr) System.out.print(i + "  ");
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
        //int[] arr = {15,10,20,80,90,89,2,45,4};
        System.out.println("Original list...");
        display(arr);
        mergeSort(arr);
        System.out.println("\n\nAfter sorting list...");
        display(arr);
        System.out.println("\nTotal comparisons made: " + comparisons + ".");
    }
}
