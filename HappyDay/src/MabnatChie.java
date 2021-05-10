import java.util.*;

class MabnatChie {
    static int getMax(int array[], int n)
    {
        int maxi = array[0];
        for (int i = 1; i < n; i++)
            if (array[i] > maxi)
                maxi = array[i];
        return maxi;
    }

    static void countSort(int arr[], int n, int exp)
    {
        int result[] = new int[n];
        int i;
        int cnt[] = new int[10];
        Arrays.fill(cnt, 0);

        for (i = 0; i < n; i++)
            cnt[(arr[i] / exp) % 10]++;

        for (i = 1; i < 10; i++)
            cnt[i] += cnt[i - 1];

        for (i = n - 1; i >= 0; i--) {
            result[cnt[(arr[i] / exp) % 10] - 1] = arr[i];
            cnt[(arr[i] / exp) % 10]--;
        }

        for (i = 0; i < n; i++)
            arr[i] = result[i];
    }


    static void sortBased(int array[], int n)
    {
        int m = getMax(array, n);

        for (int e = 1; m / e > 0; e *= 10) {
            countSort(array, n, e);
            for(int i = 0; i < n; i++) {
                System.out.print(array[i] + " ");
            }
            System.out.println();
        }
    }

    static void showArray(int array[], int n)
    {
        for (int i = 0; i < n; i++)
            System.out.print(array[i] + " ");
    }

    public static void main(String[] args)
    {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int m = input.nextInt();

        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }

        sortBased(arr, n);
    }
}
