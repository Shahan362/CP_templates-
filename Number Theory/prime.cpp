#include<bits/stdc++.h>
using namespace std;

bool is_prime(int n) {// O(sqrt(n))

    for(int i = 2; i * i <=n; i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    if(is_prime(n)) {
        cout << "Prime" << endl;
    }
    else {
        cout << "Not Prime" << endl;
    }
}


