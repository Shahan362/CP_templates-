//Akhulbab
#include<bits/stdc++.h>
#define int long long
#define TC int t ; cin>>t ; while (t--)
using namespace std;
void s()
{
    int s,r,n,sum=0;
    cin >> n >> s >> r;
    int rem = s-r;
    vector<int>v(n);
    v[0]=rem;
    sum+=rem;
    for(int i=1;i<n;i++) {
        if(sum==s)break;
        v[i]++;
        sum++;
        if(i==n-1)i=0;
    }

    for(auto it:v) {
        cout << it << " ";
    }cout << endl;
}
int32_t main()
{
    TC //slash TC if test cases not needed.
    s();


}

