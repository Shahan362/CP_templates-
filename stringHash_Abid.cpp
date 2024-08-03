#include <bits/stdc++.h>
using namespace std;
// Speed
#define Code ios_base::sync_with_stdio(false);
#define By cin.tie(NULL);
#define Abid cout.tie(NULL);
using vi = vector<int>;
using vs = vector<string>;
using ll = long long;
// #define int long long
#define endl '\n'
#define print(x) cout << " >> " << #x << " : " << x << endl
#define coutall(v) for (auto &it : v)cout << it << ' ';cout << endl;
const int N = 1e6 + 10;
const int Base1 = 137;
const int Base2 = 277;
const ll mod1 =  127657753;
const ll mod2 =  987654319;
// ll h[N + 5], power[N + 5];
pair<ll,ll>prefix[N];
pair<ll,ll>suffix[N];
pair<ll,ll>power[N];
void GeneratePrefixHash(string &s) // create an array of hash value of the prefix of the string
{
    prefix[0].first = s[0];
    for (int i = 1; i < s.size(); i++) // storing hash value of every prefix of the string based on ascii value
    {
        prefix[i].first = ((prefix[i - 1].first * Base1) + s[i]) % mod1;
    }
    prefix[0].second = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        prefix[i].second = ((prefix[i - 1].second * Base2) + s[i]) % mod2;
    }
    power[0].first = 1;
    for (int i = 1; i < s.size(); i++) // storing power of the base upto string length
    {
        power[i].first = (power[i - 1].first * Base1) % mod1;
    }
    power[0].second = 1;
    for (int i = 1; i < s.size(); i++)
    {
        power[i].second = (power[i - 1].second * Base2) % mod2;
    }
}
void GenerateSuffixHash(string s)
{
    int n=s.size();
    suffix[n-1].first = s[n-1];
    for (int i = n-2; i>=0; i--) // storing hash value of every prefix of the string based on ascii value
    {
        suffix[i].first = ((suffix[i + 1].first * Base1) + (s[i])) % mod1;
    }
    suffix[n-1].second = s[n-1];
    for (int i = n-2; i >=0; i--)
    {
        suffix[i].second = ((suffix[i + 1].second * Base2) + (s[i])) % mod2;
    }
}
pair<int,int> getHashVal(string &s) // return hash value of a string
{
    pair<ll,ll>H={0,0};
    for (int i = 0; i < s.size(); i++){
        H.first = ((H.first * Base1) + s[i]) % mod1;
    }
    for (int i = 0; i < s.size(); i++){
        H.second = ((H.second * Base2) + s[i]) % mod2;
    }
    return H;
}
pair<int,int> getPrefixRangeHash(int l, int r) // return hash value of a range
{
    pair<ll,ll>Hs;
    if (l == 0){
        return prefix[r];
    }
    Hs.first=(prefix[r].first - (prefix[l - 1].first * power[r - l + 1].first % mod1) + mod1) % mod1;
    Hs.second=(prefix[r].second - (prefix[l - 1].second * power[r - l + 1].second % mod2) + mod2) % mod2;
    return Hs;
}
pair<ll,ll> getSuffixRangeHash(int l, int r,int n) // return hash value of a range
{
    pair<ll,ll>Hs;
    if (r == n-1){
        return suffix[l];
    }
    Hs.first=(suffix[l].first - (suffix[r + 1].first * power[r - l + 1].first % mod1) + mod1) % mod1;
    Hs.second=(suffix[l].second - (suffix[r + 1].second * power[r - l + 1].second % mod2) + mod2) % mod2;
    return Hs;
}

pair<ll,ll> concat(pair<ll,ll> hash1,pair<ll,ll> hash2,int len){
    // return ((hash1*power[len])+hash2)%mod;
    return {((hash1.first*power[len].first)+hash2.first)%mod1,((hash1.second*power[len].second)+hash2.second)%mod2};
}



void solve(){
     int n;
    // cin >> n;
    while (cin >> n){
        string p, s;
        cin >> p >> s;
        GeneratePrefixHash(s);
        pair<ll,ll>hashValOfp = getHashVal(p);
        int cnt = 0;
        for (int i = 0; i + p.size() <= s.size(); i++){
            pair<ll,ll>range = getPrefixRangeHash(i, i + p.size() - 1);
            if (range==hashValOfp){
                cout << i << endl;
                cnt++;
            }
        }
        if (cnt == 0){
            cout << endl;
        }
        // cout << endl;
    }
}





int32_t main()
{
    // Code By Abid
    int t = 1;
    // cin >> t;
    for (int tc = 1; tc <= t; ++tc)
    {
        // cout << "Case " << tc << ": ";
        solve();
    }
}
// https://w...content-available-to-author-only...j.com/problems/NHAY/
