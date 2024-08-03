#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int node,edge;
vector<int> g[N];
bool vis[N];
queue<int>q;

void bfs(int x) {

    vis[x]=true;

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v: g[u]) {
            if(!vis[v]) {
                q.push(v);
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

}
