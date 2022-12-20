import java.util.Arrays;

public class Main {
    public static void main(String[] args) {
        int[] arr = {3, 2, 8, 9, 5, 6, 7};
        int[] temp = new int[arr.length];
        mergeSort(arr, 0, arr.length - 1, temp);
        System.out.println(Arrays.toString(arr));
    }

    //分
    public static void mergeSort(int[] arr, int left, int right, int[] temp) {
        if (left < right) {
            int mid = (left + right) / 2;
            mergeSort(arr, left, mid, temp);
            mergeSort(arr, mid + 1, right, temp);
            merge(arr, left, mid, right, temp);
        }
    }

    //合并
    public static void merge(int[] arr, int left, int mid, int right, int[] temp) {
        int i = left;
        int j = mid + 1;
        int t = 0;
        //左右两边的数据进行比较，直到有一边的数据比较完
        while (i <= mid && j <= right) {
            if (arr[i] < arr[j]) {
                temp[t] = arr[i++];
            } else {
                temp[t] = arr[j++];
            }
            t++;
        }
        //将剩余一边地数据填充到temp里面
        while (i <= mid) {
            temp[t++] = arr[i++];
        }
        while (j <= right) {
            temp[t++] = arr[j++];
        }
        //拷贝数组
        t = 0;
        int tempLeft = left;
        while (tempLeft <= right) {
            arr[tempLeft++] = temp[t++];
        }
    }
}