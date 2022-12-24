public class Main {
    public static void main(String[] args) {

    }
}

class Pair<T> {
    private T first;
    private T second;

    public Pair(T first, T second) {
        this.first = first;
        this.second = second;
    }

    public T getFirst() {
        return first;
    }

    public void setFirst(T first) {
        this.first = first;
    }

    public T getSecond() {
        return second;
    }

    public void setSecond(T second) {
        this.second = second;
    }
}

class ArrayAlg {
    public static <T extends Comparable> Pair<T> MinMax(T[] a) {
        if (a.length == 0 || a == null) {
            return null;
        }
        T min = a[0];
        T max = a[0];
        for (int i = 1; i < a.length; i++) {
            if (a[i].compareTo(min) < 0) {
                min = a[i];
            }
            if (a[i].compareTo(max) > 0) {
                max = a[i];
            }
        }
        return new Pair<T>(min,max);
    }
}