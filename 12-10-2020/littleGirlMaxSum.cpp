#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
const int maxN = 2e5 + 1;
const int maxD = 1e9 + 1;

int occ[maxN]; // occ[i] - How many times the index i has been comprehended in the indexes of the queries

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n, q;
    scanf("%d %d", &n, &q);

    vector<int> array(n+1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
    }

    while(q--)
    {
        int l, r;
        scanf("%d %d", &l, &r);

        occ[l] += 1;
        occ[r+1] -= 1;
    }
    
    occ[0] = 0, occ[n+1] = 0;
    for(int i = 1; i <= n; i++)
    {
        occ[i] += occ[i-1];
    }
    // This technique allows the avoidance of the iteration from l to r in each query to compute occ[i]


    sort(occ + 1, occ + n + 1, greater<int>());
    sort(array.begin() + 1, array.end(), greater<int>());


    // Compute ans by doing the sum of the multiplications of
    //      the biggest value besides the ones already processed with
    //      the most occurring index besides the ones already processed
    int i = 1;
    ll ans = 0;
    while(occ[i] != 0)
    {
        ans += (ll) occ[i] * array[i];
        i++;
    }

    printf("%lld\n", ans);

    return 0;
}
