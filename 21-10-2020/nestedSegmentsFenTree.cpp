#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
const int maxN = 1e6 + 5;
const int maxD = 1e9 + 1;

// w[i] = v -> i: end point (left or right) of the segment, v: its position in all end points sorted in ascending order
// h is a map used to support the creation of w. A set would have been ok as well
map<int, int> h, w;
vector<int> indexRightEndSeg[maxN];
vector<int> fenwickTree(maxN);
vector<int> ans(maxN);

void addInFenwickTree(int k)
{
    while(k >= 1)
    {
        fenwickTree[k]++;
        k -= k & -k;
    }

}

int sumRangeFenwickTree(int k, int n)
{
    int sum = 0;
    while(k < maxN)
    {
        sum += fenwickTree[k];
        k += k & -k;
    }
    return sum;
}

/*
    Solution: 
        The corresponding segment of the first right end between all right ends does not contain any other segments inside,
        so we do +1 from the order of its left end (we cannot do directly the left end because it could be negative)
        to the left in the Fenwick Tree and we store the answer.

        We do the same to all other segments ordered by the appearance of their right end.
*/


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    scanf("%d", &n);
    
    vector<pairIntInt> seg(n+1);

    for(int i = 1; i <= n; i++)
    {
        scanf("%d %d", &seg[i].first, &seg[i].second);
        h[seg[i].first] = 1, h[seg[i].second] = 1;
    }

    int s = 1;
    for(map<int, int>::iterator it = h.begin(); it != h.end(); it++)
    {
        w[it->first] = s;
        s++;
    }


    // indexRightEndSeg[k] = (a, b, c) ->
    //     k = order of right end of segments (a, b, c) in all ends sorted in ascending order,
    //     (a, b, c) -> the indexes of segments in the input sequence
    for(int i = 1; i <= n; i++)
    {
        indexRightEndSeg[ w[ seg[i].second ] ].push_back(i);
    }

    
    for(int i = 1; i <= s; i++)
    {
        // does +1 of fenT [ order of left end of each segment  ] from the segment of the first right end onwards
        for(auto index: indexRightEndSeg[i]) addInFenwickTree( w [ seg[index].first ] );

        for(auto index: indexRightEndSeg[i]) ans[index] = sumRangeFenwickTree( w [ seg[index].first ], n);
    }

    for(int i = 1; i <= n; i++)
    {
        printf("%d\n", --ans[i]);
    }
    

    return 0;
}
