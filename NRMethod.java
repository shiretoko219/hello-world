import java.util.Scanner;

public class NRMethod {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("本程序将用牛顿迭代法计算函数的根");
        System.out.println("请输入预估的根：");
        double x0 = sc.nextDouble();
        System.out.println("请输入允许误差（小数）");
        double e = sc.nextDouble();
        double x1 = x0-TheFunc(x0)/DevFunc(x0);

        double[] ein = new double[2];  //数组，ein[0]储存计算误差和设置e比较，ein[1]负责储存计算结果
        double x = x0;
        double newx = x1;
        do {               //牛顿迭代法的计算
            double save;
            save = newx;
            newx = newx-((newx-x)/(TheFunc(newx)-TheFunc(x))*TheFunc(newx));
            double miu = save-newx;
            ein[0] = Math.abs(miu);
            ein[1] = newx;
        }
        while (ein[0] < e);  //小于误差时，数出结果
        {
            System.out.println("结果为：");
            System.out.println(ein[1]);
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
