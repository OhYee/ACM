#include <cstdio>
#include<ctime>
int f(int a){
       int c;
       c=a+1;
       return c;
}
int main(){
                     double time_Start = (double)clock(); //��ʼʱ��
                     for(int i=1;i<=50000000;i++)f(i);
                                   double time_Finish = (double)clock(); //����ʱ��
       printf("\n operate time: %.2fms \n",time_Finish-time_Start); //���
       return 0;
}
