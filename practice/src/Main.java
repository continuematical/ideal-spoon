import java.lang.reflect.Field;
import java.lang.reflect.ParameterizedType;
import java.lang.reflect.Type;

public class Main {
    public static void main(String[] args) throws Exception {
        Class clazz = Cooker.class;
        Type types = clazz.getGenericSuperclass();
        ParameterizedType parameterizedType = (ParameterizedType) types;
        Type[] parameter = parameterizedType.getActualTypeArguments();
        System.out.println(((Class)parameter[0]).getName());
    }
}

class Person {
    private String name;
    private int age;

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
}

class Cooker extends Person {
    private String food;
    public String cook;

    public String getFood() {
        return food;
    }

    public void setFood(String food) {
        this.food = food;
    }

    public String getCook() {
        return cook;
    }

    public void setCook(String cook) {
        this.cook = cook;
    }
}