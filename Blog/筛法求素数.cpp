#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
const int maxn=10000;
int main(){
    int count[maxn+1]={0};
    //memset(count,0,sizeof(count));


    long prime[maxn]={0},num_prime=0;
    bool isNotPrime[maxn]={1,1};

    for(long i=2;i<maxn;i++){//��2��ʼ
        if(!isNotPrime[i])prime[num_prime++]=i;//�������������¼i
        for(long j=0;j<num_prime&&i*prime[j]<maxn;j++){//��0��ʼ
            isNotPrime[i*prime[j]]=true;//��������
            if(!(i%prime[j]))break;//
        }
    }

    for(int num=1;num<100;num++){
        if(isNotPrime[num]!=true){
            cout<<num<<"������"<<endl;
        }else{
            cout<<num<<"��������"<<endl;
        }
    }

    for(int i=1;i<=maxn;i++)if(count[i]>1)cout<<i<<":"<<count[i]<<endl;
    return 0;
}

