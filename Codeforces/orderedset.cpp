#include <bits/stdc++.h>
using namespace std;
 
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vll> vvll;
typedef vector<vpll> vvpll;
typedef unordered_map<ll, ll> um;
typedef unordered_set<ll> us;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define ts \
    ll t;  \
    in(t) while (t--) solve();
#define endl '\n'
#define ln cout << endl;
#define in(x) cin >> x;
#define out(x) cout << x << endl;
#define flush cout << flush;
#define reset(a, b) memset(a, b, sizeof(a));
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FORI(i, a, b, c) for (ll i = a; i < b; i += c)
#define FORD(i, a, b) for (ll i = a; i > b; i--)
#define FOREACH(it, v, r) for (auto it = v.begin() + r; it != v.end(); it++)
#define FORALL(it, v) for (auto it : v)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define vin(v, x) \
    vll v(x);     \
    FOR(i, 0, x)  \
    in(v[i])
#define all(v) v.begin(), v.end()
#define allr(v, r) v.begin(), v.begin() + r
#define showv(v)           \
    for (auto it : v)      \
        cout << it << ' '; \
    ln
#define showm(v)                            \
    for (auto it : v)                       \
        cout << it.F << ':' << it.S << ' '; \
    ln
#define show2d(v)             \
    for (auto it : v)         \
    {                         \
        for (auto j : it)     \
            cout << j << ' '; \
        ln                    \
    }
#define printv(v)     \
    for (auto it : v) \
        out(it)
#define showvm(v)             \
    for (auto it : v)         \
    {                         \
        for (auto j : it)     \
            cout << j << ' '; \
        ln                    \
    }
#define sortv(v) sort(all(v));
#define revv(v) reverse(all(v));
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define gcd __gcd
#define checkbit(n, i) (n >> i) & 1               // check ith bit
#define bitcount __builtin_popcount               // count set bits
#define firstbitindex __builtin_ctz               // count trailing zeros
#define lastbitindex __builtin_clz                // count leading zeros
#define bitparity __builtin_parity                // check set bits are even or odd
#define findv(v, x) (find(all(v), x) != v.end())  // find in a vector
#define findsm(u, x) (u.find(x) != u.end())       // find in a set / map
#define findstr(s, x) (s.find(x) != string::npos) // find in a string
#define sz(a) a.size()
#define precise(x) cout << fixed << setprecision(x);

const ll MAXN = 1e6 + 5, MOD = 1e9 + 7, SIZE = 1e6 + 5;
const double EPS = 1e-9, PI = acos(-1);
const int INFi = 0x7f7f7f7f;

//<<------Declare Variables Here----->>//
ll n, q, x, y;
ordered_set s;
 
//<<-----Implement Functions Here---->>//
void solve()
{
    in(n >> q)
    FOR(i, 0, n)
    {
        in(x)
        s.insert(x);
    }
    FOR(i, 0, q)
    {
        in(x)
        if(x < 0)
            s.erase(s.find_by_order(-x-1));
        else
            s.insert(x);
    }
    if(sz(s))
        out(*s.find_by_order(0))
    else
        out(0)
}
 
//<<----------Start of Main---------->>//
int main()
{
    fastio
    solve();
    return 0;
}