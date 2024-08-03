//Akhulbab
#include<bits/stdc++.h>
#define int long long
#define TC int t ; cin>>t ; while (t--)
using namespace std;
void s()
{
    string s = "3141592653589793238462643383279502884197169399";
    int cnt=0;
    string s2 ;
    cin >> s2;
    for(int i=0;i<s2.size();i++) {
        if(s[i]==s2[i]) {
            cnt++;
        }
        else {
            break;
        }
    }
    cout << cnt << endl;
}
int32_t main()
{
    TC //slash TC if test cases not needed.
    s();


}
