import java.util.ArrayList;
import java.util.Scanner;

public class MoratabKonBere {
    public static int partition(int []a, int n, int start, int end) {
        String msg = String.format("partition from %d to %d", start+1, end+1);
        System.out.println(msg);

        int k = end - start + 1;

        if (k == 1) return start;

        int pv = a[end];

        int _i = start;
        int _j = start;

        while(_j < end) {
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
        a[end] = t;

        return _i;
    }

    public static void quick(int[] a, int n, int start, int end) {
        if (start >= end) return;

        if (end - start == 1) {
            int mn = Math.min(a[start], a[end]);
            int mx = Math.max(a[start], a[end]);

            a[start] = mn;
            a[end] = mx;
        }

        int pv_i = partition(a, n, start, end);

        quick(a, n, start, pv_i-1);
        quick(a, n,pv_i+1, end);
    }

    public static void main(String[] args) {
        Scanner get = new Scanner(System.in);

        int n = get.nextInt();

        int[] a = new int [n];

        for (int i = 0; i < n; i++) {
            a[i] = get.nextInt();
        }

        quick(a, n, 0, n - 1);

        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }
}
