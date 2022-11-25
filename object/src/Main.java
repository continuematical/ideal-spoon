import javax.imageio.IIOException;
import java.io.*;
import java.nio.charset.Charset;
public class Main{
    public static void main(String args[]){
        try{
            OutputStream out=new FileOutputStream("D:\\IdeaProjects\\file.txt");
            write(out);
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    public static void write(OutputStream out){
        Writer writer=new OutputStreamWriter(out,Charset.defaultCharset());
        try{
            writer.write("你好");
            writer.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
}