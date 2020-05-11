#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef pair<string, string> pss;
typedef vector<pll> vpll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vstr;
typedef unordered_map<ll, vll> um;
typedef unordered_set<ll> us;

#define fastio                   \
    ios::sync_with_stdio(false); \
    cin.tie(NULL);               \
    cout.tie(NULL);
#define endl '\n'
#define ln cout << endl;
#define input(x) cin >> x;
#define print(x) cout << x << endl;
#define reset(a, b) memset(a, b, sizeof(a))
#define FOR(i, a, b) for (ll i = a; i < b; i++)
#define FORI(i, a, b, c) for (ll i = a; i < b; i += c)
#define FORD(i, a, b, c) for (ll i = a; i > b; i -= c)
#define FOREACH(it, v) for (typeof(v.begin()) it = v.begin(); it != v.end(); it++)
#define FORALL(it, v) for (auto it : v)
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()
#define allr(arr, r) arr, arr + r
#define showv(v)           \
    for (auto it : v)      \
        cout << it << ' '; \
    ln;
#define show2d(v)             \
    for (auto it : v)         \
    {                         \
        for (auto j : it)     \
            cout << j << ' '; \
        ln;                   \
    }
#define printv(v)     \
    for (auto it : v) \
        cout << it << endl;
#define sortv(v) sort(all(v));
#define revv(v) reverse(all(v));
#define maxv(v) *max_element(all(v))
#define minv(v) *min_element(all(v))
#define gcd __gcd
#define checkbit(n, i) (n >> i & 1)              // check ith bit
#define bitcount __builtin_popcount              // count set bits
#define firstbitindex __builtin_ctz              // count trailing zeros
#define lastbitindex __builtin_clz               // count leading zeros
#define bitparity __builtin_parity               // check set bits are even or odd
#define findv(v, x) (find(all(v), x) != v.end()) // find in a vector
#define findsm(u, x) (u.find(x) != u.end())      // find in a set / map
#define finds(s, x) (s.find(x) != string::npos)  // find in a string
#define sz(a) a.size()
#define precise(x) cout << fixed << setprecision(x);
#define N 100000

const ll MAXN = 1e+2 + 7, MOD = 1e+9 + 7, INF = 0x7f7f7f7f7f7f7f7f;
const int INFi = 0x7f7f7f7f;
const double EPS = 1e-9, PI = acos(-1);

//<<------Declare Variables Here----->>//
ll t, n, m, x, y, i, j, k, ans;
vll p;
map<ll, ll> q, g;
map<ll, vll> d, r;
vvll f, v;
set<ll> temp;

//<<-----Implement Functions Here---->>//
bool check()
{
    FORALL(it, r)
    {
        if (!it.S.empty())
        {
            i = it.F;
            return true;
        }
    }
    return false;
}

ll findpos(ll z)
{
    if (z == q[z])
        return z;
    return findpos(q[z]);
}

ll solve()
{
    input(n >> m)
    p = vll(n);
    FOR(i, 0, n)
        input(p[i])
    q = {};
    FOR(i, 1, n + 1)
        q[i] = i;
    FOR(i, 0, m)
    {
        input(x >> y)
        x = findpos(x);
        y = findpos(y);
        if (x != y)
            q[y] = x;
    }
    d = {};
    FOR(i, 1, n + 1)
        d[findpos(i)].pb(i);
    f = v = {};
    FORALL(it, d)
    {
        temp = {};
        if (sz(it.S))
        {
            f.pb(it.S);
            FORALL(jt, it.S)
                temp.insert(p[jt - 1]);
            v.pb(vll(all(temp)));
        }
    }
    g = {};
    FOR(i, 0, sz(f))
        FORALL(jt, f[i])
            g[jt] = i + 1;
    r = {};
    FOR(i, 0, sz(v))
        FORALL(jt, v[i])
            if (g[jt] != i + 1)
                r[i + 1].pb(g[jt]);
    ans = 0;
    if (sz(r))
    {
        while (check())
        {
            j = r[i][0];
            r[i].erase(r[i].begin());
            while (i != j)
            {
                k = j;
                j = r[j][0];
                r[k].erase(r[k].begin());
                ans++;
            }
        }
    }
    return ans;
}

//<<----------Start of Main---------->>//
int main()
{
    fastio
    input(t) while (t--)
        print(solve());
    return 0;
}