#include<bits/stdc++.h>
using namespace std;
const int N = 510;
int n,m;
queue<pair<int,int>>q;
char l[N][N];
int vis[N][N];
int dis[N][N];
int idx = 1;
int dRow[] = { -1, 0, 1, 0 };
int dCol[] = { 0, 1, 0, -1 };

string s = "snuke";

bool isValid(int row, int col, int idx,int u,int v)
{
    if (row < 1 || col < 1 || row > n || col > m)
        return false;

    if (vis[row][col] == vis[u][v])
        return false;

    if (l[row][col]!=s[idx])
        return false;

    return true;
}

void bfs(int x, int y) {
    q.push({x,y});
    vis[x][y]++;
    dis[x][y]=0;
    while(!q.empty()) {
        int u = q.front().first;
        int v = q.front().second;
        q.pop();

        for(int i=0;i<4;i++) {
            int adju = u+dRow[i];
            int adjv = v+dCol[i];

            if(isValid(adju,adjv,idx,u,v)) {
                    idx++;
                    if(idx==5)idx=0;
                    q.push({adju,adjv});
                    vis[adju][adjv]++;
                    dis[adju][adjv] = dis[u][v] + 1;
            }
        }
    }

}

int main () {

    cin >> n >> m;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cin >> l[i][j];
        }
    }
    if(l[1][1]!='s') {
        cout << "No" << endl;
        return 0;
    }
    for(int i=1;i<=N*N;i++)bfs(1,1);
    if(vis[n][m]==true) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=m;j++) {
            cout << vis[i][j] << " ";
        }cout << endl;
    }

}
