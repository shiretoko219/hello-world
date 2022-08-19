#include <stdio.h>
#include <math.h>

int main() {
    int d =0;
    double PI = 3.14159265358979;
    do{
        double a=(PI/180)*d;
        double b=1-(pow(a,2)/(1*2))+(pow(a,4)/(1*2*3*4))-(pow(a,6)/(1*2*3*4*5*6))+(pow(a,8)/(1*2*3*4*5*6*7*8));
        printf("cos%d = %.11f\n",d,b);
        d++;
    }
    while(d<=45);
    printf("计算完毕！\n");
    return 0;
}
