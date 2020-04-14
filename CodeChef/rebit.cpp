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
ll t, i, total, ans;
string s;
vll x, y, temp;
vchar operators;
vvll output;
char op;

//<<-----Implement Functions Here---->>//
ll power(ll a, ll b)
{
    ans = 1;
    while(b)
	{
        if(b&1)
			ans = (ans * a) % MOD;
        a = (a * a) % MOD;
        b = b / 2;
    }
    return ans;
}

ll modulo(ll p, ll q, ll m)
{
    return ((power(q, m - 2) % m) * (p % m)) % m;
}

void solve()
{
	cin>>s;
    if(s=="#")
		s="(#^#)";
	output = {}, operators = {};
	i = 0;
	while(i<sz(s))
	{
		if(s[i]!=')')
		{
			if(s[i]=='#')
				output.pb({1, 1, 1, 1});
			else if(s[i]!='(')
				operators.pb(s[i]);
		}
		else
		{
			op = operators.back();
			operators.pop_back();
			x = output.back();
			output.pop_back();
			y = output.back();
			output.pop_back();
			temp = {0, 0, 0, 0};
			if(op == '&')
				FOR(j, 0, 4)
					FOR(k, 0, 4)
						temp[j & k] = (temp[j & k] + x[j] * y[k]) % MOD;
			else if(op == '^')
				FOR(j, 0, 4)
					FOR(k, 0, 4)
						temp[j ^ k] = (temp[j ^ k] + x[j] * y[k]) % MOD;
			else
				FOR(j, 0, 4)
					FOR(k, 0, 4)
						temp[j | k] = (temp[j | k] + x[j] * y[k]) % MOD;
			output.pb(temp);
		}
		i++;
	}
	total = (output[0][0] + output[0][1] + output[0][2] + output[0][3]) % MOD;
	cout<<modulo(output[0][0], total, MOD)<<' '<<modulo(output[0][3], total, MOD)<<' '<<modulo(output[0][1], total, MOD)<<' '<<modulo(output[0][2], total, MOD)<<endl;
	return;
}

//<<----------Start of Main---------->>//
int main()
{
	fastio;
	cin>>t;
	while(t--)
		solve();
	return 0;
}