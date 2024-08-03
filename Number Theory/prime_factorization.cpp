#include<bits/stdc++.h>
using namespace std;
int main () {

    int n;
    cin >> n;
    vector<int>p;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                p.push_back(i);
                n/=i;
            }
        }
    }
    if(n>1) {
        p.push_back(n);
    }

    for(auto it: p) {
        cout << it << " ";
    }cout << endl;

}
// O(sqrt(n))
