#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int node,edge;
vector<int> g[N];
bool vis[N];
int dis[N];
queue<int>q;

void bfs(int x) {
    q.push(x);
    vis[x]=true;
    dis[x]=0;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: g[u]) {
            if(!vis[v]) {
                q.push(v);
                dis[v]=dis[u]+1;
                vis[v] = true;
            }
        }
    }
}

int main () {

    freopen("dfs.txt","r",stdin);
    cin >> node >> edge;
    while(edge--) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    bfs(1);//O(node+edge)
    for(int i=1;i<=node;i++) {
        cout << dis[i] << " ";
    }
}
