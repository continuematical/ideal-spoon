public class Main {
    public static int getCoins(int arr[]) {
        int n = arr.length;
        int coins[] = new int[n + 2];
        //dp[i][j] 表示区间i-j之间最大的能量值
        int dp[][] = new int[n + 2][n + 2];

        coins[0] = 1;
        for (int i = 1; i < n + 1; i++) coins[i] = arr[i - 1];
        coins[n + 1] = 1;

        for (int i = 1; i <= n; i++) dp[i][i] = coins[i - 1] * coins[i] * coins[i + 1];
        for (int i = n; i > 0; i--) {
            for (int j = i + 1; j <= n; j++) {
                int left = dp[i + 1][j] + coins[i - 1] * coins[i] * coins[j + 1];
                int right = dp[i][j - 1] + coins[i - 1] * coins[j] * coins[j + 1];
                dp[i][j] = Math.max(left, right);
                for (int k = i; k <= j; k++)
                    dp[i][j] = Math.max(dp[i][j], dp[i][k - 1] + coins[i - 1] * coins[k] * coins[j + 1] + dp[k + 1][j]);
            }
        }
        return dp[1][n];
    }

    public static void main(String[] args) {
        int[] array = {10, 18, 4, 3, 6, 12, 1, 9, 15, 8};
        QuickSort sort = new QuickSort(array);
        sort.sort();
    }
}

class QuickSort {
    private int[] array;

    public QuickSort(int[] array) {
        this.array = array;
    }

    public void sort() {
        quickSort(array, 0, array.length - 1);
    }

    public void print(int key) {
        System.out.println("枢纽为：" + key);
        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }

    /**
     * 递归排序
     *
     * @param src
     * @param begin
     * @param end
     */
    private void quickSort(int[] src, int begin, int end) {
        if (begin < end) {
            int key = src[begin];
            int i = begin;
            int j = end;
            while (i < j) {
                while (i < j && src[j] > key) j--;
                if (i < j) {
                    src[i] = src[j];
                    i++;
                }
                while (i < j && src[i] < key) i++;
                if (i < j) {
                    src[j] = src[i];
                    j--;
                }
            }
            src[i] = key;
//输出每一趟快速排序的结果
            print(key);
            quickSort(src, begin, i - 1);
            quickSort(src, i + 1, end);
        }
    }
}