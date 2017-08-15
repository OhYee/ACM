#include<cstdio>
#include<string.h>
#include<vector>
#include<queue>
#include<iostream>

using namespace std;

#define debug 1

const int maxn = 105;
const int INF=10000;
int n,m;
int mindis=INF;
int di[maxn][maxn];

struct Road{
    int from,to,dist;
};
struct Node{
    int weight,id;
    bool operator < (const Node& rhs)const{
        return weight>rhs.weight;
    }
};

struct Dijkstra{
    int PointNumber,RoadNumber;
    vector<Road>road;
    vector<int>road_id[maxn];
    int d[maxn];
    bool done[maxn];

    void init(int n){//��ʼ��
        PointNumber=n;
        for(int i=0;i<n;i++){
            road_id[i].clear();
        }
        road.clear();
        #if debug
        cout<<"Dijkstra��ʼ�����"<<endl;
        #endif // debug
    }

    void AddRoad(int from,int to,int dist){
        road.push_back(Road{from,to,dist});//���뵽·����
        road_id[from].push_back(road.size()-1);//��¼·����id
        #if debug
       cout<<"·�� "<<from<<"-"<<to<<"����"<<dist<<" �����룬·��id "<<(road.size()-1)<<endl;
        #endif // debug
    }

    void dijkstra(int s){
        priority_queue<Node> Q;
        for(int i=0;i<PointNumber;i++){
            d[i]=INF;
        }
        d[s]=0;
        memset(done,false,sizeof(done));
        Q.push((Node){0,s});
        while(!Q.empty()){
            Node a=Q.top();
            Q.pop();
            #if debug
            cout<<"  ���Խ���ڵ�"<<a.id<<endl;
            #endif // debug
            if(done[a.id]==true)continue;
            done[a.id]=true;
            #if debug
            cout<<"     �ɹ�����ڵ�"<<a.id<<endl;
            #endif // debug
            for(int i=0;i<road_id[a.id].size();i++){
                Road& b=road[road_id[a.id][i]];
                #if debug
                cout<<"     ���ӽڵ�"<<b.to<<endl;
                #endif // debug
                if(d[b.to]>d[a.id]+b.dist){
                    d[b.to]=d[a.id]+b.dist;
                    #if debug
                    cout<<"     �ڵ�"<<b.to<<"Ȩֵ������"<<d[b.to]<<endl;
                    #endif // debug
                    Q.push((Node){d[b.to],b.to});
                }
            }
        }

    }

};
Dijkstra D;





priority_queue<Node> reasult;

int main(){
    freopen("djsa.in","r",stdin);
    #if !debug
    freopen("djsa.out","w",stdout);
    #endif // debug

    cin>>n>>m;
    #if debug
    cout<<"���й�"<<n<<"������·��"<<m<<"��"<<endl;
    #endif // debug

    D.init(n);

    for(int i=0;i<m;i++){
        int x,y,dis;
        cin>>x>>y>>dis;
        D.AddRoad(x,y,dis);
        D.AddRoad(y,x,dis);
    }
    #if debug
    cout<<"��ͼ�������"<<endl;
    #endif // debug

    for(int i=0;i<n;i++){
        #if debug
        cout<<"������"<<i<<endl;
        #endif // debug

        D.dijkstra(i);
        int maxdis=0;


        for(int j=0;j<n;j++){
            maxdis=(maxdis>=D.d[j]?maxdis:D.d[j]);
            #if debug
            cout<<" �ڵ�"<<j<<"ȨֵΪ"<<D.d[j]<<endl;
            #endif // debug
            di[i][j]=D.d[j];
        }
        #if debug
        cout<<"������"<<i<<"����Զ����Ϊ"<<maxdis<<endl;
        #endif // debug

    }


    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){

        }
    }

    return 0;
}
