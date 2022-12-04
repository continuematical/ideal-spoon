import com.sun.jdi.Value;

import java.lang.annotation.ElementType;
import java.lang.annotation.Target;

public class Main {
    public static void main(String[] args) throws Exception {
        int[] list=new int[]{1,4,7,2};
        System.out.println(money(list));
    }

    public static int money(int[] list){
        int[] num=new int[list.length];
        if(list.length==1){
            return list[0];
        }
        num[0]=list[0];
        num[1]=list[1];
        for(int i=2;i< list.length;i++){
            num[i]=Math.max(num[i-1],num[i-2]+list[i]);
        }
        return num[list.length-1];
    }
}


