#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
int dep[N];
int diameter,node,mx = INT_MIN;
void dfs1(int u,int p)
{
    dep[u] = dep[p] + 1;
    if(dep[u]>mx) {
        mx = dep[u];
        node = u;
    }
    for(auto v:g[u])
    {
        if(v!=p)
        {
            dfs1(v,u);
        }
    }

}

void dfs2(int u,int p)
{
    dep[u] = dep[p] + 1;
    diameter = max(diameter,dep[u]);
    for(auto v:g[u])
    {
        if(v!=p)
        {
            dfs2(v,u);
        }
    }

}

int main ()
{

    int n;
    cin >> n;
    for(int i=1; i<=n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    dfs2(node,0);
    cout << "Farthest node from 1 : " << node << endl;
    for(int i=1; i<=n; i++)
    {
        cout << dep[i] << " ";
    }cout << endl;
    cout << diameter << endl;
    return 0;
}
