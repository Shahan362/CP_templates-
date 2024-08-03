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
const int N = 1e9 + 7;
using namespace std;

// int count_set_bits(int n)
// {   
// 	int set_bit_count = 0;
// 	while(n>0) {
// 		set_bit_count += (n&1);
// 		n = n>>1;
// 	}
// 	return set_bit_count;
// }

// int remove_last_set_bit(int n)
// {   
// 	n = (n&(n-1));
// 	return n;
// }

// int extract_bit(int n,int i) {
// 	return n & (1<<i);
// }

// int set_bit(int n,int i) {
// 	return n | (1<<i);
// }

// int unset_bit(int n,int i) {
// 	return n & (~(1<<i));
// }

// int swap(int &a, int &b) {
// 	a = a^b;
// 	b = b^a;
// 	a = a^b;
// }


void s()
{   
	int l,r;
	int ans = 0;
	cin >> l;
	cin >> r;
	for(int i=l;i<=r;i++) {
		for(int j=i;j<=r;j++) {
			int x = (i^j);
			if(ans<x) {
				ans = x;
			}
		}
	}
	cout << ans << endl;

}

int32_t main()
{   ios::sync_with_stdio(false);

    //TC
    s();


}




