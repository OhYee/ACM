#include <stdio.h>  
struct node {  
int divisor;            //��ʾ����  
int  remainder;     //��ʾ����  
}T[1000];  
  //�����Լ��  
int gcd ( int n, int m)  
{  
    return m ? gcd(m, n%m) : n;  
}  
  int main( )  
{  
   //MAX_NUM��ʾ��������Ľ�ķ�Χ�����ֵ��MIN_NUM��ʾ����Ľ�ķ�Χ����Сֵ��//n��ʾ����ͬ�ڷ��̵ĸ�����m��ʾ�������������ĳ˻���gcd_max��ʾ���������������Լ������Ϊ���������ǻ��ص�//����gcd_max=1��  
    int i, j, n, t = 0,m = 1, sum = 0, gcd_max = 0, MAX_NUM, MIN_NUM;  
   printf("�������м������̣�\n");    
    scanf("%d", &n);  
    printf("������ÿ�����ݣ�  ���� ��������\n"); 
    for ( i = 0; i < n; i++)  
        scanf("%d%d",&T[i].remainder,&T[i].divisor );  
    printf("����������ֵ��ֵ��min max\n" );  
        scanf("%d%d",&MIN_NUM, &MAX_NUM);  
//������������ĳ˻�m  
    for ( i = 0; i < n; i++) {  
    gcd_max = gcd (T[i].divisor, gcd_max);  
    m = m * T[i].divisor;  
    }  
    gcd_max *= m;  
//��mI  
    for ( i = 0; i < n; i++)   
    {     
        t = 0;m = 1;   
        for ( j = 0; j < n; j++)  
        {  
            if (j != i  )  
            {  
                t = gcd( T[j].divisor , t);  
                m  = m * T[j].divisor;  
            }  
        }  
        t = m * t;  
        m = t;  
        while (m % T[i].divisor != 1)  
            m += t;  
        sum += m * T[i].remainder;  
    }  
    printf("��С��ֵΪ��\n");  
    printf("%d\n",sum % gcd_max);  
    printf("�������ֵ����ֵ��\n");  
   if (sum >= MIN_NUM && sum <= MAX_NUM)  
    {  
        sum-=gcd_max;  
    while(sum>=MIN_NUM && sum<=MAX_NUM)  
    {   
        printf("%d   ",sum);  
        sum += gcd_max;  
    }  
    }else{  printf("No Solution!\n");   }  
  return 0; } 
