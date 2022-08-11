import java.util.Scanner;

public class SuperPlus {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入一个小于100的整数：");
        int num = sc.nextInt();
        int a=num;  //第一个加数a
        int b = 0;  //b充当结果暂存
        do {
            b=b+(a++);  //第一次相加后a自加，充当下一个加数
        }
         while (a <= 100);{
            System.out.println("结果是："+b);
        }
        sc.close();
    }
}
