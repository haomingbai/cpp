/*************************************************************************
    > File Name: 7-010.cpp
    > Author: Haoming Bai
    > Mail: haomingbai@hotmail.com 
    > Created Time: 2023年12月13日 星期三 08时06分46秒
 ************************************************************************/
#include<stdio.h>

int month_to_day(int month,int year=1){
        switch(month){
                case 1:return 31;
                case 2:if(year%4==0&&(year%100!=0||year%400==0)) return 29;
                                   return 28;
                case 3:return 31;
                case 4:return 30;
                case 5:return 31;
                case 6:return 30;
                case 7:return 31;
                case 8:return 31;
                case 9:return 30;
                case 10:return 31;
                case 11:return 30;
                case 12:return 31;
        }
}

int year_to_day(int year){
        if(year%4==0&&(year%100!=0||year%400==0)) return 366;
        return 365;
}

//Use 100sec as unit
long long int dif_tm(int *a,int *b){
        long long res=0;
        res+=(a[2]-b[2]);
        while(a[1]<b[1]){
                res-=month_to_day(a[1]++,a[0]);
        }
        while(a[1]>b[1]){
                res+=month_to_day(a[1]--,a[0]);
        }
        while(a[0]<b[0]){
                res-=year_to_day(a[0]++);
        }
        while(a[0]>b[0]){
                res+=year_to_day(a[0]--);
        }
        res*=(24*36);
        return res;
}

int main(){
        int data[2][3]={{0},{0}};
        scanf("%d %d %d\n%d %d %d",data[0],data[0]+1,data[0]+2,data[1],data[1]+1,data[1]+2);
        long long int res=0;
        //cout<<a<<endl;
        res=dif_tm(data[0],data[1]);
        printf("%lld00.000000\n",res);
}

