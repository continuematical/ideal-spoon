public class Main {
    //生产者/消费者问题
    public static void main(String[] args) {
        Clerk clerk = new Clerk();
        Producer producer = new Producer(clerk);
        Customer customer = new Customer(clerk);
        producer.setName("生产者");
        customer.setName("消费者");

        producer.start();
        customer.start();
    }
}

class Producer extends Thread {
    private Clerk clerk;

    public Producer(Clerk clerk) {
        this.clerk = clerk;
    }

    @Override
    public void run() {
        while(true){
            try {
                sleep(100);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

            clerk.produceProduct();
        }
    }
}

class Customer extends Thread {
    private Clerk clerk;

    public Customer(Clerk clerk) {
        this.clerk = clerk;
    }

    @Override
    public void run() {
        while (true){
            try {
                sleep(500);
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }

            clerk.consumeProduct();
        }
    }
}

class Clerk {
    private int number = 0;

    public synchronized void produceProduct(){
        if (number < 20) {
            number++;
            System.out.println(Thread.currentThread().getName() + " 生产商品" + number);

            notify();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }

    public synchronized void consumeProduct() {
        if (number > 0) {
            number--;
            System.out.println(Thread.currentThread().getName() + " 购买商品" + number);

            notify();
        } else {
            try {
                wait();
            } catch (InterruptedException e) {
                throw new RuntimeException(e);
            }
        }
    }
}