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
const int N = 1e5 + 7;
using namespace std;
int h[N];
int dp[N];

int func(int i,int k) {
    if(i==0) return 0;
    if(dp[i]!=-1) return dp[i];
    int cost = INT_MAX;
    for(int j=1;j<=k;j++) {
        if(i-j>=0)
            cost = min(cost, func(i-j,k) + abs(h[i] - h[i-j]));
    }
    return dp[i] = cost; 
}

void s()
{   
    memset(dp,-1,sizeof(dp));
    int n, k;
    cin >> n >> k;
    for(int i=0;i<n;i++) {
        cin >> h[i];
    }
    cout << func(n-1, k) << endl;
}
int32_t main()
{
    ios::sync_with_stdio(false);

   // TC
    s();


}

