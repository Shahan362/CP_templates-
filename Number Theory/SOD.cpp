#include<bits/stdc++.h>
using namespace std;
int main () {

    int n;
    cin >> n;
    vector<int>p;
    map<int,int>mp;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                p.push_back(i);
                mp[i]++;
                n/=i;
            }
        }
    }
    if(n>1) {
        p.push_back(n);
        mp[n]++;
    }
    int sod=1;
    for(auto it: p) {
        cout << it << " ";  //prime factors
    }cout << endl;
    for(auto it:mp) {
        sod*=((pow(it.first,it.second+1)-1)/(it.first-1));
    }
    cout << sod << endl;
}
// O(sqrt(n))
