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
int dp[51][1015];

int func1(int ind, int amount,vector<int>& coins) {
    if(amount==0) return 1;
    if(ind<0) return 0;
    if(dp[ind][amount]!=-1) return dp[ind][amount];
    int ways = 0;
    for(int coin_amount = 0; coin_amount <= amount; coin_amount += coins[ind]) {
        ways += func1(ind - 1, amount - coin_amount, coins);
    }
    return dp[ind][amount] = ways;
}

int coinChange(vector<int>& coins,int amount) {
    memset(dp,-1,sizeof(dp));
    return func1(coins.size()-1, amount, coins);
}

void s()
{   
    int n,amount;
    cin >> n >> amount;
    vector<int> coins;
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;
        coins.push_back(x);
    }
    cout << "Case " << cs++ << ": ";
    cout << coinChange(coins,amount) << endl;

}
int main()
{
    ios::sync_with_stdio(false);

    TC
    s();
}

