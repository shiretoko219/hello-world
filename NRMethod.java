import java.util.Scanner;

public class NRMethod {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("本程序将用牛顿迭代法计算函数的根");
        System.out.println("请输入预估的根：");
        double x0 = sc.nextDouble();
        System.out.println("请输入允许误差（小数）");
        double e = sc.nextDouble();
        double x1 = x0 - TheFunc(x0) / DevFunc(x0);
        System.out.println("结果为：");
        System.out.println(NRMethod(x0,e,x1));
        sc.close();
}
    public static double NRMethod(double x0,double e,double x1) {
        Double ein0,ein1;  //ein0储存计算误差和设置e比较，ein1负责储存计算结果
        double x = x0;
        double newX = x1;
        do {               //牛顿迭代法的计算
            double save;
            save = newX;
            newX = newX-((newX-x)/(TheFunc(newX)-TheFunc(x))*TheFunc(newX));
            double miu = save-newX;
            ein0 = Math.abs(miu);
            ein1 = newX;
        }
        while (ein0 < e);  //小于误差时，数出结果
        {
            return ein1;
        }
    }
    private static double TheFunc(double x){  //原函数
        double y = x*Math.log10(x)-1;
        return y;
    }
    private static double DevFunc(double x){  //原函数的导函数，需要手动计算
        double y = (1+Math.log10(x))/Math.log10(10);
        return y;
    }
}
