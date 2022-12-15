import java.security.SecureRandom;
import java.util.Scanner;

class LotteryTicket {
    static float price = 2.0F;
    int buyNum;
    int winningNum;
    int[] myNum;
    float finalPrize = 0.0F;

    void buy() {   //确认购买数量部分
        Scanner sc = new Scanner(System.in);
        System.out.println("请输入您要购买的彩票数：");
        buyNum = sc.nextInt();
        myNum = new int[buyNum];
        sc.close();
    }
    void randomGuess() {   //彩票机选部分
        SecureRandom sr = new SecureRandom();
        System.out.println("您购买的彩票号码如下：");
        for (int i=0; i<buyNum; i++){
            myNum[i] = sr.nextInt(10000000);
            System.out.println(myNum[i]);
        }
    }
    void priceCala() {   //显示购买总价格部分
        System.out.println("您购买的彩票数量："+ buyNum +"张，共消费："+ price*buyNum +"元。");
    }
    void drawPrize() {   //开奖部分
        SecureRandom sr = new SecureRandom();
        winningNum = sr.nextInt(10000000);
        System.out.println("本期开奖号："+winningNum);
        for (int i=0; i<buyNum; i++){
            if (myNum[i]==winningNum){
                finalPrize += 5.0F;
                System.out.println("您赢得了5元！");
            }
        }
        System.out.println("您的中奖总金额为："+finalPrize+"元。");
    }
}

public class Caipiao {
    public static void main(String[] args) {
        LotteryTicket lt = new LotteryTicket();
        lt.buy();
        lt.randomGuess();
        lt.priceCala();
        lt.drawPrize();
    }
}
