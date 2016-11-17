/*
By:OhYee
Github:OhYee
Blog:http://www.oyohyee.com/
Email:oyohyee@oyohyee.com

かしこいかわいい？
エリーチカ！
要写出来Хорошо的代码哦~
*/
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

const int INF = 0x7FFFFFFF;
const double eps = 1e-10;

const int maxn = 10005;

//Tarjan
const int maxm = 100005;

struct Edge {
    int u,v;
    Edge():u(0),v(0) {}
    Edge(int a,int b):u(a),v(b) {}
};
int pos;
Edge edge[maxm];
list<int> L[maxn];
list<int> L2[maxn];

stack<int> s;
bool vis[maxn];
vector<int> SCC[maxn];//得到的强连通分量链表
int cnt;

inline void add(int u,int v) {
    edge[pos] = Edge(u,v);
    L[u].push_back(pos);
    pos++;
}

void tarjan(u)
{
    DFN[u] = Low[u] = ++Index;
    s.push(u);F
    for(){//枚举每一条边
        if(!vis[v]){
            tarjan(v);
            Low[u] = min(Low[u],Low[v]);
        }else if(stack[v]){//在栈里
            Low[u] = min(Low[u],DFN[v]);
        }

    }
    if(DFN[u] == Low[u]){
        v = s.top();
        s.pop();

        SCC[cnt++].push_back(u);

        while(u != v){
            list[cnt-1].push_back(v);
        }
    }
}

int Tarjan(){
    cnt = 0;
    tarjan(0);
    return cnt;

}

int main() {
    cin.tie(0);
    cin.sync_with_stdio(false);

    int n,m;
    while(cin >> n >> m,!(n == 0 && m == 0)) {
        for(int i = 0;i < n;i++) {
            L[i].clear();
            L2[i].clear();
            SCC[i].clear();
            vis[i] = false;
        }
        while(!s.empty())s.pop();
        pos = 0;

        for(int i = 0;i < m;i++) {
            int a,b;
            cin >> a >> b;
            add(a - 1,b - 1);
        }

        cout << (Kosaraju(n) == 1 ? "Yes" : "No") << endl;


    }
    return 0;
}