#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
const int maxN = 1e6 + 5;
const int maxD = 1e9 + 1;

map<int, int> mapSxToDx;
map<int, int> mapDxToSx;
vector<int> fenTree(maxN);

void addInFenwickTree(int k, int val, int n)
{
    while(k <= n)
    {
        fenTree[k] += val;
        k += k & -k;
    }

}

int sumRangeFenwickTree(int k)
{
    int sum = 0;
    while(k >= 1)
    {
        sum += fenTree[k];
        k -= k & -k;
    }
    return sum;
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<int> seq(n+1);
    vector<int> sxToDx(n+1);
    vector<int> dxToSx(n+1);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &seq[i]);
    }
    
    // fill sxToDx
    for(int i = 1; i <= n; i++)
    {
        mapSxToDx[seq[i]]++;
        sxToDx[i] = mapSxToDx[seq[i]];
    }

    // fill dxToSx
    for(int i = n; i >= 1; i--)
    {
        mapDxToSx[seq[i]]++;
        dxToSx[i] = mapDxToSx[seq[i]];
    }


    for(int i = 1; i <= n; i++)
    {
        addInFenwickTree(dxToSx[i], 1, n+1);
    }

    ll ans = 0;
    for(int i = 1; i <= n; i++)
    {
        addInFenwickTree(dxToSx[i], -1, n+1);

        ans += sumRangeFenwickTree(sxToDx[i] - 1);
    }

    printf("%I64d\n", ans);

    return 0;
}
