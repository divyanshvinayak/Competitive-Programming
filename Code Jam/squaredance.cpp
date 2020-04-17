#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<char> vchar;
typedef vector<vll> vvll;
typedef map<char, ll> um;
typedef unordered_set<ll> us;

#define fastio ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
#define ln cout<<endl;
#define input(x) cin>>x;
#define print(x) cout<<x<<endl;
#define reset(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for(ll i = a; i < b; i++)
#define FORI(i, a, b, c) for(ll i = a; i < b; i += c)
#define FORD(i, a, b) for(ll i = a; i > b; i--)
#define FOREACH(it, v) for(auto it = v.begin();  it != v.end(); it++)
#define FORALL(it, v) for(auto it: v)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(arr, r) arr, arr + r
#define showv(v) for(auto it: v) cout<<it<<' '; ln;
#define showm(v) for(auto it: v) cout<<it.F<<','<<it.S<<' '; ln;
#define show2d(v) for(auto it: v) {for(auto j: it) cout<<j<<' '; ln;}
#define printv(v) for(auto it: v) cout<<it<<endl;
#define sortv(v) sort(all(v));
#define revv(v) reverse(all(v));
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define gcd __gcd
#define checkbit(n, i) (n >> i & 1) // check ith bit
#define bitcount __builtin_popcount // count set bits
#define firstbitindex __builtin_ctz // count trailing zeros
#define lastbitindex __builtin_clz // count leading zeros
#define bitparity __builtin_parity // check set bits are even or odd
#define findv(v, x) (find(all(v), x) != v.end()) // find in a vector
#define findsm(u, x) (u.find(x) != u.end()) // find in a set / map
#define findstr(s, x) (s.find(x) != string::npos) // find in a string
#define sz(a) a.size()
#define precise(x) cout<<fixed<<setprecision(x);

const ll MAXN = 1e+2+7, MOD = 998244353, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Variables Here----->>//
ll t, r, c, ans, total, val, cnt;
vvll s, z, lefty, righty, up, down, when;
vpll v, rm;

//<<-----Implement Functions Here---->>//
ll solve()
{
	cin>>r>>c;
	s = lefty = righty = up = down = when = vvll(r+2, vll(c+2));
	v = {}, total = 0;
	FOR(i, 1, r+1)
		FOR(j, 1, c+1)
		{
			cin>>s[i][j];
			total += s[i][j];
			lefty[i][j] = j-1, righty[i][j] = j+1, up[i][j] = i-1, down[i][j] = i+1;
			v.pb({i, j});
		}
	ans = total;
	FOR(i, 1, INF)
	{
		rm = {};
		FORALL(it, v)
		{
			val = 0, cnt = 0;
			if(lefty[it.F][it.S])
				val+=s[it.F][lefty[it.F][it.S]], cnt++;
			if(righty[it.F][it.S]<=c)
				val+=s[it.F][righty[it.F][it.S]], cnt++;
			if(up[it.F][it.S])
				val+=s[up[it.F][it.S]][it.S], cnt++;
			if(down[it.F][it.S]<=r)
				val+=s[down[it.F][it.S]][it.S], cnt++;
			if(s[it.F][it.S]*cnt<val)
				rm.pb(it);
		}
		if(rm.empty())
			break;
		FORALL(it, rm)
			total-=s[it.F][it.S], when[it.F][it.S]=i;
		ans += total, v = {};
		FORALL(it, rm)
		{
			if(lefty[it.F][it.S])
				if(when[it.F][lefty[it.F][it.S]]!=i)
					v.pb({it.F, lefty[it.F][it.S]}), when[it.F][lefty[it.F][it.S]]=i;
			if(righty[it.F][it.S]<=c)
				if(when[it.F][righty[it.F][it.S]]!=i)
					v.pb({it.F, righty[it.F][it.S]}), when[it.F][righty[it.F][it.S]]=i;
			if(up[it.F][it.S])
				if(when[up[it.F][it.S]][it.S]!=i)
					v.pb({up[it.F][it.S], it.S}), when[up[it.F][it.S]][it.S]=i;
			if(down[it.F][it.S]<=r)
				if(when[down[it.F][it.S]][it.S]!=i)
					v.pb({down[it.F][it.S], it.S}), when[down[it.F][it.S]][it.S]=i;
		}
		FORALL(it, rm)
		{
			lefty[it.F][righty[it.F][it.S]]=lefty[it.F][it.S];
			righty[it.F][lefty[it.F][it.S]]=righty[it.F][it.S];
			up[down[it.F][it.S]][it.S]=up[it.F][it.S];
			down[up[it.F][it.S]][it.S]=down[it.F][it.S];
		}
	}
	return ans;
}

//<<----------Start of Main---------->>//
int main()
{
	fastio;
	cin>>t;
	FOR(k, 1, t+1)
		cout<<"Case #"<<k<<": "<<solve()<<endl;
	return 0;
}