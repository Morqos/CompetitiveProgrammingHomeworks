#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const ll INF = numeric_limits<ll>::max()/4 ;
 
const int maxN = 1e6 + 5;
const int maxD = 1e9 + 1;

vector<ll> seq(maxN);
vector<pairLL> lazySegTree(2*maxN, make_pair(INF,0));

vector<ll> readInput()
{
    vector<ll> arr; string input; ll num;
    getline(cin, input); istringstream is(input);
    
    while(is>>num) arr.push_back(num);

    return arr;
}



void build(int k, int start, int end)
{
    if(start == end)
    {
        lazySegTree[k].first = seq[start];
    }
    else
    {
        int mid = (start + end) / 2;

        build(2*k, start, mid);
        build(2*k + 1, mid+1, end);

        lazySegTree[k].first = min(lazySegTree[2*k].first, lazySegTree[2*k + 1].first);
    }
}



void updateRange(int k, int start,int end, int l,int r, ll val)
{
    if(lazySegTree[k].second != 0)
    { 
        lazySegTree[k].first += lazySegTree[k].second;
        if(start != end)
        {
            lazySegTree[k*2].second += lazySegTree[k].second;
            lazySegTree[k*2 + 1].second += lazySegTree[k].second;
        }
        lazySegTree[k].second = 0;
    }

    if(start > end || start > r || end < l) // Current segment [start, end] is not fully outside range [l, r]
        return;
    
    if(l <= start && end <= r) // Current segment [start, end] is fully within range [l, r]
    {
        lazySegTree[k].first += val;
        if(start != end)
        {
            lazySegTree[k*2].second += val;
            lazySegTree[k*2 + 1].second += val;
        }
        return;
    }
    
    int mid = (start + end) / 2;
    
    updateRange(k*2, start, mid, l, r, val);
    updateRange(k*2 + 1, mid + 1, end, l, r, val);

    lazySegTree[k].first = min(lazySegTree[k*2].first, lazySegTree[k*2 + 1].first);
}


ll queryRange(int k, int start,int end, int l,int r)
{
    if(start > end || start > r || end < l) // Current segment [start, end] is not fully outside range [l, r]
        return INF;
    
    if(lazySegTree[k].second != 0)
    {
        lazySegTree[k].first += lazySegTree[k].second;
        if(start != end)
        {
            lazySegTree[k*2].second += lazySegTree[k].second;
            lazySegTree[k*2 + 1].second += lazySegTree[k].second;
        }

        lazySegTree[k].second = 0;
    }
    
    if(start >= l and end <= r) // Current segment is fully within range [l, r]
        return lazySegTree[k].first;
    
    int mid = (start + end) / 2;
    ll val1 = queryRange(k*2, start, mid, l, r);
    ll val2 = queryRange(k*2 + 1, mid + 1, end, l, r);

    return min(val1, val2);
}


int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){ scanf("%I64d", &seq[i]); }

    build(1, 0, n-1);


    int m;
    scanf("%d\n", &m);

    // In each type of query, if indexes range (a, b) are a > b and so the range becomes [a, a+1, a+2, .., n-1, 0, 1, 2, .., b],
    // we split in 2 queries:
    //      1) (a, n-1)
    //      2) (0, b)
    while(m--)
    {
        vector<ll> arr = readInput();

        if(arr.size() == 3) // inc operation
        {
            if(arr[1] >= arr[0])
            {
                updateRange(1, 0, n-1, arr[0],arr[1], arr[2]);
            }
            else
            {
                updateRange(1, 0,n-1, arr[0],n-1, arr[2]);
                updateRange(1, 0,n-1, 0,arr[1], arr[2]);
            }
        }
        else // min value in segment
        {
            if(arr[1] >= arr[0])
            {
                ll val = queryRange(1, 0,n-1, arr[0],arr[1]);
                printf("%I64d\n", val);
            }   
            else
            {
                ll val1 = queryRange(1, 0,n-1, arr[0],n-1);
                ll val2 = queryRange(1, 0,n-1, 0,arr[1]);
                printf("%I64d\n", min(val1, val2));
            }
        }
    }



    return 0;
}
