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
#define BASE        29
const int N = 1e6 + 7;
using namespace std;
int hp[N+5],hs[N+5],po[N+5];
void generatePrefixHash(string &s) {

    hp[0] = s[0] - 'a' + 1;
    for(int i=1;i<s.size();i++) {
        hp[i] = ((hp[i-1] * BASE) + (s[i] - 'a' + 1)) % mod;
    }

    for(int i=0;i<s.size();i++) {
        cout << hp[i] << endl;
    }
    po[0] = 1;
    for(int i=1;i<=s.size();i++) {
        po[i] = (po[i-1]*BASE) % mod;
    }
}

void generateSuffixHash(string &s) {

    hs[s.size()-1] = s[s.size()-1] - 'a' + 1;
    for(int i=s.size()-2;i>=0;i--) {
        hs[i] = ((hs[i+1] * BASE) + (s[i] - 'a' + 1)) % mod;
    }

    for(int i=s.size()-1;i>=0;i--) {
        cout << hs[i] << endl;
    }
    po[0] = 1;
    for(int i=1;i<=s.size();i++) {
        po[i] = (po[i-1]*BASE) % mod;
    }
}

int generateHash(string &s) {

    int H = 0;
    for(auto &c:s) {
         H = ((H*BASE) + (c-'a'+1))%mod;
    }
    return H;
}

int getHash(int L,int R) {

    if(L==0) return hp[R];
    return (hp[R] - (hp[L-1] * po[R-L+1]%mod) + mod)%mod;
}

void s()
{
    string s = "fixprefixsuffix";
    generatePrefixHash(s);
    generateSuffixHash(s);
}
int32_t main()
{   ios::sync_with_stdio(false);
    //TC
    s();


}

