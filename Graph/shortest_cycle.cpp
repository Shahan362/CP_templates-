//on the name of Allah:)
#include<bits/stdc++.h>
#define int         long long
#define endl        "\n"
#define pi          2 * acos(0.0)
#define mod         1000000007
#define Mul(a,b)    (a%mod * b%mod)%mod
#define Add(a,b)    (a%mod + b%mod)%mod
#define all(x)      (x).begin(),(x).end()
#define allr(x)     (x).rbegin(),(x).rend()
#define gcd(x, y)   (__gcd(x, y))
#define lcm(x, y)   ((x/gcd(x, y))*y)
#define faster      cin.tie(NULL), cout.tie(NULL);
#define TC          int t ; cin>>t ; while (t--)
const int N = 2e4 + 7;
using namespace std;
vector<int> g[N];
int shortest_cycle(int n)
{
    int ans = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        vector<int> dist(n, N);
        vector<int> par(n, -1);
        dist[i] = 0;
        queue<int> q;
        q.push(i);
        while (!q.empty())
        {

            int x = q.front();
            q.pop();
            for (int child : g[x])
            {
                if (dist[child] == N)
                {
                    dist[child] = 1 + dist[x];
                    par[child] = x;
                    q.push(child);
                }
                else if (par[x] != child and par[child] != x) {
                    ans = min(ans, dist[x] + dist[child] + 1);
                }
            }
        }
        for(int i=0;i<n;i++) {
            cout << dist[i] << " ";
        }cout << endl;
    }

    if (ans == INT_MAX)
        return INT_MAX;
    else
        return ans;
}


void s()
{
    int t,casee=1;;
    cin >> t;
    while(t--) {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<m;i++) {
            int u,v;
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int ans = shortest_cycle(n);
        cout << "Case " << casee << ": ";
        if(ans==INT_MAX) {
            cout << "Impossible" << endl;
        }
        else {
            cout << ans << endl;
        }
        casee++;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);

    s();


}

