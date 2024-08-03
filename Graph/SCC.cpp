//Kosaraju Algorithm
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;
int u, v, n, m;
vector<int>g[N],r[N],comp[N];
int vis[N];
stack<int>stk;
int numOfComp;
void dfs(int i) {
    vis[i] = 1;

    for(auto v:g[i]) {
        if(!vis[v]) {
            dfs(v);
        }
    }

    stk.push(i);
}

void dfs2(int i) {
    vis[i] = 1;
    comp[numOfComp].push_back(i);
    for(auto v:r[i]) {
        if(!vis[v]) {
            dfs2(v);
        }
    }
}

int main () {



    cin >> n >> m;
    memset(vis,0,sizeof vis);

    for(int i=1;i<=m;i++) {
        cin >> u >> v;
        g[u].push_back(v);
        r[v].push_back(u);
    }

    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            dfs(i);
        }
    }
    memset(vis,0,sizeof vis);
    numOfComp = 0;
    while(!stk.empty()) {
        int x = stk.top();
        stk.pop();
        if(!vis[x]) {
            numOfComp++;
            dfs2(x);
        }
    }
    for(int i=1;i<=numOfComp;i++) {
        cout << "Component number: " << i << endl;
        for(int j=0;j<comp[i].size();j++) {
            cout << comp[i][j] << " ";
        }cout << endl;
    }
    return 0;
}
