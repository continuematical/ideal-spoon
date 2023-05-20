public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
    }
}

class LinkedNode {
    private int data;
    private String name;
    private String nickname;
    public LinkedNode next;

    public LinkedNode(int data, String name, String nickname) {
        this.data = data;
        this.name = name;
        this.nickname = nickname;
    }

    @Override
    public String toString() {
        return name + " " + nickname;
    }
}

class LinkedList {
    private LinkedNode Head = new LinkedNode(0, "", "");

    public void add(LinkedNode node) {
        LinkedNode tmp = Head;
        while (tmp.next != null) {
            tmp = tmp.next;
        }
        tmp.next = node;
    }

    public void list() {
        if (Head.next == null) {
            return;
        }
        LinkedNode tmp = Head;
        while (tmp.next != null) {
            System.out.println(tmp.next);
            tmp = tmp.next;
        }
    }
}