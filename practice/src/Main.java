import java.io.*;
import java.lang.annotation.Retention;
import java.lang.annotation.RetentionPolicy;
import java.util.Scanner;

@SuppressWarnings("unused")
public class Main {
    public static void main(String[] args) {
        Dog dog = new Dog(3,"mike","母");
        File file = new File("D:\\ideal-spoon\\practice\\src\\Dog.obj");
        try {
            OutputStream out = new FileOutputStream(file);
            ObjectOutputStream ou = new ObjectOutputStream(out);
            ou.writeObject(file);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch(IOException e){
            e.printStackTrace();
        }
    }
}

