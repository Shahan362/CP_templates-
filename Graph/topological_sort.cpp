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
    vector<int>ans;
    while(ans.size()<node) {
        int cur = 0;
        for(int i=1;i<=node;i++) {
            if(!vis[i] && indeg[i]==0) {
                cur = i;
                break;
            }
        }
        if(cur == 0) {
            cout << "Impossible, Cycle exists!" << endl;
            return 0;
        }
        vis[cur] = true;
        ans.push_back(cur);
        for(auto v: g[cur]) {
            indeg[v]--;
        }
    }
    for(auto it:ans) {
        cout << it << " ";
    }cout << endl;
    return 0;
}
