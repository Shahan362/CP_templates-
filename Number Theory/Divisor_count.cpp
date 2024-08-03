#include<bits/stdc++.h>
using namespace std;

int const N = 1e8 + 9;
int d[N];//divisor count
int ds[N];//sum of divisors
int main () {

    int n;
    cin >> n;
    for(int i=1;i<=n;i++) {
        for(int j=i;j<=n;j+=i) {
            d[j]++;
            ds[j]+=i;
        }
    }
    for(int i=1;i<=n;i++) {
        cout << ds[i] << " ";
    }
}
