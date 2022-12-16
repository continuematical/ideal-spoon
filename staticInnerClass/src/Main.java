public class Main {
    public static void main(String[] args) {

    }
}

class ArrayAlg {
    public static class Pair {
        private double first;
        private double second;

        public Pair(double f, double s) {
            this.first = f;
            this.second = s;
        }

        public double getFirst() {
            return first;
        }

        public double getSecond() {
            return second;
        }
    }

    public Pair MinMax(double[] values) {
        double max = Double.POSITIVE_INFINITY;
        double min = Double.NEGATIVE_INFINITY;
        for (double x : values) {
            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }
        return new Pair(min, max);
    }
}