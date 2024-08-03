#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {//O(logn)
    if(a==0)return b;
    if(b==0)return a;
    if(a<b) swap(a,b);
    return gcd(a%b,b);

}
int main () {
    int a,b;
    cin >> a >> b;
    int lcm = ((a*b)/gcd(a,b) + 10000007) % 10000007;
    cout << lcm << endl;
    cout << (gcd(a,b) + 10000007) % 10000007 << endl;
    //cout << gcd(10,15) << endl;

}
// O(sqrt(n))
