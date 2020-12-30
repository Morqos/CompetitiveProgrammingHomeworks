#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
 
const int maxN = 2e5 + 1;
const int maxD = 1e9 + 1;
const int maxA = 1e6 + 1;

vector<int> howMany(maxA, 0); // howMany[i] = #times value i appears in current segment
 
set<pairIntInt> segment; // first = value; second = #times value appears in current segment

// Function used to debug
void print()
{
    set<pairIntInt>::iterator itr;
    for (itr = segment.begin(); itr != segment.end(); ++itr) 
    {
        printf("f: %d, s: %d\n", itr->first, itr->second);
    }
    printf("\n");
}

// Return:
//      1 if value removed from set "segment",
//      0 if value not removed from set "segment"
int tryUpdate(int value, int updateV)
{
    set<pairIntInt>::iterator it;
    it = segment.lower_bound(make_pair(value, -1));

    assert(it != segment.end());

    int secondValue = it->second + updateV;
    howMany[value] = secondValue;

    segment.erase(it);

    if(secondValue > 0)
    {
        segment.insert(make_pair(value, secondValue));
        return 0;        
    }
    else return 1;
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
 
    int n, k;
    scanf("%d %d", &n, &k);
 
    vector<int> array(n+1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d", &array[i]);
    }

    int pLeft = 1, pRight = 1;
    int ansLeft = 1, ansRight = 1, nDiff = 1;

    segment.insert(make_pair(array[1], 1));
    howMany[array[1]] = 1;

    // 'Two Pointers" Technique
    for(int i = 1; i < n; i++)
    {
        if(nDiff < k && segment.find(make_pair(array[i+1], howMany[array[i+1]])) == segment.end())
        {
            nDiff++;
            segment.insert(make_pair(array[i+1], 1));
            howMany[array[i+1]] = 1;
            pRight = i+1;
        }
        else if(nDiff < k && segment.find(make_pair(array[i+1], howMany[array[i+1]])) != segment.end())
        {
            pRight = i+1;
            tryUpdate(array[i+1], 1);
        }
        else if(nDiff == k && segment.find(make_pair(array[i+1], howMany[array[i+1]])) == segment.end())
        {
            int res = 0;
            do
            {
                res = tryUpdate(array[pLeft], -1);
                pLeft++;
            } while(!res && pLeft <= pRight);

            pRight = i+1;
            segment.insert(make_pair(array[i+1], 1));
            howMany[array[i+1]] = 1;
        }
        else if(nDiff == k && segment.find(make_pair(array[i+1], howMany[array[i+1]])) != segment.end())
        {
            pRight = i+1;
            tryUpdate(array[i+1], 1);
        }



        if(pRight - pLeft > ansRight - ansLeft)
        {
            ansLeft = pLeft;
            ansRight = pRight;
        }
        // printf("pLeft: %d, pRight: %d\n", pLeft, pRight);
        // print();
    }
 
 
    printf("%d %d\n", ansLeft, ansRight);
   
    return 0;
}
