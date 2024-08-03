#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N = 1e5 + 7;
int node,edge;
int g[N][N];

int32_t main () {

    cin >> node >> edge;

    for(int i=1;i<=edge;i++) {
        int u,v,cost = 1;
        cin >> u >> v ;
        g[u][i] = cost;
    }

    for(int i=0;i<=node;i++) {
        for(int j=0;j<=node;j++) {
            cout << g[i][j] << " ";
        }
        cout << endl;
    }

}
