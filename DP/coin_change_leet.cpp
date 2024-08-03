//on the name of Allah:)
#include<bits/stdc++.h>
//#define int         long long
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
const int N = 1e4 + 7;
using namespace std;
int cs = 1;
int dp[N];

int func(int amount,vector<int>& coins) {
    if(amount==0) return 0;
    if(dp[amount]!=-1) return dp[amount];
    int ans = INT_MAX;
    for(int coin: coins) {
        if(amount - coin >= 0)
            ans = min(ans + 0LL,func(amount - coin, coins) + 1LL);
    }
    return dp[amount] = ans;
}

int coinChange(vector<int>& coins,int amount) {
    memset(dp,-1,sizeof(dp));
    int ans = func(amount, coins);
    return ans == INT_MAX ? -1 : ans;
}

void s()
{   
     vector<int> coins = {1,2,5};
     cout << coinChange(coins,11) << endl;

}
int main()
{
    ios::sync_with_stdio(false);

    //TC
    s();
}

