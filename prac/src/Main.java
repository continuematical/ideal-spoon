public class Main {
    public static void main(String[] args) {
        int[] array = {34, 50, 71, 26, 23, 9, 44, 35};
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
                while (i < j && src[j] > key) {
                    j--;
                }
                if (i < j) {
                    src[i] = src[j];
                    i++;
                }
                while (i < j && src[i] < key) {
                    i++;
                }
                if (i < j) {
                    src[j] = src[i];
                    j--;
                }
            }
            src[i] = key;
            print(key);
            quickSort(src, begin, i - 1);
            quickSort(src, i + 1, end);
        }
    }
}