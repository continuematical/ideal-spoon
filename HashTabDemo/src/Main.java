import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        HashTab hash = new HashTab(7);
        Scanner in = new Scanner(System.in);
        System.out.println("请输入用户id");
        int id = in.nextInt();
        System.out.println("请输入用户姓名");
        String name = in.next();
        Employee emp = new Employee(id, name);
        hash.add(emp);
        hash.List();
    }
}

//表示一个雇员
class Employee {
    private int id;
    private String name;
    private Employee next = null;

    public Employee() {
    }


    public Employee(int id, String name) {
        super();
        this.id = id;
        this.name = name;
    }

    public int getId() {
        return id;
    }

    public String getName() {
        return name;
    }

    public Employee getNext() {
        return next;
    }

    public void setNext(Employee next) {
        this.next = next;
    }
}

//表示一条链表
class EmpLinkedList {
    //头指针
    private Employee head = null;

    //添加雇员
    public void add(Employee tmp) {
        if (head == null) {
            head = tmp;
        }
        Employee cur = head;
        while (cur.getNext() != null) {
            cur = cur.getNext();
        }
        cur.setNext(tmp);
    }

    //遍历链表
    public void List() {
        if (head == null) {
            System.out.println("该链表为空");
        }
        Employee cur = head;
        while (true) {
            System.out.println(cur.getName() + " " + cur.getId());
            if (cur.getNext() == null) {
                break;
            }
            cur = cur.getNext();
        }
    }

    public boolean find(int id) {
        if (head == null) {
            return false;
        }
        Employee cur = head;
        while (cur.getId() != id && cur.getNext() != null) {
            cur = cur.getNext();
        }
        if (cur.getId() == id) {
            return true;
        } else {
            return false;
        }
    }
}

//创建哈希表
class HashTab {
    private EmpLinkedList[] empLinkedListsArray;
    private int size;

    public HashTab(int size) {
        this.size = size;
        empLinkedListsArray = new EmpLinkedList[size];
        for (int i = 0; i < size; i++) {
            empLinkedListsArray[i] = new EmpLinkedList();
        }
    }

    //取模运算
    public int HashFun(int id) {
        return id % size - 1;
    }

    public void add(Employee emp) {
        int empLinkedListNo = HashFun(emp.getId());
        empLinkedListsArray[empLinkedListNo].add(emp);
    }

    public void List() {
        for (int i = 0; i < size; i++) {
            empLinkedListsArray[i].List();
        }
    }

    public void FindEmp(int id) {
        int empLinkedListNo = HashFun(id);
        System.out.println(empLinkedListsArray[empLinkedListNo].find(id));
    }
}