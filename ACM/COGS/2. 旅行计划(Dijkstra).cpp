#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

#define debugmode 0


const int INF=100000;
const int maxn=105;
int n,m,v;
int path[maxn];

struct Edge{//��
    int from,to,dist;
    Edge(int u,int v,int d):from(u),to(v),dist(d){}
};
struct HeapNode{
    int d,u;//d��Ȩֵ u�ǽڵ���
    bool operator < (const HeapNode& rhs)const{
        return d>rhs.d;
    }
};

struct Dijkstra{
    int n,m;
    vector<Edge> edges;
    vector<int> G[maxn];//�ڵ���edges�е����
    bool done[maxn];//�Ƿ������ñ��
    int d[maxn];//s��������ľ���
    int p[maxn];//���·�ϵ�һ����
    void init(int n){
        this->n=n;
        for(int i=0;i<n;i++){
            G[i].clear();
        }
        edges.clear();
    }
    void AddEdge(int from,int to,int dist){
        edges.push_back(Edge(from,to,dist));
        m=edges.size();
        G[from].push_back(m-1);
        #if debugmode
        printf("��%d-%d Ȩֵ%d\n",from,to,dist);
        #endif
    }
    void dijkstra(int s){
        priority_queue<HeapNode> Q;
        for(int i=0;i<n;i++){
            d[i]=INF;
        }
        d[s]=0;
        memset(done,0,sizeof(done));
        Q.push((HeapNode){0,s});
        while(!Q.empty()){
            HeapNode x=Q.top();
            Q.pop();
            int u=x.u;//Ȩֵ��С�Ľڵ�
            if(done[u])continue;//�����ʹ�������
            done[u]=true;//��ӷ��ʹ���־
            #if debugmode
            printf("����ڵ�%d\n",u);
            #endif
            for(int i=0;i<G[u].size();i++){//�Ӹýڵ��������ڵ�ǰ��
                Edge& e=edges[G[u][i]];//��һ�ڵ�
                #if debugmode
                printf("���Խ���ڵ�%d\n",e.to);
                #endif
                if(d[e.to]>d[u]+e.dist){
                    d[e.to]=d[u]+e.dist;
                    p[e.to]=G[u][i];
                    Q.push((HeapNode){d[e.to],e.to});
                    #if debugmode
                    printf("�ڵ�%dȨֵ����%d\n",e.to,d[e.to]);
                    #endif
                    path[e.to]=u;
                }
            }

        }
    }
};
Dijkstra D;



int main(){
    freopen("djs.in","r",stdin);
    freopen("djs.out","w",stdout);

    cin>>n>>m>>v;

    D.init(n);
    for(int i=0;i<m;i++){
        int x,y,dis1;
        cin>>x>>y>>dis1;
        D.AddEdge(x,y,dis1);
    }

    D.dijkstra(v);

    for(int i=0;i<n;i++){
        cout<<i<<":"<<endl;
        if(D.d[i]==0||D.d[i]==INF){
            cout<<"no"<<endl;
            continue;
        }
        cout<<"path:";
        vector<int>temp;
        temp.push_back(i);
        while(temp[temp.size()-1]!=v){
            temp.push_back(path[temp[temp.size()-1]]);
        }
        for(int i=0;i<temp.size();i++){
            cout<<temp[temp.size()-i-1]<<" ";
        }
        cout<<endl<<"cost:"<<D.d[i]<<endl;
    }
    return 0;
}
