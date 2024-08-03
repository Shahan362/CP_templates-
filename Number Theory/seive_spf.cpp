#include<bits/stdc++.h>
using namespace std;

int const N = 1e6 + 9;
int spf[N];
int main () { //O(nloglogn)
    int n;
    cin >> n;
    for(int i=2;i<n;i++) {
        spf[i]=i;
    }
    for(int i=2;i<n;i++) {
        for(int j=i;j<N;j+=i) {
            spf[j]=min(spf[j],i);
        }
    }
    for(int i=1;i<=n;i++) {
        cout << spf[i] << " ";
    }
}
