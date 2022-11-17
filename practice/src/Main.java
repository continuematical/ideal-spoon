import java.io.File;

public class Main {
    public static void main(String[] args) {

    }

    public void filefind(File target,String exc){
        if(target==null)
            return;
        //判断是否为文件夹
        if(target.isDirectory()){
            File[] file=target.listFiles();
            //有些系统文件无法访问，返回空值
            if(file!=null){
                for(File f:file){
                    filefind(f,exc);
                }
            }
        }else{
            String name=target.getName().toLowerCase();
            if(name.endsWith(exc)){
                System.out.println(target.getAbsolutePath());
            }
        }
    }
}