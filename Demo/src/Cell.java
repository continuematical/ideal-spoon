
public class Cell {
    public boolean Status;
    public boolean nextStatus;
    int LivingNum ;

    public boolean isStatus() {
        return Status;
    }

    public void setStatus(boolean status) {
        Status = status;
    }

    public boolean isNextStatus() {
        return nextStatus;
    }

    public void setNextStatus(boolean nextStatus) {
        this.nextStatus = nextStatus;
    }

    public Cell(boolean status) {
        Status = status;
    }
    public void setNextStatus(){
        if(LivingNum == 3) nextStatus  = true;
        else if (LivingNum == 2 ) nextStatus = Status;
        else nextStatus = false;
    }
}
