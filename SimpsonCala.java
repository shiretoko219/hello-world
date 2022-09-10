import java.util.Scanner;

public class SimpsonCala {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  //输入部分
        System.out.println("e^x积分计算器");
        System.out.println("请输入积分下限：");
        double a = sc.nextDouble();
        System.out.println("请输入积分上限：");
        double b = sc.nextDouble();
        System.out.println("请输入计算阶数（越大越精准）：");
        int n = sc.nextInt();

        double inter = (b-a)/(3*n);  //根据同济版高等数学辛普森法编制，计算公式前半部分
        double e = 2.718281828;
        double deltaX = (b-a)/n;  //计算步进值
        double [] yResult = new double[n+1];  //计算出每个点上的y值，存入数组备用
        double x = a;
        for (int i =0;i<n+1;i++){
            yResult[i] = Math.pow(e,x);
            x = x+deltaX;

        }
        double inter2;
        double[] nn = new double[2];
        for (int j=0;j<n+1;j++) {
            if ((j % 2) == 0 && j != 0) {
                nn[0] = nn[0]+(2 * yResult[j]);
                continue;
            } else if ((j % 2) == 1 && j != 0) {
                nn[1] = nn[1]+(4 * yResult[j]);
                continue;
            }
        }
        inter2 = yResult[0] + yResult[n] + nn[0] + nn[1];  //会和公式后半部分结果
        double finalResult = inter*inter2;
        System.out.println("结果为：");
        System.out.println(finalResult);
        sc.close();
    }
}
