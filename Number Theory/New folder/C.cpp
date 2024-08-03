//Akhulbab
#include<bits/stdc++.h>
#define int long long
#define TC int t ; cin>>t ; while (t--)
using namespace std;
void s()
{
    int n;
    cin >> n;
    map<int,int>m;
    int a[n][n-1];
    for(int i=0;i<n;i++) {
        for(int j=0;j<n-1;j++) {
            cin >> a[i][j];
        }
    }
    int f_val,s_val;
    for(int j=0;j<n;j++) {
        m[a[j][0]]++;
    }
    for(auto it:m) {
        if(it.second==n-1) {
            f_val=it.first;
        }
        else {
            s_val=it.first;
        }
    }
    cout << f_val << " " ;
    for(int i=0;i<n;i++) {
        if(a[i][0]==s_val) {
            for(int j=0;j<n-1;j++) {
                cout << a[i][j] << " ";
            }
            break;
        }
    }cout << endl;
}
int32_t main()
{
    TC //slash TC if test cases not needed.
    s();


}

