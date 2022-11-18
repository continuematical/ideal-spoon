import java.time.DayOfWeek;
import java.time.LocalDate;
public class Main {
    public static void main(String[] args) {
        LocalDate date=LocalDate.now();
        int month=date.getMonthValue();
        int today=date.getDayOfMonth();
        date=date.minusDays(1);
        DayOfWeek day=date.getDayOfWeek();
        int value= day.getValue();
        System.out.println("Mon Tue Wed Thu Fri Sat Sun");
        for(int i=1;i<value;i++){
            System.out.print("    ");
        }
        while(month== date.getMonthValue()){
            if(date.getDayOfMonth()==today){
                System.out.print(" * ");
            }else{
                System.out.print(" & ");
            }
            System.out.print(" ");
            date=date.plusDays(1);
            if(date.getDayOfWeek().getValue()==1)
                System.out.println();
        }
    }
}