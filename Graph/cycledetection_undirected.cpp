#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
int par[N];
bool cycle, vis[N];
void dfs (int u) {
    vis[u] = true;
    for(auto v:g[u]) {
        if(!vis[v]) {
            par[v] = u;
            dfs(v);
        }
        else if(vis[v]) {
            if(par[u]!=v) {
                cycle = true;
            }
        }
    }
}

int main () {

    int n,m;
    cin >> n >> m;
    for(int i=1;i<=m;i++) {
        int u,v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(U);
    }
    cycle = false;
    for(int i=1;i<=n;i++) {
        if(!vis[i])dfs(i);
    }
    cout << (cycle ? "YES\n" : "NO\n") << endl;
}


//if bicoloring is possible, then the graph has even length cycle
//else, it has odd length cycle







