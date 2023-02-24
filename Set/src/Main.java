import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Collection set1 = new TreeSet();
        Person a1 = new Person("tom", 19);
        Person a2 = new Person("amy", 34);
        set1.add(a1);
        set1.add(a2);
        System.out.println(set1);

        List list=new ArrayList();
        list.add(12);
        list.add(34);
        list.add(256);
        list.add(39);
        Collections.sort(list);
        System.out.println(list);

    }
}

class Person implements Comparable {
    private String name;
    private int age;

    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public int getAge() {
        return age;
    }

    public void setAge(int age) {
        this.age = age;
    }

    @Override
    public int compareTo(Object o) {
        if (o instanceof Person) {
            return this.getName().compareTo(((Person) o).getName());
        } else {
            throw new RuntimeException("不是同一类型");
        }
    }
}
