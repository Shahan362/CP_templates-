#include<bits/stdc++.h>
using namespace std;

int main () {

    int n;
    cin >> n;

    int arr[n];

    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    int sqrtt = (int)ceil(sqrt(n));
    int sz = sqrtt;
    int sq[sz];
    fill_n(sq,sz,INT_MAX);
    for(int i=0;i<n;i++) {
        sq[i/sqrtt]=min(sq[i/sqrtt],arr[i]);
    }


    int q;
    cin >> q;
    while(q--) {
        int l,r;
        cin >> l >> r;
        int ans = INT_MAX;
        for(int i=l;i<=r;) {
            if(i%sqrtt==0&&i+sqrtt-1<=r) {
                ans = min(sq[i/sqrtt],ans);
                i+=sqrtt;
            }
            else {
                ans = min(ans,arr[i]);
                i++;
            }
        }
        cout << ans << endl;
    }

}

//16
//2 3 -1 9 6 -2 10 4 12 -1 5 7 16 -4 8 3
