#include<bits/stdc++.h>
using namespace std;
int main () {
    int t;
    cin >> t;
    int casee=1;
    while(t--) {
        string s1,s2,a;
        vector<string>v1,v2;
        cin >> s1;
        cin >> s2;
        int x;
        for(int i=0;i<s1.size();i++) {
            if(s1[i]=='.') {
                x = stoi(a);
                string y = bitset<8>(x).to_string();
                v1.push_back(y);
                a="";
            }
            else {
                a+=s1[i];
            }
        }
        x = stoi(a);
        string y = bitset<8>(x).to_string();
        v1.push_back(y);
        a="";
        for(int i=0;i<s2.size();i++) {
            if(s2[i]=='.') {
                v2.push_back(a);
                a="";
            }
            else {
                a+=s2[i];
            }
        }
        v2.push_back(a);

        bool flag = false;
        cout << "Case " << casee << ": ";
        for(int i=0;i<4;i++) {
            if(v1[i]!=v2[i]) {
                cout << "No" << endl;
                flag = true;
                break;
            }
        }
        if(!flag) {
            cout << "Yes" << endl;
        }
        casee++;
    }
}
