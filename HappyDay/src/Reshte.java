import java.util.Scanner;

public class Reshte {
    public static String reverse(String s) {
        String r = "";

        for(int i = 0; i < s.length(); i++) {
            r += (s.charAt(i) == '1' ? "0" : "1");
        }

        return r;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        int l, r;
        l = scanner.nextInt();
        r = scanner.nextInt();

        int n = 100000;
        int k = 0;
        boolean s[] = new boolean[n];
        s[k++] = true;

        while (k < r) {
            for(int j = 0; j < k && j+k<n; j++) {
                s[j+k] = !s[j];
            }
            k *= 2;
        }

        for(int i = l-1; i < r; i++) {
            System.out.print((s[i] ? '1' : '0'));
        }
    }
}
