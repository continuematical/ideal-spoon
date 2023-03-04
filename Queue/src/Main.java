public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}

class Queue {
    private int maxSize;
    private int front;
    private int rear;
    private int[] queue;

    public Queue(int maxSize) {
        this.maxSize = maxSize;//数组可以容纳的最大元素数量
        queue = new int[maxSize];
        rear = 0;//指向队列末尾的元素的后一个空位
        front = 0;//指向队列的第一个元素
    }

    public boolean isFull() {
        return rear == maxSize - 1;
    }

    public boolean isEmpty() {
        return rear == front;
    }

    public void addQueue(int n) {
        if (isFull()) {
            System.out.println("队列已满");
        }
        queue[rear] = n;
        rear = (rear + 1) % maxSize;
    }

    public int getQueue() {
        if (isEmpty()) {
            throw new RuntimeException("队列为空");
        }
        int value = queue[front];
        front = (front + 1) % maxSize;
        return value;
    }

    public void showQueue() {
        if (isEmpty()) {
            System.out.println("队列为空");
        }
        for (int i = front; i < front + size(); i++) {
            System.out.println(queue[i % maxSize]);
        }
    }

    public int size() {
        return (rear + maxSize - front) % maxSize;
    }

    public int headQueue() {
        if (isEmpty()) {
            throw new RuntimeException("队列为空");
        }
        return queue[front + 1];
    }
}