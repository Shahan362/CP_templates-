#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int node,edge;
vector<int> g[N];
bool vis[N],ok = true;
int color[N];


void dfs(int x) {

    vis[x]=true;

    for(auto it:g[x]) {
        if(!vis[it]) {
            color[it] = color[x] ^ 1;
            dfs(it);
        }
        else {
            if(color[x] == color[it]) {
                ok = false;
            }
        }
    }

}

int main () {

    //freopen("dfs.txt","r",stdin);
    cin >> node >> edge;
    while(edge--) {
        int u,v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=node;i++) {
        if(!vis[i])dfs(i);
    }
    if(ok) {
        cout << "Bipartite graph" << endl;
    }
    else {
        cout << "Not Bipartite graph" << endl;
    }


}
