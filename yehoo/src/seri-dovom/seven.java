import java.util.ArrayList;
import java.util.Scanner;

public class seven {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();

        int arr[] = new int[n];

        for(int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int k = scanner.nextInt();
        int index = -1;

        for(int i = 0; i < n; i++) {
            if (arr[i] == k) {
                index = i;
                break;
            }
        }

        if (index < 0) {
            System.out.println("Not found");
        } else {
            System.out.println(index);
        }
    }
}
