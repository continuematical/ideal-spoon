import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        int lottery=1;
        Scanner in=new Scanner(System.in);
        System.out.println("how many numbers do you need to draw?");
        int k=in.nextInt();
        System.out.println("what is the highest number can you draw?");
        int n=in.nextInt();
        for(int i=1;i<=k;i++){
            lottery=lottery*(n-i+1)/i;
        }
        System.out.println("you are 1 in the "+lottery+" good luck!");
    }
}