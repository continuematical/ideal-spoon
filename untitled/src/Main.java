import java.util.Random;
import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        //生成中奖号码
        int[] number=creatNumber();
        for(int x:number){
            System.out.println(x);
        }
        //用户输入彩票号码
        int[] arr=userInputNumber();
        //判断用户中奖情况
        int RedCount=0;
        int BlueCount=0;
        //红球
        for(int i=0;i<arr.length-1;i++) {
            int RedNumber=arr[i];
            for(int j=0;j<number.length-1;j++){
                if(RedNumber==number[j]){
                    RedCount++;
                    break;
                }
            }
        }
        //蓝球
        int BlueNumber=arr[arr.length-1];
        if(BlueNumber==number[number.length-1])
            BlueCount++;
        System.out.println(RedCount);
        System.out.println(BlueCount);
    }
    public static int[] creatNumber() {
        //创建数组用于添加中奖号码
        int[] number=new int[7];
        //生成号码并添加到当前数组中
        Random r=new Random();
        for(int i=0;i<6;){
            //生成红球号码
            int redNumber=r.nextInt(33)+1;
            //判断数据在数组中是否存在，生成不重复的数据
            boolean flag=contain(number,redNumber);
            if(flag){
                number[i]=redNumber;
                i++;
            }
        }
        //生成蓝球号码
        int blueNumber=r.nextInt(16)+1;
        number[number.length-1]=blueNumber;
        return number;
    }
    //判断数据是否在数组中存在
    public static boolean contain(int[] number,int redNumber)
    {
        for(int i=0;i<number.length;i++)
        {
            if(number[i]==redNumber)
                return false;
        }
        return true;
    }

    public static int[] userInputNumber()
    {
        //存放用户输入的号码
        int[] arr=new int[7];
        Scanner in=new Scanner(System.in);
        //输入红球号码
        for(int i=0;i<6;) {
            System.out.println("请输入第"+(i+1)+"个号码");
            int redNumber=in.nextInt();
            if(redNumber>=1&&redNumber<=33){
                boolean flag=contain(arr,redNumber);
                if(flag){
                    arr[i]=redNumber;
                    i++;
                }else{
                    System.out.println("输入的红球号码重复");
                }
            }else{
                System.out.println("输入的红球号码超出范围");
            }
        }
        //输入蓝球号码
        System.out.println("请输入蓝球号码:");
        int blueNumber=in.nextInt();
        while(true){
            if(blueNumber>=1&&blueNumber<=16){
                arr[arr.length-1]=blueNumber;
                break;
            }else{
                System.out.println("输入的蓝球号码超出范围");
            }
        }
        return arr;
    }
}


