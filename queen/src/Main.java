import java.io.*;

public class Main {
    static int max = 8;
    static int count = 0;
    static int[] array = new int[max];

    public static void main(String[] args) {
        check(0);
        System.out.println(count);
    }

    public static void check(int n) {
        if (n == max) {
            count++;
            return;
        }
        for (int i = 0; i < max; i++) {
            array[n] = i;
            if (judge(n)) {
                check(n + 1);
            }
        }
    }

    //判断是否符合标准
    private static boolean judge(int n) {
        for (int i = 0; i < n; i++) {
            if (array[i] == array[n] || Math.abs(n - i) == Math.abs(array[n] - array[i])) {
                return false;
            }
        }
        return true;
    }

    public static void print() {
        for (int i = 0; i < max; i++) {
            System.out.print(array[i] + " ");
        }
        System.out.println();
    }
}

