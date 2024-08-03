#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int vis[N],in[N],low[N];
vector<int>g[N];
int timer;

void dfs(int node,int par) {

    vis[node] = 1;
    in[node] = timer;
    low[node] = timer;
    timer++;
    for(auto child:g[node]) {
        if(child==par)continue;
        if(vis[child]==1) {
            low[node] = min(low[node],in[child]);
        }
        else {
            dfs(child,node);
            if(low[child]>in[node]) {
                cout << node << " " << child << endl;
            }
            low[node] = min(low[node],low[child]);
        }
    }

}

int main () {

    int n,m;
    cin >> n >> m;
    while(m--) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1,-1);

}
