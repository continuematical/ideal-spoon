import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Random;

public class Main {
    public static void main(String args[]) {
        int[] arr = new int[80000];
        for (int i = 0; i < 80000; i++) {
            arr[i] = (int) Math.random();
        }
        Date date1 = new Date();
        SimpleDateFormat format = new SimpleDateFormat("yy-MM-dd hh:mm:ss");
        System.out.println(format.format(date1));
        ShellSortSwap(arr);
        Date date2 = new Date();
        System.out.println(format.format(date2));
    }

    //希尔排序 交换法
    public static void ShellSortSwap(int arr[]) {
        for (int gap = arr.length / 2; gap > 0; gap /= 2) {
            for (int i = gap; i < arr.length; i++) {
                int tmp = 0;
                for (int j = i - gap; j >= 0; j -= gap) {
                    if (arr[j] > arr[j + gap]) {
                        tmp = arr[j + gap];
                        arr[j + gap] = arr[j];
                        arr[j] = tmp;
                    }
                }
            }
        }
    }

    //希尔排序 移位法
    public static void ShellSort(int[] arr) {
        for (int gap = arr.length / 2; gap > 0; gap /= 2) {
            //从第gap个元素开始逐个对其所在的组进行遍历
            for (int i = gap; i < arr.length; i++) {
                int j = i;
                int tmp = arr[j];
                while (tmp < arr[j - gap] && j >= gap) {
                    arr[j] = arr[j - gap];
                    j -= gap;
                }
            }
        }
    }
}