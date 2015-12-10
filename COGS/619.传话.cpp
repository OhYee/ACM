#include <cstdio>
#include <string.h>
#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>
#include <stack>
using namespace std;

#define debug 0
#define REP(n) for(int o=0;o<n;o++)
#define REP1(m,n) for(int o1=0;o1<m;o1++)for(int o2=0;o2<n;o2++)
#define Min(a,b) ((a)<(b))?(a):(b)
#define Max(a,b) ((a)>(b))?(a):(b)
#define swap(a,b) {int Temp=a;a=b;b=Temp;}
#define abs(a) ((a>0)?a:(-a))
/*
#############################################################
*/
const int maxn=1001;
int n,m;
class Tree{
    private:
    struct Node{
        set<int> to;
    };
    vector<Node>node;
    bool d[maxn];//���ʱ��

    void bfs(int i){
        if(d[i])return;//�ѷ��ʹ�
        d[i]=true;
        set<int>& next=node[i].to;
        set<int>::iterator it;
        it=next.begin();
        REP(next.size()){
            bfs(*it);
            it++;
        }
    }

    public:
    void build(int n){
        node.resize(n+1);//�˵ı��Ϊ1-n
    }
    void add(int from,int to){
        node[from].to.insert(to);
        #if debug
        cout<<"     ��ϵ���� "<<from<<"��ʶ"<<to<<endl;
        #endif // debug
    }
    bool message(int i){
        memset(d,0,sizeof(d));

        set<int>& next=node[i].to;
        set<int>::iterator it;
        it=next.begin();
        REP(next.size()){
            bfs(*it);
            it++;
        }

        return d[i];
    }
};
Tree T;
int main(){
    freopen("messagez.in","r",stdin);
    #if !debug
    freopen("messagez.out","w",stdout);
    #endif // debug

    cin>>n>>m;
    #if debug
    cout<<"��������:"<<n<<"   ��ϵ������:"<<m<<endl;
    #endif // debug

    T.build(n);


    REP(m){
        int from,to;
        cin>>from>>to;
        T.add(from,to);
    }

    #if debug
    cout<<"��ϵ�������"<<m<<endl;
    #endif // debug

    REP(n){
        #if debug
        cout<<"���Դ�"<<o+1<<" ��ʼ����"<<endl;
        #endif // debug
        cout<<(T.message(o+1)==true?"T":"F")<<endl;
    }


}

