#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int node,edge;
vector<int> g[N];
bool vis[N];
int indeg[N];

void dfs(int x) {

    vis[x]=true;

    for(auto it:g[x]) {
        if(!vis[it]) {
            dfs(it);
        }
    }

}

int main () {

    //freopen("dfs.txt","r",stdin);
    cin >> node >> edge;
    while(edge--) {
        int u,v;
        cin >> u >> v;
        indeg[v]++;
        g[u].push_back(v);
    }
    vector<int> z;
    for(int i=1;i<=node ;i++) {
        if(indeg[i]==0) {
            z.push_back(i);
            vis[i] = true;
        }
    }
    vector<int>ans;
    while(ans.size()<node) {
        if(z.empty()) {
            cout << "Impossible, Cycle exists!" << endl;
            return 0;
        }
        int cur = z.back();
        z.pop_back();
        ans.push_back(cur);
        for(auto v: g[cur]) {
            indeg[v]--;
            if(!vis[v] && indeg[v]==0) {
                z.push_back(v);
                vis[v] = true;
            }
        }
    }
    for(auto it:ans) {
        cout << it << " ";
    }cout << endl;
    return 0;
}

