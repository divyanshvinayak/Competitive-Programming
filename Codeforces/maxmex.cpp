/*
Created on Fri Jan 24 12:00:00 2020
@author: divyanshvinayak
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef unordered_map<ll,ll> um;
typedef unordered_set<ll> us;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define sqr(x) ((ll)(x) * (x))
#define reset(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b, c) for(ll i = a; i < b; i += c)
#define FORD(i, a, b, c) for(ll i = a; i > b; i -= c)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(arr, r) arr, arr + r
#define showv(v) for(auto it: (v)) cout<<it<<' '; cout<<'\n';
#define show2d(v) for(auto it: (v)) {for(auto j:it) cout<<j<<' '; cout<<'\n';}
#define printv(v) for(auto it: (v)) {cout<<it<<'\n';}
#define N 100000

const ll MAXN = 1e+2+7;
const ll MOD = 1e+9+7, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const double EPS = 1e-9;
const double PI = acos(-1);

//<<------Declare Variables Here----->>//
ll t, x, z, n = 0, m = 0, k = 0;
vll mex;
um a;
 
//<<-----Implement Functions Here---->>//
 
//<<----------Start of Main---------->>//
int main()
{
	fastio;
    cin>>t>>x;
	FOR(i, 0, t, 1)
	{
	    cin>>z;
	    z = (z - n) % x + n;
	    while(true)
	    {
	       if(a[z])
	           z += x;
	       else
	       {
	           a[z] = 1;
	           break;
	       }
	    }
	    if(z > m)
            m = z;
	    if(z == n)
	    {
	        k = n + 1;
	        while(k <= m + 1)
	        {
	            if(a[k])
	                k += 1;
	            else
	            {
	                n = k;
	                break;
	            }
	        }
	    }
	    mex.pb(n);
	}
	printv(mex);
}