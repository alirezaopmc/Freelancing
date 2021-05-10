import java.util.Scanner;

public class Triangles {
    public static int maxPath(int[][] arr, int n, int i, int j, int s) {
        if (j < 0 || j > i || i == n) return s;

        return Math.max(
                maxPath(arr, n, i+1, j, s + arr[i][j]),
                maxPath(arr, n, i+1, j+1, s + arr[i][j])
        );
    }

    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int t = input.nextInt();

        int[][] arr = new int[100][];
        for(int i = 0; i < 100; i++) {
            arr[i] = new int[100];
        }

        while(t-- > 0) {
            int n = input.nextInt();

            for(int i = 0; i < n; i++) {
                for(int j = 0; j < i+1; j++) {
                    arr[i][j] = input.nextInt();
                }
            }

            System.out.println(maxPath(arr, n, 0, 0, 0));
        }
    }

}
