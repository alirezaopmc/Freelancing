import java.util.Scanner;

public class HeapCheck {
    public static boolean isHeap(int[] arr, int n, int i) {
        if (i >= n) return true;

        int left = 2*i+1;
        int right = 2*i+2;

//        if (arr[i] < arr[left] || arr[i] < arr[right]) return false;
        if (left < n && arr[left] > arr[i]) return false;
        if (right < n && arr[right] > arr[i]) return false;

        return (
                isHeap(arr, n, left)
                &&
                isHeap(arr, n, right)
        );
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();

        int[] arr = new int[n];

        for(int i = 0; i < n; i++){
            arr[i] = input.nextInt();
        }

        System.out.println((isHeap(arr, n, 0) ? "Yes" : "No"));
    }
}
