public class Main {
    public static void main(String[] args) {
        Father son = new Son();
        System.out.println("gay " + son.money);
    }

    static class Father {
        public int money = 1;

        public Father() {
            money = 2;
            show();
        }

        public void show() {
            System.out.println("Father " + money);
        }
    }

    static class Son extends Father {
        public int money = 3;

        public Son() {
            money = 4;
            show();
        }

        @Override
        public void show() {
            System.out.println("Son " + money);
        }
    }
}