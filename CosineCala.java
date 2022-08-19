import static java.lang.Math.*;

public class CosineCala {
    public static void main(String[] args) {
        int d = 0;
        do {
            double a=(PI/180)*d;
            double b=1-(pow(a,2)/(1*2))+(pow(a,4)/(1*2*3*4))-(pow(a,6)/(1*2*3*4*5*6))+(pow(a,8)/(1*2*3*4*5*6*7*8));
            System.out.println("cos"+d+" = "+b);
            d++;
        } while (d <= 45);
            System.out.println("计算完毕！");
    }
}
