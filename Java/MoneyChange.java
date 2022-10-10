import java.util.Scanner;
public class MoneyChange{
    public static void main(String args[]){
        Scanner tej=new Scanner(System.in);
        System.out.println("enter the money");
        int money=tej.nextInt();
        
        if(money>=2000){
            int x=money/2000;
           
            System.out.println("2000 are"+x);
             money=money-(2000*x);
        }
        if(money>=500)
        {
            int y=money/500;
           
            System.out.println("500 are"+y);
             money=money-(500*y);
        }
        if(money>=100)
        {
            int z=money/100;
           
            System.out.println("100 are"+z);
             money=money-(100*z);
        }

    }

}