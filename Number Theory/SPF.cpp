#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for(int i = 2 ; i * i <= n ; i++) {
        if(n % i == 0) {
            cout << i << endl;
            break;
        }
    }
}
//O(sqrt(n)
// The smallest divisor of a number is always prime.


