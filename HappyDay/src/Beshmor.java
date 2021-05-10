import java.util.Scanner;

public class Beshmor {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        int n = input.nextInt();
        int m = input.nextInt();

        int[] array = new int[n];
        int[] count = new int[m+1];

        for(int i = 0; i < n; i++) {
            array[i] = input.nextInt();
            count[array[i]]++;
        }

        for(int i = 0; i <= m; i++) {
            System.out.print(count[i] + " ");
            if (i > 0) {
                count[i] += count[i-1];
            }
        }

        System.out.println();

        for(int i = 0; i <= m; i++) {
            System.out.print(count[i] + " ");
        }

        System.out.println();

        int[] result = new int[n];
        for (int i : result) i = 0;

        for(int i = n-1; i >= 0; i--) {
            result[--count[array[i]]] = array[i];

            for (int i1 : result) System.out.print(i1 + " ");
            System.out.println();
        }
    }
}
