#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MX = 1e6 + 10;
int arr[MX];
int tree[MX];

void init(int node, int b, int e) {

    if(b==e) {
        tree[node] = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    init(left,b,mid);
    init(right,mid+1,e);
    tree[node] = min(tree[left],tree[right]);

}

int query(int node, int b,int e, int i, int j) {

    if(i>e||j<b) {
        return INT_MAX;
    }
    if(b>=i&&e<=j) {
        return tree[node];
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b+e)/2;
    int leftMin = query(left,b,mid,i,j);
    int rightMin = query(right,mid+1,e,i,j);
    return min(leftMin,rightMin);


}


int32_t main () {

    int t,casee=1;;
    cin >> t;

    while(t--) {
        fill_n(tree, MX, MX);
        string s;
        getline(cin,s);
        cin.ignore();
        int n,q;
        cin >> n >> q;
        for(int i=0;i<n;i++) {
            cin >> arr[i];
        }
        init(0,0,n-1);
        cout << "Case " << casee << ":" << endl;
        while(q--) {
            int l,r;
            cin >> l >> r;
            cout << query(0,0,n-1,l-1,r-1) << endl;
        }
        casee++;
    }
}
