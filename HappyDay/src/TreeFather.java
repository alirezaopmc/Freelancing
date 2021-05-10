import java.util.Scanner;

public class TreeFather {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int n = scanner.nextInt();

        int[] arr = new int[n];

        for(int i = 0; i < n; i++) {
            arr[i] = scanner.nextInt();
        }

        int m = scanner.nextInt();

        System.out.println(m + " " + arr[m-1]);
        if (m == 1) {
            System.out.println("root");
        } else {
            System.out.println((m/2) + " " + arr[(m/2-1)]);
        }
    }
}
