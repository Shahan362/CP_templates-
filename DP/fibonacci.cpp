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

int dp[N];

int fib(int n) {
	if(n==0) return 0;
	if(n==1) return 1;
	if(dp[n]!=-1) return dp[n];
	return dp[n] = fib(n-1) + fib(n-2);
}

void s()
{
	memset(dp, -1, sizeof(dp));
    int x;
    cin >> x;
    
    cout << fib(x) % mod << endl;

}
int32_t main()
{
    ios::sync_with_stdio(false);

   // TC
    s();


}

