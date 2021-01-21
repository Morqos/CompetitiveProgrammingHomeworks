#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pairIntInt;
typedef pair<ll, ll> pairLL;
 
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int maxN = 1e6 + 5;

string s;

/*
    nAlt = size of alternative (contiguous or not) subsequence of the initial sequence 's'

    ans = 
        the same as nAlt
            (if nAlt == n)

    or
        nAlt + 1
            (if s is composed by [contiguous, alternative] or the reverse, ex: 00010101)
    
    or
        nAlt + 2
            (if s is composed with (contiguous > 2) or
                (contiguous == 2 and there's an alternative sequence
                that doesn't start/end at the beginning/end of 's')
*/

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    scanf("%d", &n);

    cin >> s;

    string tmpS;
    tmpS.assign(s, 0, 1);

    int nAlt = 1;
    for(int i = 1; i < n; i++)
    {
        if(s[i] != tmpS[0])
        {
            nAlt++;
            tmpS[0] = s[i];
        }
    }

    int nBiggestCont = 1; int nTmpCont = 1;
    tmpS[0] = s[0];
    for(int i = 1; i < n; i++)
    {
        if(s[i] == tmpS[0])
        {
            nTmpCont++;
            if(nTmpCont > nBiggestCont) nBiggestCont = nTmpCont;
        }
        else
        {
            tmpS[0] = s[i];

            nTmpCont = 1;
        }
    }


    if(nBiggestCont > 2) nAlt += 2;
    else
    {
        if(nBiggestCont > 1)
        {
            if(n - nBiggestCont == nAlt - 1) nAlt += 1;
            else nAlt += 2;
        }
    }
    cout << nAlt << endl;
    


    return 0;
}
