import java.util.ArrayList;
import java.util.Scanner;

public class Sandali {
    public static int partition(int []a, int n) {
        int pv = a[n-1];

        int _i = 0;
        int _j = 0;

        while(_j < n) {
            if (a[_j] < pv) {
                int t = a[_i];
                a[_i] = a[_j];
                a[_j] = t;
                _i++;
            }
            _j++;
        }

        int t = a[_i];
        a[_i] = pv;
        a[n-1] = t;

        return _i+1;
    }

    public static void main(String[] args) {
        Scanner get = new Scanner(System.in);

        int n = get.nextInt();

        int a[] = new int[n];

        for(int i = 0; i < n; i++) {
            a[i] = get.nextInt();
        }

        System.out.println(partition(a, n));

        for(int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
