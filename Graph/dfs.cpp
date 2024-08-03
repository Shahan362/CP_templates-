#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int node,edge;
vector<int> g[N];
bool vis[N];


void dfs(int x) {

    vis[x]=true;

    for(auto it:g[x]) {
        if(!vis[it]) {
            dfs(it);
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

    dfs(1);//O(node+edge

    for(int i=1;i<=node;i++) {
        if(!vis[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;

}
