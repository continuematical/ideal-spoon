public class Main {
    public static void main(String[] args) {
        MemberStrategy mem=new AdvanceMemberStrategy();
        context AdvanceMemberStrategy=new context();
        AdvanceMemberStrategy.SetName(mem);
        AdvanceMemberStrategy.calculatePrice(3,20);
    }
}

interface MemberStrategy{
    public double calculatePrice(int n,double price);
}

class PrimaryMemberStrategy implements MemberStrategy{
    public double calculatePrice(int n,double price){
        return n*price;
    }
}

class IntermediateMemberStrategy implements MemberStrategy{
    public double calculatePrice(int n,double price){
        return n*price*0.9;
    }
}

class AdvanceMemberStrategy implements MemberStrategy{
    public double calculatePrice(int n,double price){
        return n*price*0.8;
    }
}

class context{
    private MemberStrategy memberStrategy;
    public void SetName(MemberStrategy name){
        this.memberStrategy=name;
    }

    public void calculatePrice(int n,double price){
        System.out.println(memberStrategy.calculatePrice(n,price));
    }
}