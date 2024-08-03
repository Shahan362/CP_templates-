#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAX = 1e5 + 10;
int arr[MAX * 4];
struct Tree
{
    int sum, prop = 0;

} tree[MAX * 4];
void init(int node, int b, int e)
{
    if (b == e)
    {
        tree[node].sum = arr[b];
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    init(left, b, mid);
    init(right, mid + 1, e);
}
int query(int node, int b, int e, int i, int j, int pro = 0)
{
    if (i > e || j < b)
    {
        return 0;
    }
    if (b >= i && e <= j)
    {
        return tree[node].sum + (e - b + 1) * pro;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;
    int leftSum = query(left, b, mid, i, j, tree[node].prop + pro);
    int rightSum = query(right, mid + 1, e, i, j, tree[node].prop + pro);
    return leftSum + rightSum;
}
void update(int node, int b, int e, int i, int j)
{
    if (i > e || j < b)
    {
        return;
    }
    if (b >= i && e <= j)
    {
        tree[node].sum += (e - b + 1) * 1;
        tree[node].prop += 1;
        return;
    }
    int left = node * 2 + 1;
    int right = node * 2 + 2;
    int mid = (b + e) / 2;

    update(left, b, mid, i, j);
    update(right, mid + 1, e, i, j);

    tree[node].sum = tree[left].sum + tree[right].sum;
}
int32_t main()
{

}
