#include <bits/stdc++.h>
using namespace std;
#define int long long
#define faster      cin.tie(NULL), cout.tie(NULL);
const int MAX = 1e5 + 10;
int par[MAX],circle[MAX];

void make(int v) {
    par[v] = v;
    circle[v] = 1;
}

int Find(int x)
{
    if(par[x]== x)
    {
        return x;
    }
    par[x] = Find(par[x]);
    return par[x];

}
int Union(int u,int v)
{
    int repU = Find(u);
    int repV = Find(v);

    if(repU != repV)
    {
        circle[repU] += circle[repV];
        par[v] = u;
        cout << circle[repU] << endl;
        return circle[repU];
    }
}
int32_t main()
{
    int u,v,tc,n,num;
    string s1,s2;
    map <string,int> mp;
    cin >> tc;

    while(tc--)
    {
        vector<int>ans;
        cin >> n;
        mp.clear();
        num = 1;
        for(int i=1;i<=n;i++) {
            make(i);
        }
        for(int i=1; i<=n; ++i)
        {
            cin >> s1 >> s2;
            if(mp.find(s1)==mp.end())
            {
                mp[s1] = num++;
            }
            if(mp.find(s2)==mp.end())
            {
                mp[s2] = num++;
            }
            ans.push_back(Union(mp[s1],mp[s2]));
        }
    }
}
