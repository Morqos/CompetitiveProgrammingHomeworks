#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
const int maxN = 5e5 + 1;
const int maxD = 1e9 + 1;

int cnt[maxN];
 
int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    scanf("%d", &n);

    vector<int> array(n+1);
    ll totalSum = 0;
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
        totalSum += array[i];
    }

    // If the total sum is not evenly divisble by 3 we cannot have 3 equal numbers which sum is equal to the total sum
    if(totalSum % 3 != 0) printf("0\n"), exit(EXIT_SUCCESS);
    

    ll thirdSum = totalSum / 3;
    ll tmpSum = 0;
    for(int i = n; i >= 1; --i)
    {
        tmpSum += array[i];
        if (tmpSum == thirdSum) cnt[i] = 1;
    }
    // Here, cnt[i] == 1 iff array[n] + array[n-1] + ... + array[i] = 1/3 of the total sum

    for(int i = n-1; i >= 1; --i) cnt[i] += cnt[i+1];
    // Here, cnt[] has become the prefixSum array of the previous cnt[]


    // Count ans as for each i, how many j do I have such that the condition is satisfied?
    ll ans = 0;
    tmpSum = 0;
    for(int i = 1; i <= n-2; i++)
    {
        tmpSum += array[i];
        if(tmpSum == thirdSum) ans += cnt[i+2];
    }

    printf("%lld\n", ans);

    return 0;
}
