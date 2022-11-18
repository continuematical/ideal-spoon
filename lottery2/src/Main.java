import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        System.out.println("how many numbers do you need to draw?");
        int k=in.nextInt();
        System.out.println("what the highest numbers can you draw?");
        int n= in.nextInt();

        int[] number=new int[n];
        for(int i=0;i< number.length;i++){
            number[i]=i+1;
        }

        int[] result=new int[k];
        for(int i=0;i<result.length;i++){
            int r=(int)(Math.random()*n);
            result[i]=number[r];
            number[i]=number[n-1];
            n--;
        }

        Arrays.sort(result);
        for(int a:result){
            System.out.println(a);
        }
    }
}