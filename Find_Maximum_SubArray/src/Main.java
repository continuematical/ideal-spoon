public class Main {
    public static void main(String[] args) {
        int[] arr={1,2,-3,4,8,0,-3,4};
        int sum=Find_Max_SubArray(arr,0,arr.length-1);
        System.out.println(sum);
    }

    public static int Find_Max_Crossing_SubArray(int[] arr, int low, int high, int mid) {
        int left_sum = Integer.MIN_VALUE;
        int right_sum = Integer.MIN_VALUE;
        int max_left, max_right;
        int sum = 0;
        for (int i = mid; i >= low; i--) {
            sum = sum + arr[i];
            if (sum > left_sum) {
                left_sum = sum;
                max_left = i;
            }
        }
        sum = 0;
        for (int i = mid + 1; i <= high; i++) {
            sum = sum + arr[i];
            if (sum > right_sum) {
                right_sum = sum;
                max_right = i;
            }
        }
        return left_sum + right_sum;
    }

    public static int Find_Max_SubArray(int[] arr, int low, int high) {
        if (low == high) {
            return arr[0];
        } else {
            int mid = (low + high) / 2;
            int left_max = Find_Max_SubArray(arr, low, mid);
            int right_max = Find_Max_SubArray(arr, mid + 1, high);
            int sum = Find_Max_Crossing_SubArray(arr, low, high, mid);

            if (left_max > right_max && left_max > sum) {
                return left_max;
            } else if (right_max > left_max && right_max > sum) {
                return right_max;
            }else{
                return sum;
            }
        }
    }
}