public class YanghuiTri {  //本程序将显示9阶杨辉三角
    public static void main(String[] args){
        int [][] arr = new int[9][];
        for (int i=0;i< arr.length;i++){  //确定（0，0）及每行第一个和最后一个的值为1
            for (int j=0;j<= i;j++){
                arr[i] = new int[j+1];
                arr[i][0]=1;
                if (i==j){
                arr[i][j]=1;
                }
            }
        }

        for (int k=1;k< arr.length;k++){  //确定其他位置的值
            for (int l=1;l< k;l++){
                arr[k][l] = (arr[k-1][l])+(arr[k-1][l-1]);
            }
        }

        for (int m=0;m<arr.length;m++){  //打印结果
            for (int n=0;n<=m;n++){
                System.out.print(arr[m][n]+" ");
            }
            System.out.println(" ");
        }
    }
}
