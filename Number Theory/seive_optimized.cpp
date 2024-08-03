#include<bits/stdc++.h>
using namespace std;

 int const N = 1e8 + 9;
bool f[N];
int main () {

    int n;
    cin >> n;
    vector<int>primes;
    auto st = clock();
    f[1] = true;
    for(int i=2;i*i<=n;i++) {
        if(!f[i]) {
            for(int j=i*i;j<=n;j+=i) {
                f[j] = true;
            }
        }
    }
    for(int i=2;i<=n;i++) {
        if(!f[i]) {
            primes.push_back(i);
        }
    }
    cout << primes.size() << endl;
    cerr << 1.0 * (clock()-st)/CLOCKS_PER_SEC << endl;
}
