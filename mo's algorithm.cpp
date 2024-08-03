#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
struct range{

    int left,right,idx;

};
int sqrtt;
bool cmp(range a,range b) {

    if(a.left/sqrtt==b.left/sqrtt) {
        return a.right<b.right;
    }
    else {
        return a.left<b.left;
    }

}


int main () {

    int n , q;
    cin >> n >> q;
    sqrtt=sqrt(n)+1;
    int arr[n];
    for(int i=0;i<n;i++) {
        cin >> arr[i];
    }
    range query[q];
    int index=0;
    for(int i=0;i<q;i++) {
        int l,r;
        cin >> l >> r;
        query[i].left = --l;
        query[i].right = --r;
        query[i].idx = i;
    }
    for (int i = 0; i < q; ++i)   {    // is the query sorted?    {
         int ql = query[i].left;
        int qr = query[i].right;
        cout<<ql<<" "<<qr<<" "<<query[i].idx<<endl;

    }cout << endl;
    sort(query, query + q, cmp);
    for (int i = 0; i < q; ++i)   {    // is the query sorted?    {
         int ql = query[i].left;
        int qr = query[i].right;
        cout<<ql<<" "<<qr<<" "<<query[i].idx<<endl;

    }
    vector<int>ans(q);
    int cl=-1,cr=-1,lsum=0,rsum=0;
    while(cl!=query[0].left-1) {
        cl++;
        lsum+=arr[cl];
    }
    while(cr!=query[0].right) {
        cr++;
        rsum+=arr[cr];
    }
    int anss=rsum-lsum;
    cl++;
    ans[0]=anss;
    for(int i=1;i<q;i++) {
        if(cl<query[i].left) {
            while(cl!=query[i].left) {

                anss-=arr[cl];
                cl++;
            }
        }
        if(cl>query[i].left) {
            while(cl!=query[i].left) {
                cl--;
                anss+=arr[cl];

            }
        }
        if(cr<query[i].right) {
            while(cr!=query[i].right) {
                cr++;
                anss+=arr[cr];
            }
        }
        if(cr>query[i].right) {
            while(cr!=query[i].right) {
                rsum-=arr[cr];
                cr--;
            }
        }
        ans[i] = anss;
    }
    for(auto it:ans) {
        cout << it << " ";
    }cout << endl;
}
