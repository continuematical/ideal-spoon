import javax.imageio.IIOException;
import java.io.*;
import java.nio.charset.Charset;
public class Main{
    public static void main(String args[]){
        //Dog dog=new Dog(3,"mike","母");
        try{
            //序列化对象
              File file=new File("D:\\ideal-spoon\\object\\src\\Dog.obj");
//            OutputStream ou=new FileOutputStream(file);
//            ObjectOutputStream out =new ObjectOutputStream(ou);
//            out.writeObject(dog);
//            out.close();

            //反序列化
            InputStream in=new FileInputStream(file);
            ObjectInputStream i=new ObjectInputStream(in);
            Dog dog=(Dog)i.readObject();
            i.close();
            System.out.println(dog);
        }catch(FileNotFoundException e){
            e.printStackTrace();
        }catch(IOException e){
            e.printStackTrace();
        }catch(ClassNotFoundException e){
            e.printStackTrace();
        }
    }
}