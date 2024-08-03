#include<bits/stdc++.h>
using namespace std;
const int N = 1000;
int vis[N],in[N],low[N];
vector<int>g[N];
set<int>AP;
int timer;

void dfs(int node,int par) {

    vis[node] = 1;
    in[node] = timer;
    low[node] = timer;
    timer++;
    int cnt = 0;
    for(auto child:g[node]) {
        if(child==par)continue;
        if(vis[child]==1) {
            low[node] = min(low[node],in[child]);
        }
        else {
            dfs(child,node);
            cnt++;
            if(low[child]>=in[node] && par!=-1) {
                AP.insert(node);
            }
            low[node] = min(low[node],low[child]);
        }
    }
    if(par==-1 && cnt>1)AP.insert(node);
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

    for(auto it:AP) {
        cout << it << " ";
    }cout << endl;

}
