#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;


//...................................................................//
#define endl                '\n'
#define Int                 long long int
#define gcd(x, y)           (__gcd(x, y))
#define lcm(x, y)           ((x/gcd(x, y))*y)
#define rand(x, y)          rand()%(y-x+1)+x
#define pow2(x)             (1<<x)
#define pi                  3.141592653589793
#define decimal(x)          fixed<<setprecision(x)
#define unsync              ios_base::sync_with_stdio(0); cin.tie(0);
//...................................................................//


int parent[N];
int Size[N];

void make(int v)
{
    parent[v] = v;
    Size[v] = 1;
}

int Find(int v)
{
    if(v==parent[v])
        return v;

    return parent[v] = Find(parent[v]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);

    if(a!=b)
    {
        if(Size[a]<Size[b])
            swap(a, b);

        parent[b] = a;
        Size[a] += Size[b];
    }
}

int main()
{
    //srand(time(0));
    //unsync


    make(1);
    make(2);
    make(3);
    make(4);
    make(5);
    make(6);
    Union(1, 2);
    Union(1, 3);
    Union(4, 5);
    Union(4, 6);
    Union(3, 6);
    cout << parent[1] << " " << parent[2] << " " << parent[3] << endl;
    cout << parent[6] << " " << parent[3] << " " << parent[4] <<  endl;
}
